# Eden's Keyboard Firmware

![reference](./resources/ednkbd.png)

This repository contains my personal keymap for my [Dactyl Manuform][dactman-repo] and [Corne] keyboard.

This keymap uses [Colemak-DH] for its alpha base with the ability to swap to Qwerty when needed.
It is also heavily inspired/based off of [Miryoku], an ergonomic, minimal, orthogonal layout for
ergo or ortho keyboards.

[Colemak-DH]: https://colemakmods.github.io/mod-dh/
[Miryoku]: https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org
[dactman-repo]: https://github.com/edeneast/dactyl-manuform
[Corne]: https://github.com/foostan/crkbd

## Quick start

This repository uses [qmk_firmware] as a submodule located in `external/qmk_firmware`. Make sure you
have [Just] installed as this repository is built upon automation of build using just recipes. You
should also use `nix-shell` to make sure you have the correct development environment to build the
firmware. Make sure you update your submodules before trying to execute nix-shell

```bash
# Enter a development shell
nix-shell

# Build the corne keymap
just crkbd

# Build the dactyl-manuform keymap
just dact

# Or all
just
```

[qmk_firmware]: https://github.com/qmk/qmk_firmware
[Just]: https://github.com/casey/just

## 40% Layout

This is a layout made to be keyboard agnostic as I use multiple keyboards. The base layout is
designed for a split ortho / column staggered 3x6 with 3 thumb buttons.

### Features

- Can be used on almost any split or non-split ergo or ortho keyboard.
- Dual-function modifiers on home row, mirrored on both hands. ([home row mods][homerowmod])
  - Left hand: Meta, Alt, Shift, Ctrl
  - Right hand: Ctrl, Shift, Alt, Meta

[homerowmod]: https://precondition.github.io/home-row-mods

### Base layout layers

This keymap has 3 main keyboard layers built in ([Colemak-DH],  Qwerty). The default
layout is Colemak-DH. There is also a base gaming layer.

#### Colemak-DH

|      |      |      |      |      |      |      |      |      |      |      |      |      |
| ---- |:----:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| ----:|
|      |   Q  |   W  |   F  |   P  |   B  |      |   J  |   L  |   U  |   Y  |  ;:  |      |
|      |   A  |   R  |   S  |   T  |   G  |      |   M  |   N  |   E  |   I  |   O  |   '  |
| Shft |   Z  |   X  |   C  |   D  |   V  |      |   K  |   H  |  ,<  |  .>  |  /?  | Shft |
|      |      |      | Esc  |Space | Tab  |      |Enter | Bksp | Del  |      |      |      |

#### Qwerty

|      |      |      |      |      |      |      |      |      |      |      |      |      |
| ---- |:----:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| ----:|
|      |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |      |
|      |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |  ;:  |   '  |
| Shft |   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |  ,<  |  .>  |  /?  | Shft |
|      |      |      | Esc  |Space | Tab  |      |Enter | Bksp | Del  |      |      |      |

### Hold

With all the layers above if you hold a key down this will be the result.

|      |      |      |      |      |      |      |      |      |      |      |      |      |
| ---- |:----:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| :---:| ----:|
|      |      |      |      |      |      |      |      |      |      |      |      |      |
|      |LMeta | LAlt |LShift|LCtrl |      |      |      |RCtrl |RShift| LAlt |LMeta |      |
|      |      |      |      |      |      |      |      |      |      |      |      |      |
|      |      |      |Media | Nav  |Mouse |      |  FN  | Num  | Sym  |      |      |      |


## Trouble shooting flashing on linux

If having issues with the bootloader being recongnized check issue with [udev]. Also to view list of
usb devices run `lsusb`.

[udev]: https://beta.docs.qmk.fm/faqs/faq_build#linux-udev-rules-id-linux-udev-rules

## Resources and References

- [Miryoku]
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap/)
- [Rsta](https://github.com/rstacruz/my_qmk_keymaps)
- [curry](./external/qmk_firmware/users/curry/README.md)
