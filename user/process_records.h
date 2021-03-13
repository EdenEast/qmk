#pragma once

enum userspace_custom_keycodes {
    VRSN = SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_COLEMAK,         // Sets default layer to COLEMAK
    KC_WORKMAN,         // Sets default layer to WORKMAN
    KC_QWERTY,          // Sets default layer to QWERTY
    NEW_SAFE_RANGE      // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Layer keys
#define NAV_SPC LT(_NAV,   KC_SPC)
#define MDA_ESC LT(_MEDIA, KC_ESC)
#define MOU_TAB LT(_MOUSE, KC_TAB)
#define FN_ENTR LT(_FN,    KC_ENT)
#define NUM_BSP LT(_NUM,   KC_BSPC)
#define SYM_DEL LT(_SYM,    KC_DEL)

#define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN
#define QWERTY  KC_QWERTY

#define GAME_TG TG(_GAME)

// Lock layer useful when eating and trying to navigate with one hand
#define DF_BASE DF(_COLEMAK_DH)
#define DF_NUM  DF(_NUM)
#define DF_SYM  DF(_SYM)
#define DF_NAV  DF(_NAV)
#define DF_FN   DF(_FN)
#define DF_MDIA DF(_MEDIA)
#define DF_MOUS DF(_MOUSE)

// Left-hand home row mod
// Colemak-DH
#define HOME_CA LGUI_T(KC_A)
#define HOME_CR LALT_T(KC_R)
#define HOME_CS LSFT_T(KC_S)
#define HOME_CT LCTL_T(KC_T)

// Workman
#define HOME_WA LGUI_T(KC_A)
#define HOME_WS LALT_T(KC_S)
#define HOME_WH LSFT_T(KC_H)
#define HOME_WT LCTL_T(KC_T)

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

// Workman
#define HOME_WI LGUI_T(KC_I)
#define HOME_WO LALT_T(KC_O)
#define HOME_WE LSFT_T(KC_E)
#define HOME_WN LCTL_T(KC_N)

// Qwerty
#define HOME_QC RGUI_T(KC_SCLN)
#define HOME_QL LALT_T(KC_L)
#define HOME_QK RSFT_T(KC_K)
#define HOME_QJ RCTL_T(KC_J)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

// Clipboard
#define UNDO  C(KC_Z)
#define REDO  C(KC_Y)
#define CUT   C(KC_X)
#define COPY  C(KC_C)
#define PASTE C(KC_V)

#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

