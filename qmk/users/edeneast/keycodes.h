#pragma once
#include QMK_KEYBOARD_H

enum userspace_custom_keycodes {
  VRSN = QK_USER,

  KC_CLMK, // Sets default layer to COLEMAK_DH
  KC_ENGM, // Sets default layer to ENGRAM
  KC_GAME, // Sets default layer to GAME
  TL_GAME, // Toggle game layer
  TL_STNO, // Toggle steno layer
  TL_ENGM, // Toggle engram layer
  STCK_LY,
  TMUX_PX, // Gui when pressed, Tmux prefix when tapped
  TRP_GRV, // Triggers grave

  UP_DIR,  // '../' up directory
  DB_QUOT, // Double quote `''<-=<=<=<=<<=<=<=<=<=<=<=<=<=`
  KC_RARW, // Right arrow <-

  OS_RST,
  OS_WIN,
  OS_MAC,
  OS_LNX,

  ED_UNDO,
  ED_CUT,
  ED_COPY,
  ED_PASTE,

  VB_UP,
  VB_DOWN,
  MUTE_MIC,

  TG_SENT, // Toggle sentence case
  KC_MAKE, // Run keyboard's customized make command

  NEW_SAFE_RANGE, // use "NEWPLACEHOLDER for keymap specific codes
};
