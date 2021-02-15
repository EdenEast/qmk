#pragma once

#include QMK_KEYBOARD_H

// Initialize variables that hold the binary representation
// of the active modifier state
uint8_t mod_state;

enum layer_names {
    _COLEMAK_DH,
    _QWERTY,
    _SYM,
    _NAV,
    _MEDIA,
    _ADJUST,
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define MEDIA   MO(_MEDIA)
#define ADJUST  MO(_ADJUST)
#define QRTY_TG TG(_QWERTY)

// Left-hand home row mod
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

#define HOME_SS LALT_T(KC_S)
#define HOME_D  LSFT_T(KC_D)
#define HOME_F  LCTL_T(KC_F)

// Right-hand home row mod
#define HOME_O RGUI_T(KC_O)
#define HOME_I LALT_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N RCTL_T(KC_N)

#define HOME_SC RGUI_T(KC_SCLN)
#define HOME_L  LALT_T(KC_L)
#define HOME_K  RSFT_T(KC_K)
#define HOME_J  RCTL_T(KC_J)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

