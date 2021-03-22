#pragma once
#include QMK_KEYBOARD_H

#include "wrapper.h"
#include "process_records.h"
#ifdef TAP_DANCE_ENABLE
#    include "tap_dances.h"
#endif  // TAP_DANCE_ENABLE

// Define layer names
enum layer_names {
    _COLEMAK_DH = 0,
    _WORKMAN,
    _QWERTY,
    _GAME,
    _NUM,
    _SYM,
    _NAV,
    _FN,
    _MEDIA,
    _MOUSE,
};

// Initialize variables that hold the binary representation
// of the active modifier state
uint8_t mod_state;
