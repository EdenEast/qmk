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
#define _______________________________________________ _______,_______,_______,_______,_______,_______
//                             |

#define _________________COLEMAK_DH_L1_________________ KC_TAB ,GUI_Q  ,KC_W   ,KC_F   ,KC_P   ,KC_B
#define _________________COLEMAK_DH_L2_________________ CTL_ESC,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G
#define _________________COLEMAK_DH_L3_________________ TD_TMUX,ALT_Z  ,KC_X   ,KC_C   ,KC_D   ,KC_V

#define _________________COLEMAK_DH_R1_________________ KC_J   ,KC_L   ,KC_U   ,KC_Y   ,GUI_SCN,KC_EQL
#define _________________COLEMAK_DH_R2_________________ KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,CTL_QOT
#define _________________COLEMAK_DH_R3_________________ KC_K   ,KC_H   ,KC_COMM,KC_DOT ,ALT_SLH,SFT_ENT


#define ____________________GAME_L1____________________ KC_GRV ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R
#define ____________________GAME_L2____________________ KC_ESC ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F
#define ____________________GAME_L3____________________ KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V

#define ____________________GAME_R1____________________ KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
#define ____________________GAME_R2____________________ KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,COLEMAK
#define ____________________GAME_R3____________________ KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH


#define ____________________CODE_L1____________________ _______,GUI_EXM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC
#define ____________________CODE_L2____________________ _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5
#define ____________________CODE_L3____________________ _______,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0

#define ____________________CODE_R1____________________ KC_CIRC,KC_LPLT,KC_ASTR,KC_RPGT,GUI_NEQ,_______
#define ____________________CODE_R2____________________ KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_BSLS,_______
#define ____________________CODE_R3____________________ KC_AMPR,KC_LBRC,KC_MINS,KC_RBRC,_______,_______


#define ____________________FUNC_L1____________________ KC_F12 ,GUI_F1 ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5
#define ____________________FUNC_L2____________________ _______,_______,KC_INS ,KC_PSCR,KC_PGUP,KC_BRIU
#define ____________________FUNC_L3____________________ _______,_______,KC_PAUS,TG_MIC ,KC_PGDN,KC_BRID

#define ____________________FUNC_R1____________________ KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,GUI_F10 ,KC_F11
#define ____________________FUNC_R2____________________ KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______
#define ____________________FUNC_R3____________________ KC_VOLD,KC_MUTE,TG_MIC ,_______,_______,_______


// Thumb keys are defined by priority do first priority seonds and third
// Default thumb defineds
#define TB_DFL1 KC_BSPC
#define TB_DFL2 MO(_CODE)
#define TB_DFL3 MO(_FUNC)

/* #define TB_DFR1 BSP_SFT */
#define TB_DFR1 KC_SPC
#define TB_DFR2 MO(_CODE)
#define TB_DFR3 MO(_FUNC)

// TODO: Tapdace one of these keys to move out of gaming layer so only need left side active
#define TB_GML3 KC_M
#define TB_GML1 KC_SPC
#define TB_GML2 KC_I

#define TB_GMR2 KC_ENT
#define TB_GMR1 KC_BSPC
#define TB_GMR3 KC_DEL

#define TB_CDL1 _______
#define TB_CDL2 _______
#define TB_CDL3 _______

#define TB_CDR1 _______
#define TB_CDR2 _______
#define TB_CDR3 _______

#define TB_FNL1 _______
#define TB_FNL2 RESET
#define TB_FNL3 GAME

#define TB_FNR1 _______
#define TB_FNR2 RESET
#define TB_FNR3 GAME
