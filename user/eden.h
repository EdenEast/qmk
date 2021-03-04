#pragma once
#include QMK_KEYBOARD_H

#include "wrapper.h"
#include "process_records.h"

// Define layer names
enum layer_names {
    _COLEMAK_DH,
    _QWERTY,
    _NUM,
    _SYM,
    _NAV,
    _FN,
    _MEDIA,
    _MOUSE,
    _GAME,
};

// Initialize variables that hold the binary representation
// of the active modifier state
uint8_t mod_state;
