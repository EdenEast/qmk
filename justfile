# colors
reset  := '\033[0m'
red    := '\033[1;31m'
green  := '\033[1;32m'
yellow := '\033[1;33m'
blue   := '\033[1;34m'

user_symlink  := "./external/qmk_firmware/users/edeneast"
dm4_symlink  := "./external/qmk_firmware/keyboards/handwired/dactyl_manuform/4x6/keymaps/edeneast"
dm5_symlink  := "./external/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/edeneast"
crkbd_symlink := "./external/qmk_firmware/keyboards/crkbd/keymaps/edeneast"

default:
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
        cd external/qmk_firmware
        make {{make_cmd}}
    )
    mv ./external/qmk_firmware/{{source}} ./result/{{target}}.hex
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
        cd external/qmk_firmware
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
        cd external/qmk_firmware
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
        cd external/qmk_firmware
        make $cmd
    )

# Setup submodule and link directories to submodules
init:
    #!/usr/bin/env bash
    git config submodule.external/qmk_firmware.ignore all
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

# Re-initialize symlinks
reinit:
    #!/usr/bin/env bash
    rm -rf {{user_symlink}}
    rm -rf {{dm4_symlink}}
    rm -rf {{dm5_symlink}}
    rm -rf {{crkbd_symlink}}
    just init

fmt:
    clang-format -i $(fd --exclude external --extension c --extension h .)

# Update qmk_firmware
qmk-update:
    #!/usr/bin/env bash
    # https://stackoverflow.com/a/41081908
    pushd ./external/qmk_firmware
    git reset --hard
    git clean -fdx
    git checkout master
    git fetch origin --depth 1
    git reset --hard origin/master
    git submodule update --init --recursive --recommend-shallow
    popd
    git add -f ./external/qmk_firmware
    cp -f ./external/qmk_firmware/keyboards/handwired/dactyl_manuform/readme.md ./keyboard/dm/readme.md
    cp -f ./external/qmk_firmware/keyboards/crkbd/readme.md ./keyboard/crkbd/readme.md

# Update nix development environment
nix-update:
    #!/usr/bin/env bash
    mkdir -p ./util/
    rm -rf ./util/nix
    cp -f ./external/qmk_firmware/shell.nix ./shell.nix
    cp -fr ./external/qmk_firmware/util/nix/ ./util/
    sed -i '$ d' shell.nix
    echo "  nativeBuildInputs = [ fd just ];" >> ./shell.nix
    echo "}" >> ./shell.nix
