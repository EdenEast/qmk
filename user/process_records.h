#pragma once
#include "edeneast.h"

enum userspace_custom_keycodes {
  VRSN = SAFE_RANGE, // Prints QMK Firmware and board info

  KC_COLEMAK, // Sets default layer to COLEMAK
  KC_GAME,    // Sets default layer to GAME
  TL_GAME,    // Toggle game layer
  TL_STNO,    // Toggle steno layer
  STCK_LY,

  VB_UP,
  VB_DOWN,
  MUTE_MIC,

  TG_SENT, // Toggle sentence case

  NEW_SAFE_RANGE, // use "NEWPLACEHOLDER for keymap specific codes
};

#define MO_VIM MO(_VIM)

#define COPY C(KC_INS)
#define PASTE S(KC_INS)

// Homerow mod keys
// Base layer
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LSFT_T(KC_S)
#define HM_T LCTL_T(KC_T)

#define HM_O RGUI_T(KC_O)
#define HM_I LALT_T(KC_I)
#define HM_E RSFT_T(KC_E)
#define HM_N RCTL_T(KC_N)

// Lower
// #define HM_ LGUI_T(KC_)
#define HM_UNDS LALT_T(KC_UNDS)
#define HM_PLUS LSFT_T(KC_PLUS)
#define HM_EQL LCTL_T(KC_EQL)

#define HM_LPRN RCTL_T(KC_LPRN)
#define HM_RPRN RSFT_T(KC_RPRN)
#define HM_RBRC LALT_T(KC_RBRC)
#define HM_GRV RGUI_T(KC_GRV)

// Raise
// #define HM_ LGUI_T(KC_)
// #define HM_ LALT_T(KC_)
// #define HM_ LSFT_T(KC_)
// #define HM_ LCTL_T(KC_)
//
// #define HM_ RCTL_T(KC_)
// #define HM_ RSFT_T(KC_)
// #define HM_ LALT_T(KC_)
// #define HM_ RGUI_T(KC_)

// Adj
#define HM_PRSC LGUI_T(KC_PSCR)
// #define HM_ LALT_T(KC_)
// #define HM_ LSFT_T(KC_)
// #define HM_ LCTL_T(KC_)
//
#define HM_MIC RCTL_T(KC_F20)
// #define HM_ RSFT_T(KC_)
// #define HM_ LALT_T(KC_)

// Template
// #define HM_ LGUI_T(KC_)
// #define HM_ LALT_T(KC_)
// #define HM_ LSFT_T(KC_)
// #define HM_ LCTL_T(KC_)
//
// #define HM_ RCTL_T(KC_)
// #define HM_ RSFT_T(KC_)
// #define HM_ LALT_T(KC_)
// #define HM_ RGUI_T(KC_)

#define CTR_ESC LCTL_T(KC_ESC)
#define CTR_QOT LCTL_T(KC_QUOT)

// Thumb keys

#define LOW_TAB LT(_LOWER, KC_TAB)
#define SFT_BSP LSFT_T(KC_BSPC)
#define SFT_SPC RSFT_T(KC_SPC)
#define RAS_MIN LT(_RAISE, KC_MINS)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
