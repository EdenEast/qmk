
# colors
reset := '\033[0m'
red   := '\033[1;31m'
green := '\033[1;32m'

build: init
    #!/usr/bin/env bash
    (
        cd external/qmk_firmware
        make handwired/dactyl_manuform/5x6:eden && {
            BUILT=1
            mkdir -p ../../result
            echo ""
            echo "Result:"
            for f in $(fd -e bin -e hex -d 1 -I); do
                printf "  {{green}}$f{{reset}}\n"
                mv -f $f ../../result/
            done

            if [ ! -z "$POST_BUILD" ] ; then
                echo "executing postbuild: $POST_BUILD"
                $POST_BUILD
            fi
        }
    )
    if [ ! -z "BUILT" ] && [ ! -z "$POST_BUILD" ] ; then
        echo "executing postbuild: $POST_BUILD"
        $POST_BUILD
    fi

@init:
    git submodule update --init --recursive
    ln -sf $(pwd)/dact/ ./external/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/eden

