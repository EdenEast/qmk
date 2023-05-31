#pragma once
#include QMK_KEYBOARD_H

#include "process_records.h"
#include "quantum.h"
#include "wrappers.h"

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif

// Define layer names
enum userspace_layers {
  _COLEMAK_DH = 0,
  _NAV,
  _SYM,
  _ADJ,
  _GAME,
  _STENO,
  _VIM,
};
