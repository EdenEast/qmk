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
#define ________________NUMBER_LEFT________________                KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________                KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _______________________BLANK________________________       _______, _______, _______, _______, _______, _______


#define ___________________COLEMAK_DH_L1____________________       KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ___________________COLEMAK_DH_L2____________________       CTR_ESC, HM_A,    HM_R,    HM_S,    HM_T,    KC_G
#define ___________________COLEMAK_DH_L3____________________       KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ___________________COLEMAK_DH_R1____________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL
#define ___________________COLEMAK_DH_R2____________________       KC_M,    HM_N,    HM_E,    HM_I,    HM_O,    CTR_QOT
#define ___________________COLEMAK_DH_R3____________________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT


#define _______________________SYM_L1_______________________       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _______________________SYM_L2_______________________       _______, HM_CIRC, HM_PLUS, HM_EQUL, HM_DOLR, KC_ASTR
#define _______________________SYM_L3_______________________       _______, KC_EXLM, KC_AT,   KC_HASH, KC_AMPR, KC_PERC

#define _______________________SYM_R1_______________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______
#define _______________________SYM_R2_______________________       KC_TILD, HM_LBCK, HM_RBCK, HM_GRAV, KC_DLR,  _______
#define _______________________SYM_R3_______________________       KC_COLN, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSLS, _______


#define _______________________NAV_L1_______________________       _______, _______, _______, _______, _______, _______
#define _______________________NAV_L2_______________________       _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______
#define _______________________NAV_L3_______________________       _______, _______, _______, _______, _______, _______

#define _______________________NAV_R1_______________________       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______
#define _______________________NAV_R2_______________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______
#define _______________________NAV_R3_______________________       _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______


// #define _______________________ADJ_L1_______________________       _______, _______, _______, _______, _______, VB_UP
#define _______________________ADJ_L1_______________________       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _______________________ADJ_L2_______________________       _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, MUTE_MIC
#define _______________________ADJ_L3_______________________       QK_BOOT, _______, _______, _______, TL_GAME, VB_DOWN

#define _______________________ADJ_R1_______________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11
#define _______________________ADJ_R2_______________________       _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, _______
#define _______________________ADJ_R3_______________________       _______, _______, _______, _______, _______, QK_BOOT


#define ______________________GAME_L1_______________________       KC_GRV,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R
#define ______________________GAME_L2_______________________       KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F
#define ______________________GAME_L3_______________________       KC_LALT, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V

#define ______________________GAME_R1_______________________       KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define ______________________GAME_R2_______________________       KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TL_GAME
#define ______________________GAME_R3_______________________       KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// clang-format on
