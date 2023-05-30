#pragma once
#include "edeneast.h"

#if defined(KEYMAP_SAFE_RANGE)
#define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
  VRSN = SAFE_RANGE, // Prints QMK Firmware and board info

  KC_COLEMAK,         // Sets default layer to COLEMAK
  KC_GAME,            // Sets default layer to GAME
  TOGGLE_GAME_LAYER,  // Toggle game layer
  TOGGLE_STENO_LAYER, // Toggle steno layer

  VB_UP,
  VB_DOWN,
  MUTE_MIC,

  NEW_SAFE_RANGE, // use "NEWPLACEHOLDER for keymap specific codes
  /* USER_SAFE_RANGE, // use "NEWPLACEHOLDER for keymap specific codes */
};

#define COPY C(KC_INS)
#define PASTE S(KC_INS)

// Homerow mod keys

#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LSFT_T(KC_S)
#define HM_T LCTL_T(KC_T)

#define HM_O RGUI_T(KC_O)
#define HM_I LALT_T(KC_I)
#define HM_E RSFT_T(KC_E)
#define HM_N RCTL_T(KC_N)

#define HM_CIRC LGUI_T(KC_CIRC)
#define HM_PLUS LALT_T(KC_PLUS)
#define HM_EQUL LSFT_T(KC_EQL)
#define HM_UNDS LCTL_T(KC_UNDS)

#define HM_LBCK RCTL_T(KC_LBRC)
#define HM_RBCK RSFT_T(KC_RBRC)
#define HM_GRAV LALT_T(KC_GRV)
#define HM_DOLR RGUI_T(KC_DLR)

#define CTR_ESC LCTL_T(KC_ESC)
#define CTR_QOT LCTL_T(KC_QUOT)

// Thumb keys

#define SYM_TAB LT(_SYM, KC_TAB)
#define SFT_BSP LSFT_T(KC_BSPC)
#define SFT_SPC LSFT_T(KC_SPC)
#define NAV_MIN LT(_NAV, KC_MINS)

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
