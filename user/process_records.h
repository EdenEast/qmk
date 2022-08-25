#pragma once

enum userspace_custom_keycodes {
    VRSN = SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_COLEMAK,         // Sets default layer to COLEMAK
    KC_GAME,            // Sets default layer to GAME
    KC_NEQL,            // Sets '!='
    KC_LPLT,            // '(' or '<' when shift
    KC_RPGT,            // ')' or '>' when shift
    NEW_SAFE_RANGE      // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Layer keys
/* #define R_SYML LT(_SYML, KC_R) */

#define TMUX       LCTL(KC_A)

#define CTL_ESC    LCTL_T(KC_ESC)
#define CTL_ENT    LCTL_T(KC_ENT)
#define CTL_QOT    LCTL_T(KC_QUOT)

#define SFT_QOT    LSFT_T(KC_QUOT)
#define SFT_ENT    LSFT_T(KC_ENT)

#define ALT_Z      LALT_T(KC_Z)
#define ALT_SLH    LALT_T(KC_SLSH)

#define GUI_Q      LGUI_T(KC_Q)
#define GUI_SCN    LGUI_T(KC_SCLN)
#define GUI_NEQ    LGUI_T(KC_NEQL)
#define GUI_EXM    LGUI_T(KC_EXLM)
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

// Clipboard
#define UNDO  C(KC_Z)
#define REDO  C(KC_Y)
#define CUT   C(KC_X)
#define COPY  C(KC_C)
#define PASTE C(KC_V)

#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

