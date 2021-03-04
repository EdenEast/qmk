
# colors
reset  := '\033[0m'
red    := '\033[1;31m'
green  := '\033[1;32m'
yellow := '\033[1;33m'
blue   := '\033[1;34m'

user_symlink  := "./external/qmk_firmware/users/eden"
dact_symlink  := "./external/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/eden"
crkbd_symlink := "./external/qmk_firmware/keyboards/crkbd/keymaps/eden"

default:
    @just dact
    @just crkbd

dact:
    @just _build handwired/dactyl_manuform/5x6:eden handwired_dactyl_manuform_5x6_eden.hex dact

crkbd:
    @just _build crkbd:eden crkbd_rev1_legacy_eden.hex crkbd

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

init:
    #!/usr/bin/env bash
    git submodule update --init --recursive
    if [ ! -L "{{user_symlink}}" ] ; then
        ln -sf $(pwd)/user {{user_symlink}}
    fi
    if [ ! -L "{{dact_symlink}}" ] ; then
        ln -sf $(pwd)/dact {{dact_symlink}}
    fi
    if [ ! -L "{{crkbd_symlink}}" ] ; then
        ln -sf $(pwd)/crkbd {{crkbd_symlink}}
    fi

