# colors
reset  := '\033[0m'
red    := '\033[1;31m'
green  := '\033[1;32m'
yellow := '\033[1;33m'
blue   := '\033[1;34m'

user_symlink  := "./firmware/users/edeneast"
dm4_symlink  := "./firmware/keyboards/handwired/dactyl_manuform/4x6/keymaps/edeneast"
dm5_symlink  := "./firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/edeneast"
crkbd_symlink := "./firmware/keyboards/crkbd/keymaps/edeneast"

alias f := flash
alias l := layout
alias w := watch-layout

# Build all keyboards
all:
    @just dm4
    @just dm5
    @just crkbd

# Build dactyl manuform 4x6 keyboard firmware
dm4:
    @just _build handwired/dactyl_manuform/4x6:edeneast handwired_dactyl_manuform_4x6_edeneast.hex dm4

# Build dactyl manuform 5x6 keyboard firmware
dm5:
    @just _build handwired/dactyl_manuform/5x6:edeneast handwired_dactyl_manuform_5x6_edeneast.hex dm5

# Build Corne keyboard (crkbd) firmware
crkbd:
    @just _build crkbd:edeneast crkbd_rev1_edeneast.hex crkbd

_build make_cmd source target: init
    #!/usr/bin/env bash
    printf "{{yellow}}--------------------------------------------------------------------------------------{{reset}}\n"
    printf "Buildling: {{blue}}{{source}}{{reset}}\n\n"
    mkdir -p result
    (
        cd firmware
        make {{make_cmd}}
    )
    mv ./firmware/{{source}} ./result/{{target}}.hex
    printf "Result: {{green}}{{target}}.hex{{reset}}\n"
    if [ ! -z "$POST_BUILD" ]; then
        echo "executing postbuild: $POST_BUILD"
        $POST_BUILD
    fi

# Flash `keyboard`
flash keyboard:
    #!/usr/bin/env bash
    if [ "{{keyboard}}" = "crkbd" ]; then
        cmd="crkbd:edeneast:dfu"
    elif [ "{{keyboard}}" = "dm4" ]; then
        cmd="handwired/dactyl_manuform/4x6:edeneast:avrdude"
    elif [ "{{keyboard}}" = "dm5" ]; then
        cmd="handwired/dactyl_manuform/5x6:edeneast:avrdude"
    else
        printf "{{red}}Failed: Unknown keyboard: {{keyboard}}{{reset}}\n"
    fi
    (
        cd firmware
        make $cmd
    )

# Flash left hand of `keyboard`
left keyboard:
    #!/usr/bin/env bash
    if [ "{{keyboard}}" = "crkbd" ]; then
        cmd="crkbd:edeneast:dfu-split-left"
    elif [ "{{keyboard}}" = "dm4" ]; then
        cmd="handwired/dactyl_manuform/4x6:edeneast:avrdude-split-left"
    elif [ "{{keyboard}}" = "dm5" ]; then
        cmd="handwired/dactyl_manuform/5x6:edeneast:avrdude-split-left"
    else
        printf "{{red}}Failed: Unknown keyboard: {{keyboard}}{{reset}}\n"
        exit
    fi
    (
        cd firmware
        make $cmd
    )

# Flash right hand of `keyboard`
right keyboard:
    #!/usr/bin/env bash
    if [ "{{keyboard}}" = "crkbd" ]; then
        cmd="crkbd:edeneast:dfu-split-right"
    elif [ "{{keyboard}}" = "dm4" ]; then
        cmd="handwired/dactyl_manuform/4x6:edeneast:avrdude-split-right"
    elif [ "{{keyboard}}" = "dm5" ]; then
        cmd="handwired/dactyl_manuform/5x6:edeneast:avrdude-split-right"
    else
        printf "{{red}}Failed: Unknown keyboard: {{keyboard}}{{reset}}\n"
        exit
    fi
    (
        cd firmware
        make $cmd
    )

# Setup submodule and link directories to submodules
init:
    #!/usr/bin/env bash
    git config submodule.firmware.ignore all
    git submodule update --init --recursive --recommend-shallow
    if [ ! -L "{{user_symlink}}" ] ; then
        ln -sf $(pwd)/user {{user_symlink}}
    fi
    if [ ! -L "{{dm4_symlink}}" ] ; then
        ln -sf $(pwd)/keyboard/dm/4x6 {{dm4_symlink}}
    fi
    if [ ! -L "{{dm5_symlink}}" ] ; then
        ln -sf $(pwd)/keyboard/dm/5x6 {{dm5_symlink}}
    fi
    if [ ! -L "{{crkbd_symlink}}" ] ; then
        ln -sf $(pwd)/keyboard/crkbd {{crkbd_symlink}}
    fi
    if [ "$(qmk config user.qmk_home | cut -d '=' -f 2)" != "{{justfile_directory()}}/firmware" ]; then
      qmk config user.qmk_home="{{justfile_directory()}}/firmware"
    fi

# Re-initialize symlinks
reinit:
    #!/usr/bin/env bash
    rm -rf {{user_symlink}}
    rm -rf {{dm4_symlink}}
    rm -rf {{dm5_symlink}}
    rm -rf {{crkbd_symlink}}
    just init

# Format c files
fmt:
    clang-format --style=llvm -i $(fd --exclude firmware --exclude user/features --extension c --extension h .)

# Generate layout map
layout:
    keymap draw ./resources/layout.yml > ./resources/layout.svg

# live reload layout map
[linux]
@watch-layout:
    #!/usr/bin/env bash
    [[ $(uname -r) =~ microsoft ]] && powershell.exe start $(wslpath ./resources/layout.svg) || xdg-open ./resources/layout.svg
    watchexec -nrpw resources/layout.yml -- just layout

# live reload layout map
[macos]
@watch-layout:
    #!/usr/bin/env bash
    open ./resources/layout.svg
    watchexec -nrpw resources/layout.yml -- just layout

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
    git subtree merge --squash --prefix=user/features subtree-split
    git branch -D subtree-main subtree-split
