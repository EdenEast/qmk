#pragma once
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "process_records.h"
#include "quantum.h"
#include "smart_case.h"
#include "wrappers.h"
#include "os_detect.h"
#include "callbacks.h"

#ifdef LEADER_ENABLE
#  include "leader.h"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "dances.h"
#endif

#ifdef STENO_ENABLE
#  include "keymap_steno.h"
#endif

// Define layer names
enum userspace_layers {
  _BASE = 0,
  _ENGRAM,
  _SYMBOL,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJ,
  _GAME,
  _STENO,
  _VIM,
};
