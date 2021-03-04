#pragma once
#include "eden.h"

// Layer keys
#define NAV_SPC LT(_NAV,   KC_SPC)
#define MED_ESC LT(_MEDIA, KC_ESC)
#define MOU_TAB LT(_MOUSE, KC_TAB)
#define FN_ENTR LT(_FN,    KC_ENT)
#define NUM_BSP LT(_NUM,   KC_BSPC)
#define SYM_DEL LT(_SYM,    KC_DEL)

#define CLMK_TO TO(_COLEMAK_DH)
#define QRTY_TO TO(_QWERTY)
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


