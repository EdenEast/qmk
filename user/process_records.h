#pragma once

enum userspace_custom_keycodes {
    VRSN = SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_COLEMAK,         // Sets default layer to COLEMAK
    KC_GAME,            // Sets default layer to GAME
    NEW_SAFE_RANGE      // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Layer keys
/* #define R_SYML LT(_SYML, KC_R) */
#define TMUX    LCTL(KC_A)
#define T_SYML  LT(_SYML, KC_T)
#define F_NUM   LT(_NUM, KC_F)
#define N_SYMR  LT(_SYMR, KC_N)
#define U_FUNC  LT(_FUNC, KC_U)

#define ESC_CTL LCTL_T(KC_ESC)
#define ENT_CTL LCTL_T(KC_ENT)
#define Z_ALT   LALT_T(KC_Z)
#define SLH_ALT LALT_T(KC_SLSH)
#define DOT_GUI LGUI_T(KC_DOT)
#define X_GUI   LGUI_T(KC_X)

#define BSP_SFT LSFT_T(KC_BSPC)
#define SPC_ADJ LT(_ADJ, KC_SPC)
#define UNS_NUM LT(_NUM, KC_UNDS)
#define TAB_ADJ LT(_ADJ, KC_TAB)
#define MIN_SYM LT(_SYML, KC_MINS)
#define ENT_SYM LT(_SYMR, KC_ENT)

/* #define SPC_ADJ LT(_ADJ, KC_SPC) */
/* #define TAB_ADJ LT(_ADJ, KC_TAB) */

#define COLEMAK KC_COLEMAK
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

