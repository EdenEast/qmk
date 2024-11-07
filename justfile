# colors
reset  := '\033[0m'
red    := '\033[1;31m'
green  := '\033[1;32m'
yellow := '\033[1;33m'
blue   := '\033[1;34m'

alias b := build
alias f := flash
alias l := layout
alias w := watch-layout

list:
    @just --list

# Build all keyboards
all command='build':
    @just {{command}} dm4
    @just {{command}} dm5
    @just {{command}} arc
    @just {{command}} crkbd
    @just {{command}} tofu

# Build keyboard firmware
build keyboard map='edeneast' opts='':
    #!/usr/bin/env bash
    printf "{{yellow}}--------------------------------------------------------------------------------------{{reset}}\n"
    printf "Buildling: {{blue}}{{keyboard}}{{reset}} | {{red}}{{map}}{{reset}}\n\n"
    just _qmk_command compile $(just _keyboard {{keyboard}}) {{map}} {{opts}}

# Flash keyboard firmware
flash keyboard map='edeneast' opts='':
    #!/usr/bin/env bash
    printf "{{yellow}}--------------------------------------------------------------------------------------{{reset}}\n"
    printf "Flashing: {{blue}}{{keyboard}}{{reset}} | {{red}}{{map}}{{reset}}\n\n"
    just _qmk_command flash {{keyboard}} {{map}} {{opts}}

# Flash left hand of `keyboard`
left keyboard map='edeneast':
    #!/usr/bin/env bash
    printf "{{yellow}}--------------------------------------------------------------------------------------{{reset}}\n"
    printf "Setting left hand: {{blue}}{{keyboard}}{{reset}} | {{red}}{{map}}{{reset}}\n\n"
    just _qmk_command flash $(just _keyboard {{keyboard}}) {{map}} "-bl $(just _loader {{keyboard}})-split-left"

# Flash right hand of `keyboard`
right keyboard map='edeneast':
    #!/usr/bin/env bash
    printf "{{yellow}}--------------------------------------------------------------------------------------{{reset}}\n"
    printf "Setting right hand: {{blue}}{{keyboard}}{{reset}} | {{red}}{{map}}{{reset}}\n\n"
    just _qmk_command flash $(just _keyboard {{keyboard}}) {{map}} "-bl $(just _loader {{keyboard}})-split-right"

_keyboard keyboard:
  #!/usr/bin/env bash
  if [ "{{keyboard}}" = "crkbd" ]; then
    echo "crkbd"
  elif [ "{{keyboard}}" = "arc" ]; then
    echo "handwired/arc"
  elif [ "{{keyboard}}" = "dm4" ]; then
    echo "handwired/dactyl_manuform/4x6"
  elif [ "{{keyboard}}" = "dm5" ]; then
    echo "handwired/dactyl_manuform/5x6"
  elif [ "{{keyboard}}" = "tofu" ]; then
    echo "dztech/dz60v2/tofu"
  else
    printf "{{red}}Failed: Unknown keyboard: {{keyboard}}{{reset}}\n"
  fi

_loader keyboard:
  #!/usr/bin/env bash
  if [ "{{keyboard}}" = "crkbd" ]; then
    echo "dfu"
  else
    echo "avrdude"
  fi

_qmk_command command keyboard map='edeneast' opts='': init
    @qmk {{command}} -j0 -kb {{keyboard}} -km {{map}} {{opts}}

# Setup submodule and link directories to submodules
init:
    #!/usr/bin/env bash
    git submodule update --init --recursive --recommend-shallow
    stow -R -d {{justfile_directory()}}/qmk -t {{justfile_directory()}}/firmware .
    if [ "$(git config submodule.firmware.ignore)" != "all" ]; then
      git config submodule.firmware.ignore all
    fi
    if [ "$(qmk config user.qmk_home | cut -d '=' -f 2)" != "{{justfile_directory()}}/firmware" ]; then
      qmk config user.qmk_home="{{justfile_directory()}}/firmware"
    fi

# Symbolic link qmk directory into firmware
stow:
  stow -R -d {{justfile_directory()}}/qmk -t {{justfile_directory()}}/firmware .

# Format c files
fmt:
    clang-format -i $(fd --exclude firmware --exclude qmk/users/edeneast/features --extension c --extension h .)

# Generate layout map
layout:
    keymap --config ./resources/km-drawer-config.yml draw ./resources/arc-layout.yml > ./resources/arc-layout.svg
    keymap --config ./resources/km-drawer-config.yml draw ./resources/tofu-layout.yml > ./resources/tofu-layout.svg

# live reload layout map
[linux]
@watch-layout:
    #!/usr/bin/env bash
    [[ $(uname -r) =~ microsoft ]] && powershell.exe start $(wslpath ./resources/arc-layout.svg) || xdg-open ./resources/arc-layout.svg
    [[ $(uname -r) =~ microsoft ]] && powershell.exe start $(wslpath ./resources/tofu-layout.svg) || xdg-open ./resources/tofu-layout.svg
    watchexec -nrpw resources e yml -- just layout

# live reload layout map
[macos]
@watch-layout:
    #!/usr/bin/env bash
    open ./resources/arc-layout.svg
    open ./resources/tofu-layout.svg
    watchexec -nrpw resources -e yml -- just layout

# Update qmk submodule
qmk-update:
    #!/usr/bin/env bash
    # https://stackoverflow.com/a/41081908
    pushd ./firmware
    git reset --hard
    git clean -fdx
    git co master
    git fetch origin --depth 1
    git reset --hard origin/master
    git submodule update --init --recursive --recommend-shallow
    popd
    git add -f ./firmware
    just init

# Update features subtree
subtree-update:
    #!/usr/bin/env bash
    # https://stackoverflow.com/questions/22334382/git-subtree-only-one-file-or-directory
    # https://gist.github.com/tswaters/542ba147a07904b1f3f5
    # https://getreuer.info/posts/keyboards/achordion/index.html
    [[ $(git diff --name-only --diff-filter=M | wc -l) > 0 ]] && echo 'There are uncommited changes, aborting' && exit 1
    git fetch --depth=1 https://github.com/getreuer/qmk-keymap main:subtree-main
    git checkout subtree-main
    git subtree split --prefix=features -b subtree-split
    git checkout -
    git subtree merge --squash --prefix=qmk/users/edeneast/features subtree-split
    git branch -D subtree-main subtree-split
