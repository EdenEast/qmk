#pragma once

enum userspace_custom_keycodes {
    VRSN = SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_COLEMAK,         // Sets default layer to COLEMAK
    KC_QWERTY,          // Sets default layer to QWERTY
    KC_GAME,            // Sets default layer to GAME
    NEW_SAFE_RANGE      // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Layer keys
#define SH_BSPC LSFT_T(KC_BSPC)
#define MO_SYM  MO(_SYM)
#define MO_NAV  MO(_NAV)
#define CT_TAB  LCTL_T(KC_TAB)
#define AL_ENT  LALT_T(KC_ENT)
#define TT_FUNC TT(_FUNC)
#define Z_CTRL  LCTL_T(KC_Z)
#define SLH_CTR LCTL_T(KC_SLSH)
#define Q_GUI   LGUI_T(KC_Q)
#define P_GUI   LGUI_T(KC_P)
#define SCN_GUI LGUI_T(KC_SCLN)

#define COLEMAK KC_COLEMAK
#define QWERTY  KC_QWERTY
#define GAME    KC_GAME

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

