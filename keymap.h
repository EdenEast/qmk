#pragma once

#include QMK_KEYBOARD_H

// Initialize variables that hold the binary representation
// of the active modifier state
uint8_t mod_state;

enum layer_names {
    _COLEMAK_DH,
    _QWERTY,
    _DVORAK,
    _SYM,
    _NAV,
    _MEDIA,
    _GAMING,
};

// Layer keys
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define MEDIA   MO(_MEDIA)
#define ADJUST  MO(_ADJUST)
// #define QRTY_TG TG(_QWERTY)
#define CLMK_TO TO(_COLEMAK_DH)
#define QRTY_TO TO(_QWERTY)
#define DVRK_TO TO(_DVORAK)
#define GAME_TG TG(_GAMING)

// Left-hand home row mod
// Colemak-DH
#define HOME_CA LGUI_T(KC_A)
#define HOME_CR LALT_T(KC_R)
#define HOME_CS LSFT_T(KC_S)
#define HOME_CT LCTL_T(KC_T)

// Dvorak
#define HOME_DA LGUI_T(KC_A)
#define HOME_DO LALT_T(KC_O)
#define HOME_DE LSFT_T(KC_E)
#define HOME_DU LCTL_T(KC_U)

// Qwerty
#define HOME_QA LGUI_T(KC_A)
#define HOME_QS LALT_T(KC_S)
#define HOME_QD LSFT_T(KC_D)
#define HOME_QF LCTL_T(KC_F)

// Right-hand home row mod
// Colemak-DH
#define HOME_CO RGUI_T(KC_O)
#define HOME_CI LALT_T(KC_I)
#define HOME_CE RSFT_T(KC_E)
#define HOME_CN RCTL_T(KC_N)

// Dvorak
#define HOME_DS RGUI_T(KC_S)
#define HOME_DN LALT_T(KC_N)
#define HOME_DT RSFT_T(KC_T)
#define HOME_DH RCTL_T(KC_H)

// Qwerty
#define HOME_QC RGUI_T(KC_SCLN)
#define HOME_QL LALT_T(KC_L)
#define HOME_QK RSFT_T(KC_K)
#define HOME_QJ RCTL_T(KC_J)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

