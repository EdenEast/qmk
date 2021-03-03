#!/bin/bash

set -e

SN="ednkbd"

if tmux has-session -t=${SN} 2> /dev/null; then
    tmux attach -t $SN
    exit
fi

tmux new-session -d -s $SN -n dact -x "$(tput cols)" -y "$(tput lines)"
tmux split-window -t $SN:dact -hp 30

tmux send-keys -t $SN:dact.left "nvim -c Files!" Enter
tmux send-keys -t $SN:dact.right "git status" Enter

tmux attach -t $SN:dact.right
