#pragma once
#include QMK_KEYBOARD_H

#include "process_records.h"
#include "quantum.h"
#include "wrappers.h"

#ifdef TAP_DANCE_ENABLE
#include "dances.h"
#endif

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif

// Define layer names
enum userspace_layers {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJ,
  _GAME,
  _STENO,
  _VIM,
};
