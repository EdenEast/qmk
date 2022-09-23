#pragma once
#include QMK_KEYBOARD_H

enum userspace_custom_keycodes
{
    VRSN = SAFE_RANGE, // Prints QMK Firmware and board info
    KC_COLEMAK,        // Sets default layer to COLEMAK
    KC_GAME,           // Sets default layer to GAME
    KC_NEQL,           // Output '!='
    KC_AROW,           // Output '->'
    KC_LPLT,           // '(' or '<' when shift
    KC_RPGT,           // ')' or '>' when shift
    KC_CMEX,           // ',' or '!' when shift
    KC_DTAT,           // '.' or '@' when shift
    ENB_GME,           // Enable game layer
    EXT_GME,           // Exit game layer
    ENB_STN,           // Enable Steno layer
    EXT_STN,           // Exit Steno layer
    NEW_SAFE_RANGE     // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_keymap(uint16_t keycode, keyrecord_t* record);

// Layer keys
/* #define R_SYML LT(_SYML, KC_R) */

// clang-format off
#define TMUX       LCTL(KC_A)

#define CTL_ESC    LCTL_T(KC_ESC)
#define CTL_ENT    LCTL_T(KC_ENT)
#define CTL_QOT    LCTL_T(KC_QUOT)
#define CTL_GRV    LCTL_T(KC_GRV)

#define SFT_QOT    LSFT_T(KC_QUOT)
#define SFT_ENT    LSFT_T(KC_ENT)
#define SFT_BSP    LSFT_T(KC_BSPC)

#define ALT_Z      LALT_T(KC_Z)
#define ALT_SLH    LALT_T(KC_SLSH)

#define GUI_Q      LGUI_T(KC_Q)
#define GUI_SCN    LGUI_T(KC_SCLN)
#define GUI_F1     LGUI_T(KC_F1)
#define GUI_F10    LGUI_T(KC_F10)

#define COLEMAK    KC_COLEMAK
#define GAME       KC_GAME

// Lock layer useful when eating and trying to navigate with one hand
// #define TG_RASE KC_RAISE
// #define TG_LOWR KC_LOWER
// #define TG_FUNC KC_FN

#define DF_BASE DF(0)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

