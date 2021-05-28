#pragma once
#include "edeneast.h"

// Taken from users/drashna
#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define LAYOUT_5x6_WRAPPER(...)         LAYOUT_5x6(__VA_ARGS__)
#define LAYOUT_split_3x6_3_WRAPPER(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define KEYMAP_wrapper(...)             LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)

#define ______________NUMBER_LEFT______________         KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5
#define ______________NUMBER_RIGHT_____________         KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0
#define ________________BLANK__________________________ _______,_______,_______,_______,_______,_______

#define ________________COLEMAK_DH_L1__________________ KC_TAB ,Q_GUI  ,KC_W   ,KC_F   ,KC_P   ,KC_B
#define ________________COLEMAK_DH_L2__________________ KC_ESC ,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G
#define ________________COLEMAK_DH_L3__________________ _______,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V

#define ________________COLEMAK_DH_R1__________________ KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_DEL
#define ________________COLEMAK_DH_R2__________________ KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT
#define ________________COLEMAK_DH_R3__________________ KC_K   ,KC_H   ,KC_COMM,KC_DOT ,SLH_GUI,_______


#define __________________QWERTY_L1____________________ KC_TAB ,Q_GUI  ,KC_W   ,KC_E   ,KC_R   ,KC_T
#define __________________QWERTY_L2____________________ KC_ESC ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G
#define __________________QWERTY_L3____________________ _______,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B

#define __________________QWERTY_R1____________________ KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_DEL
#define __________________QWERTY_R2____________________ KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT
#define __________________QWERTY_R3____________________ KC_N   ,KC_M   ,KC_COMM,KC_DOT ,SLH_GUI,_______


#define ___________________GAME_L1_____________________ KC_ESC ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R
#define ___________________GAME_L2_____________________ KC_GRV ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F
#define ___________________GAME_L3_____________________ KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V

#define ___________________GAME_R1_____________________ KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
#define ___________________GAME_R2_____________________ KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,DF_BASE
#define ___________________GAME_R3_____________________ KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH


#define __________________SYMBOLS_L1___________________ _______,KC_QUOT,KC_DQUO,KC_CIRC,KC_QUES,KC_GRV
#define __________________SYMBOLS_L2___________________ _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC
#define __________________SYMBOLS_L3___________________ _______,KC_BSLS,KC_TILD,KC_PIPE,KC_AMPR,KC_SCLN

#define __________________SYMBOLS_R1___________________ KC_LABK,KC_LBRC,KC_EQL ,KC_RBRC,KC_RABK,_______
#define __________________SYMBOLS_R2___________________ KC_LCBR,KC_LPRN,KC_COLN,KC_RPRN,KC_RCBR,_______
#define __________________SYMBOLS_R3___________________ KC_UNDS,KC_MINS,KC_PLUS,KC_ASTR,KC_SLSH,_______


#define _________________NAVIGATION_L1_________________ KC_LGUI,KC_LCTL,KC_LSFT,KC_LALT,KC_TAB ,_______
#define _________________NAVIGATION_L2_________________ _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5
#define _________________NAVIGATION_L3_________________ _______,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0

#define _________________NAVIGATION_R1_________________ KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,COLEMAK
#define _________________NAVIGATION_R2_________________ KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_CAPS,QWERTY
#define _________________NAVIGATION_R3_________________ KC_VOLD,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLU,GAME


#define _________________FUNCTION_L1___________________ _______,KC_F11 ,KC_F12 ,_______,_______,_______
#define _________________FUNCTION_L2___________________ _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5
#define _________________FUNCTION_L3___________________ _______,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10

#define _________________FUNCTION_R1___________________ _______,_______,_______,_______,_______,RESET
#define _________________FUNCTION_R2___________________ _______,_______,_______,_______,_______,_______
#define _________________FUNCTION_R3___________________ _______,_______,_______,_______,_______,_______

// Thumb keys are defined by priority do first priority seonds and third
// Default thumb defineds
#define TB_LDF1 SH_BSPC
#define TB_LDF2 MO_SYM
#define TB_LDF3 CT_TAB

#define TB_RDF1 KC_SPC
#define TB_RDF2 MO_NAV
#define TB_RDF3 AL_ENT

// TODO: Tapdace one of these keys to move out of gaming layer so only need left side active
#define TB_GMLL KC_M
#define TB_GMLC KC_SPC
#define TB_GMLR KC_I

#define TB_GMRL KC_ENT
#define TB_GMRC KC_BSPC
#define TB_GMRR KC_DEL


#define TB_LSM1 MO_NAV
#define TB_LSM2 _______
#define TB_LSM3 _______

#define TB_RSM1 _______
#define TB_RSM2 TT_FUNC
#define TB_RSM3 _______


#define TB_LNV1 _______
#define TB_LNV2 _______
#define TB_LNV3 _______

#define TB_RNV1 _______
#define TB_RNV2 _______
#define TB_RNV3 _______


#define TB_LFN1 _______
#define TB_LFN2 _______
#define TB_LFN3 _______

#define TB_RFN1 _______
#define TB_RFN2 _______
#define TB_RFN3 _______
