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

#define _________________COLEMAK_DH_L1_________________ KC_TAB ,KC_Q   ,KC_W   ,F_NUM  ,KC_P   ,KC_B
#define _________________COLEMAK_DH_L2_________________ ESC_CTL,KC_A   ,KC_R   ,KC_S   ,T_SYML ,KC_G
#define _________________COLEMAK_DH_L3_________________ TD_TMUX,Z_ALT  ,X_GUI  ,KC_C   ,KC_D   ,KC_V

#define _________________COLEMAK_DH_R1_________________ KC_J   ,KC_L   ,U_FUNC ,KC_Y   ,KC_SCLN,KC_DEL
#define _________________COLEMAK_DH_R2_________________ KC_M   ,N_SYMR ,KC_E   ,KC_I   ,KC_O   ,QUT_CTL
#define _________________COLEMAK_DH_R3_________________ KC_K   ,KC_H   ,KC_COMM,DOT_GUI,SLH_ALT,ENT_SFT

#define ____________________GAME_L1____________________ KC_GRV ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R
#define ____________________GAME_L2____________________ KC_ESC ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F
#define ____________________GAME_L3____________________ KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V

#define ____________________GAME_R1____________________ KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
#define ____________________GAME_R2____________________ KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,COLEMAK
#define ____________________GAME_R3____________________ KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH

#define ________________SYMBOLS_ONE_L1_________________ _______,_______,_______,_______,_______,_______
#define ________________SYMBOLS_ONE_L2_________________ _______,KC_CIRC,KC_ASTR,KC_AMPR,KC_NO  ,_______
#define ________________SYMBOLS_ONE_L3_________________ _______,_______,_______,_______,_______,_______

#define ________________SYMBOLS_ONE_R1_________________ _______,KC_TILD,KC_BSLS,KC_QUOT,_______,_______
#define ________________SYMBOLS_ONE_R2_________________ KC_HASH,KC_MINS,KC_SLSH,KC_DQUO,KC_DLR ,_______
#define ________________SYMBOLS_ONE_R3_________________ _______,KC_UNDS,KC_PIPE,KC_GRV ,_______,_______

#define ________________SYMBOLS_TWO_L1_________________ _______,_______,_______,KC_LT  ,KC_GT  ,KC_COLN
#define ________________SYMBOLS_TWO_L2_________________ _______,KC_LCBR,KC_RCBR,KC_LPRN,KC_RPRN,KC_AT
#define ________________SYMBOLS_TWO_L3_________________ _______,_______,KC_EXLM,KC_LBRC,KC_RBRC,_______

#define ________________SYMBOLS_TWO_R1_________________ _______,_______,_______,_______,_______,_______
#define ________________SYMBOLS_TWO_R2_________________ _______,KC_NO  ,KC_EQL ,KC_PLUS,KC_PERC,_______
#define ________________SYMBOLS_TWO_R3_________________ _______,_______,_______,_______,_______,_______

#define ___________________NUMBER_L1___________________ _______,_______,_______,_______,_______,_______
#define ___________________NUMBER_L2___________________ _______,_______,_______,KC_NO  ,_______,_______
#define ___________________NUMBER_L3___________________ _______,_______,_______,_______,_______,_______

#define ___________________NUMBER_R1___________________ KC_PLUS,KC_7   ,KC_8   ,KC_9   ,KC_SLSH,_______
#define ___________________NUMBER_R2___________________ KC_MINS,KC_1   ,KC_2   ,KC_3   ,KC_0   ,_______
#define ___________________NUMBER_R3___________________ KC_EQL ,KC_4   ,KC_5   ,KC_6   ,KC_ASTR,_______

#define __________________FUNCTION_L1__________________ _______,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR
#define __________________FUNCTION_L2__________________ _______,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_INS
#define __________________FUNCTION_L3__________________ _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_PAUS

#define __________________FUNCTION_R1__________________ _______,TG_MIC ,KC_NO  ,KC_PAUS,_______,_______
#define __________________FUNCTION_R2__________________ _______,_______,_______,_______,_______,_______
#define __________________FUNCTION_R3__________________ _______,_______,_______,_______,_______,_______

#define ___________________ADJUST_L1___________________ RESET  ,_______,_______,_______,COLEMAK,GAME
#define ___________________ADJUST_L2___________________ _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______
#define ___________________ADJUST_L3___________________ _______,UNDO   ,CUT    ,COPY   ,_______,PASTE

#define ___________________ADJUST_R1___________________ KC_HOME,KC_PGDN,KC_PGUP,KC_END ,_______,RESET
#define ___________________ADJUST_R2___________________ KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______
#define ___________________ADJUST_R3___________________ KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,KC_MUTE


// Thumb keys are defined by priority do first priority seonds and third
// Default thumb defineds
#define TB_LDF1 BSP_SFT
#define TB_LDF2 TAB_ADJ
#define TB_LDF3 ENT_SYM

#define TB_RDF1 SPC_ADJ
#define TB_RDF2 UNS_NUM
#define TB_RDF3 MIN_SYM

// TODO: Tapdace one of these keys to move out of gaming layer so only need left side active
#define TB_GML3 KC_M
#define TB_GML1 KC_SPC
#define TB_GML2 KC_I

#define TB_GMR2 KC_ENT
#define TB_GMR1 KC_BSPC
#define TB_GMR3 KC_DEL


#define TB_LSM1 _______
#define TB_LSM2 _______
#define TB_LSM3 _______

#define TB_RSM1 _______
#define TB_RSM2 _______
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


#define TB_LAJ1 KC_BSPC
#define TB_LAJ2 _______
#define TB_LAJ3 _______

#define TB_RAJ1 KC_SPC
#define TB_RAJ2 _______
#define TB_RAJ3 _______
