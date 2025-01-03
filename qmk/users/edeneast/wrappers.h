#pragma once
#include "edeneast.h"

/**
 * As these defintions are a list of comma seperated arguments, we require a
 * wrapper in order for these defintions to be expanded by a LAYOUT_xxx macro.
 *
 * NOTE: These are all the same length. Make sure to ballence the underscores
 * to keep the length consistent.
 */

// clang-format off
#define __NUMBER_LEFT______________________________                KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __NUMBER_RIGHT_____________________________                KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __NUMBER_OPT_LEFT__________________________                KC_7,    KC_8,    KC_9,    KC_0,    KC_5
#define __NUMBER_OPT_RIGHT_________________________                KC_6,    KC_1,    KC_2,    KC_3,    KC_4
#define __BLANK_____________________________________________       _______, _______, _______, _______, _______, _______


#define __COLEMAK_DH_L1_____________________________________       KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define __COLEMAK_DH_L2_____________________________________       CTR_ESC, HMA_A,   HMA_R,   HMA_S,   HMA_T,   KC_G
#define __COLEMAK_DH_L3_____________________________________       HM_MUX,  HMA_Z,    KC_X,    KC_C,    KC_D,   KC_V

#define __COLEMAK_DH_R1_____________________________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL
#define __COLEMAK_DH_R2_____________________________________       KC_M,    HMA_N,   HMA_E,   HMA_I,   HMA_O,   CTR_QOT
#define __COLEMAK_DH_R3_____________________________________       KC_K,    KC_H,    KC_COMM, KC_DOT,  HMA_SLSH,HM_ENT


#define __ENGRAM_L1_________________________________________       KC_GRV,  KC_B,    KC_Y,    KC_O,    KC_U,    KC_QUOT
#define __ENGRAM_L2_________________________________________       CTR_ESC, HME_C,   HME_I,   HME_E,   HME_A,   KC_COMM
#define __ENGRAM_L3_________________________________________       HM_MUX,  KC_G,    KC_X,    KC_J,    KC_K,    KC_EQL

#define __ENGRAM_R1_________________________________________       KC_SCLN, KC_L,    KC_D,    KC_W,    KC_V,    KC_Z
#define __ENGRAM_R2_________________________________________       KC_DOT,  HME_H,   HME_T,   HME_S,   HME_N,   KC_Q
#define __ENGRAM_R3_________________________________________       KC_SLSH, KC_R,    KC_M,    KC_F,    KC_P,    HM_ENT


#define __SYMBOL_L0_________________________________________       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __SYMBOL_L1_________________________________________       _______, _______, KC_LABK, KC_RABK, KC_AT,   UP_DIR
#define __SYMBOL_L2_________________________________________       _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH
#define __SYMBOL_L3_________________________________________       _______, KC_BSLS, KC_SLSH, KC_ASTR, KC_CIRC, DB_QUOT

#define __SYMBOL_R0_________________________________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11
#define __SYMBOL_R1_________________________________________       KC_AMPR, _______, KC_LBRC, KC_RBRC, _______, KC_F12
#define __SYMBOL_R2_________________________________________       KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, KC_DQT
#define __SYMBOL_R3_________________________________________       KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, _______, _______


#define __NAVIGATION_L0_____________________________________       _______, _______, _______, _______, _______, _______
#define __NAVIGATION_L1_____________________________________       _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______
#define __NAVIGATION_L2_____________________________________       _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______
#define __NAVIGATION_L3_____________________________________       _______, _______, _______, _______, _______, _______

#define __NAVIGATION_R0_____________________________________       _______, _______, _______, _______, _______, _______
#define __NAVIGATION_R1_____________________________________       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______
#define __NAVIGATION_R2_____________________________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______
#define __NAVIGATION_R3_____________________________________       _______, _______, _______, _______, _______, _______


#define __ADJUSTMENT_L0_____________________________________       QK_BOOT, KC_MAKE, KC_CAPS, KC_ESC,  _______, _______
#define __ADJUSTMENT_L1_____________________________________       OS_RST,  OS_MAC,  OS_WIN,  _______, _______, _______
#define __ADJUSTMENT_L2_____________________________________       _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______
#define __ADJUSTMENT_L3_____________________________________       _______, ED_UNDO, ED_CUT, ED_COPY, ED_PASTE, KC_PSCR

#define __ADJUSTMENT_R0_____________________________________       _______, _______, _______, _______, KC_MAKE, QK_BOOT
#define __ADJUSTMENT_R1_____________________________________       _______,   VB_UP, VB_DOWN, KC_MUTE, _______, _______
#define __ADJUSTMENT_R2_____________________________________       _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______
#define __ADJUSTMENT_R3_____________________________________       _______, MUTE_MIC, _______, _______, TG_SENT, _______


#define __RAISE_L1__________________________________________       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __RAISE_L2__________________________________________       _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______
#define __RAISE_L3__________________________________________       _______, STCK_LY, _______, _______, _______, _______

#define __RAISE_R1__________________________________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______
#define __RAISE_R2__________________________________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______
#define __RAISE_R3__________________________________________       KC_MPRV, KC_MPLY, KC_MNXT, _______, STCK_LY, _______


#define __LOWER_L1__________________________________________       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __LOWER_L2__________________________________________       _______, _______, HM_UNDS, HM_PLUS, HM_EQL,  KC_TILD
#define __LOWER_L3__________________________________________       _______, STCK_LY, _______, _______, _______, _______

#define __LOWER_R1__________________________________________       KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_COLN, _______
#define __LOWER_R2__________________________________________       KC_LBRC, HM_LPRN, HM_RPRN, HM_RBRC, KC_GRV,  _______
#define __LOWER_R3__________________________________________       KC_PIPE, KC_LCBR, KC_RCBR, KC_BSLS, STCK_LY, _______


#define __ADJUST_L1_________________________________________       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __ADJUST_L2_________________________________________       QK_BOOT, HM_PRSC, KC_LALT, KC_LSFT, KC_LCTL, TG_SENT
#define __ADJUST_L3_________________________________________       _______, STCK_LY, _______, TL_ENGM, TL_GAME, TL_STNO


#define __ADJUST_R1_________________________________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11
#define __ADJUST_R2_________________________________________       VB_UP,   HM_MIC,  KC_RSFT, KC_LALT, HM_PRSC, QK_BOOT
#define __ADJUST_R3_________________________________________       VB_DOWN, KC_MUTE, _______, _______, STCK_LY, _______


#define __GAME_L1___________________________________________       KC_GRV,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R
#define __GAME_L2___________________________________________       KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F
#define __GAME_L3___________________________________________       KC_LALT, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V

#define __GAME_R1___________________________________________       KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define __GAME_R2___________________________________________       KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TL_GAME
#define __GAME_R3___________________________________________       KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#ifdef STENO_ENABLE
#define __STENO_L1__________________________________________       STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6
#define __STENO_L2__________________________________________       STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1
#define __STENO_L3__________________________________________       TL_STNO, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2

#define __STENO_R1__________________________________________       STN_N7 ,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC
#define __STENO_R2__________________________________________       STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR
#define __STENO_R3__________________________________________       STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR
#endif

// clang-format on
