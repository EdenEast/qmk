# Eden's Keyboard Firmware

This repository contains my personal keymap for my Dactyl Manuform 5x6 keyboard.

This keymap uses [Colemak-DH] for its alpha base with the ability to swap to Qwerty when needed.
It is also heavily inspired/based off of [Miryoku], an ergonomic, minimal, orthogonal layout for
ergo or ortho keyboards.

[Colemak-DH]: https://colemakmods.github.io/mod-dh/
[Miryoku]: https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org

## Quick start

This repository uses [qmk_firmware] as a submodule located in `external/qmk_firmware`. Make sure you
have [Just] installed as this repository is built upon automation of build using just recipes. You
should also use `nix-shell` to make sure you have the correct development environment to build the
firmware. Make sure you update your submodules before trying to execute nix-shell

```bash
# Enter a development shell
nix-shell

# Build the dactyl-manuform layout
just dact

# Or currently
just
```

[qmk_firmware]: https://github.com/qmk/qmk_firmware
[Just]: https://github.com/casey/just

## Resources and References

- [Miryoku]
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap/)
