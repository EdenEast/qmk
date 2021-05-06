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

#define ________________BLANK__________________________ _______,_______,_______,_______,_______,_______
#define ______________NUMBER_LEFT______________         KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5
#define ______________NUMBER_RIGHT_____________         KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0

#define ________________COLEMAK_DH_L1__________________ KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B
#define ________________COLEMAK_DH_L2__________________ KC_ESC ,HOME_CA,HOME_CR,HOME_CS,HOME_CT,KC_G
#define ________________COLEMAK_DH_L3__________________ OS_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V

#define ________________COLEMAK_DH_R1__________________ KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_DEL
#define ________________COLEMAK_DH_R2__________________ KC_M   ,HOME_CN,HOME_CE,HOME_CI,HOME_CO,KC_QUOT
#define ________________COLEMAK_DH_R3__________________ KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,OS_RSFT


#define __________________QWERTY_L1____________________ KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T
#define __________________QWERTY_L2____________________ KC_ESC ,HOME_QA,HOME_QS,HOME_QD,HOME_QF,KC_G
#define __________________QWERTY_L3____________________ OS_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B

#define __________________QWERTY_R1____________________ KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_DEL
#define __________________QWERTY_R2____________________ KC_H   ,HOME_QJ,HOME_QK,HOME_QL,HOME_QC,KC_QUOT
#define __________________QWERTY_R3____________________ KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,OS_RSFT


#define ___________________GAME_L1_____________________ KC_ESC ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R
#define ___________________GAME_L2_____________________ KC_GRV ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F
#define ___________________GAME_L3_____________________ KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V

#define ___________________GAME_R1_____________________ KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
#define ___________________GAME_R2_____________________ KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,TD_LAYR
#define ___________________GAME_R3_____________________ KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH


#define ___________________RAISE_L1____________________ KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5
#define ___________________RAISE_L2____________________ KC_PSCR,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,KC_VOLU
#define ___________________RAISE_L3____________________ KC_MUTE,KC_MSTP,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD

#define ___________________RAISE_R1____________________ KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11
#define ___________________RAISE_R2____________________ KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_CAPS,KC_PAUS
#define ___________________RAISE_R3____________________ KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_INS ,TG_RASE


#define ___________________LOWER_L1____________________ _______,KC_1   , KC_2  , KC_3  , KC_4  , KC_5
#define ___________________LOWER_L2____________________ KC_BSLS,KC_DLR ,KC_PLUS,KC_LPRN,KC_RPRN,KC_AT
#define ___________________LOWER_L3____________________ TG_LOWR,KC_EXLM,KC_HASH,KC_LCBR,KC_RCBR,KC_TILD

#define ___________________LOWER_R1____________________ KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,_______
#define ___________________LOWER_R2____________________ KC_PIPE,KC_MINS,KC_EQL ,KC_UNDS,KC_ASTR,KC_GRV
#define ___________________LOWER_R3____________________ KC_AMPR,KC_LBRC,KC_RBRC,KC_PERC,KC_CIRC,_______


#define ____________________FN_L1______________________ KC_PWR ,KC_SLEP,DEBUG  ,KC_BRIU,KC_BRID,RESET
#define ____________________FN_L2______________________ _______,_______,GAME   ,QWERTY ,COLEMAK,_______
#define ____________________FN_L3______________________ TG_FUNC,UNDO   ,CUT    ,COPY   ,_______,PASTE

#define ____________________FN_R1______________________ RESET  ,KC_BRID,KC_BRIU,DEBUG  ,KC_SLEP,KC_PWR
#define ____________________FN_R2______________________ _______,COLEMAK,QWERTY ,GAME   ,_______,_______
#define ____________________FN_R3______________________ _______,_______,_______,_______,_______,TG_FUNC


#define TB_CMLL FN_DEL
#define TB_CMLC LO_BSP
#define TB_CMLR RA_TAB

#define TB_CMRL LO_ENT
#define TB_CMRC RA_SPC
#define TB_CMRR FN_ESC


// TODO: Tapdace one of these keys to move out of gaming layer so only need left side active
#define TB_GMLL KC_M
#define TB_GMLC KC_SPC
#define TB_GMLR KC_I

#define TB_GMRL KC_ENT
#define TB_GMRC KC_BSPC
#define TB_GMRR KC_DEL


#define TB_RALL KC_DEL
#define TB_RALC KC_BSPC
#define TB_RALR KC_TAB

#define TB_RARL KC_ENT
#define TB_RARC KC_SPC
#define TB_RARR KC_ESC


#define TB_LOLL KC_DEL
#define TB_LOLC KC_BSPC
#define TB_LOLR KC_TAB

#define TB_LORL KC_ENT
#define TB_LORC KC_SPC
#define TB_LORR KC_ESC


#define TB_FNLL KC_DEL
#define TB_FNLC KC_BSPC
#define TB_FNLR KC_TAB

#define TB_FNRL KC_ENT
#define TB_FNRC KC_SPC
#define TB_FNRR KC_ESC

