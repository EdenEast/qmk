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
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define MEDIA   MO(_MEDIA)
#define ADJUST  MO(_ADJUST)
#define QRTY_TG TG(_QWERTY)

// Left-hand home row mod
#define HOME_CA LGUI_T(KC_A)
#define HOME_CR LALT_T(KC_R)
#define HOME_CS LSFT_T(KC_S)
#define HOME_CT LCTL_T(KC_T)

#define HOME_QA LGUI_T(KC_A)
#define HOME_QS LALT_T(KC_S)
#define HOME_QD LSFT_T(KC_D)
#define HOME_QF LCTL_T(KC_F)

// Right-hand home row mod
#define HOME_CO RGUI_T(KC_O)
#define HOME_CI LALT_T(KC_I)
#define HOME_CE RSFT_T(KC_E)
#define HOME_CN RCTL_T(KC_N)

#define HOME_QC RGUI_T(KC_SCLN)
#define HOME_QL LALT_T(KC_L)
#define HOME_QK RSFT_T(KC_K)
#define HOME_QJ RCTL_T(KC_J)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

