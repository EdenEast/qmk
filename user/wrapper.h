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

#define ________________COLEMAK_DH_L1__________________ _______,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B
#define ________________COLEMAK_DH_L2__________________ _______,HOME_CA,HOME_CR,HOME_CS,HOME_CT,KC_G
#define ________________COLEMAK_DH_L3__________________ OS_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V

#define ________________COLEMAK_DH_R1__________________ KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,_______
#define ________________COLEMAK_DH_R2__________________ KC_M   ,HOME_CN,HOME_CE,HOME_CI,HOME_CO,KC_QUOT
#define ________________COLEMAK_DH_R3__________________ KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,OS_RSFT


#define ________________QWERTY_L1______________________ _______,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T
#define ________________QWERTY_L2______________________ _______,HOME_QA,HOME_QS,HOME_QD,HOME_QF,KC_G
#define ________________QWERTY_L3______________________ OS_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B

#define ________________QWERTY_R1______________________ KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,_______
#define ________________QWERTY_R2______________________ KC_H   ,HOME_QJ,HOME_QK,HOME_QL,HOME_QC,KC_QUOT
#define ________________QWERTY_R3______________________ KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,OS_RSFT


#define ________________GAME_L1________________________ KC_ESC ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R
#define ________________GAME_L2________________________ KC_GRV ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F
#define ________________GAME_L3________________________ KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V

#define ________________GAME_R1________________________ KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
#define ________________GAME_R2________________________ KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,TD_LAYR
#define ________________GAME_R3________________________ KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT,KC_SLSH


#define ________________NUM_L1_________________________ _______,KC_LBRC,KC_7   ,KC_8   ,KC_9   ,KC_RBRC
#define ________________NUM_L2_________________________ _______,KC_SCLN,KC_4   ,KC_5   ,KC_6   ,KC_EQL
#define ________________NUM_L3_________________________ _______,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_BSLS

#define ________________NUM_R1_________________________ _______,_______,_______,_______,_______,RESET
#define ________________NUM_R2_________________________ _______,KC_LCTL,KC_LSFT,KC_LALT,KC_LGUI,TD_LAYR
#define ________________NUM_R3_________________________ _______,DF_NUM ,_______,_______,_______,_______


#define ________________SYM_L1_________________________ _______,KC_LCBR,KC_AMPR,KC_ASTR,KC_LPRN,KC_RCBR
#define ________________SYM_L2_________________________ _______,KC_COLN,KC_DLR ,KC_PERC,KC_CIRC,KC_PLUS
#define ________________SYM_L3_________________________ _______,KC_TILD,KC_EXLM,KC_AT  ,KC_HASH,KC_PIPE

#define ________________SYM_R1_________________________ _______,_______,_______,_______,_______,_______
#define ________________SYM_R2_________________________ _______,KC_LCTL,KC_LSFT,KC_LALT,KC_LGUI,TD_LAYR
#define ________________SYM_R3_________________________ _______,DF_SYM ,_______,_______,_______,_______


#define ________________FN_L1__________________________ KC_SLEP,KC_F12 ,KC_F7  ,KC_F8  ,KC_F9  ,KC_SLCK
#define ________________FN_L2__________________________ _______,KC_F11 ,KC_F4  ,KC_F5  ,KC_F6  ,KC_PSCR
#define ________________FN_L3__________________________ KC_PWR ,KC_F10 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_PAUS

#define ________________FN_R1__________________________ _______,_______,_______,_______,_______,_______
#define ________________FN_R2__________________________ _______,KC_LCTL,KC_LSFT,KC_LALT,KC_LGUI,TD_LAYR
#define ________________FN_R3__________________________ _______,DF_FN  ,_______,_______,_______,_______


#define ________________NAV_L1_________________________ RESET  ,_______,_______,_______,_______,_______
#define ________________NAV_L2_________________________ TD_LAYR,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______
#define ________________NAV_L3_________________________ _______,_______,_______,_______,DF_NAV ,_______

#define ________________NAV_R1_________________________ REDO   ,COPY   ,PASTE  ,CUT    ,UNDO   ,_______
#define ________________NAV_R2_________________________ KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_CAPS,_______
#define ________________NAV_R3_________________________ KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_INS ,_______


#define ________________MDA_L1_________________________ RESET  ,_______,_______,_______,_______,_______
#define ________________MDA_L2_________________________ TD_LAYR,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______
#define ________________MDA_L3_________________________ _______,_______,_______,_______,DF_MDIA,_______

#define ________________MDA_R1_________________________ _______,_______,_______,_______,_______,_______
#define ________________MDA_R2_________________________ KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,_______,_______
#define ________________MDA_R3_________________________ TG_MIC ,_______,_______,_______,_______,_______


#define ________________MOS_L1_________________________ RESET  ,_______,_______,_______,_______,_______
#define ________________MOS_L2_________________________ TD_LAYR,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______
#define ________________MOS_L3_________________________ _______,_______,_______,_______,DF_MOUS,_______

#define ________________MOS_R1_________________________ _______,KC_ACL0,KC_ACL1,KC_ACL2,_______,_______
#define ________________MOS_R2_________________________ KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______
#define ________________MOS_R3_________________________ KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______,_______


#define TB_CMLL MDA_DEL
#define TB_CMLC NAV_BSP
#define TB_CMLR MOU_TAB

#define TB_CMRL FN_ENTR
#define TB_CMRC NUM_SPC
#define TB_CMRR SYM_ESC


// TODO: Tapdace one of these keys to move out of gaming layer so only need left side active
#define TB_GMLL KC_M
#define TB_GMLC KC_SPC
#define TB_GMLR KC_I

#define TB_GMRL KC_ENT
#define TB_GMRC KC_BSPC
#define TB_GMRR KC_DEL


#define TB_NMLL KC_DOT
#define TB_NMLC KC_0
#define TB_NMLR KC_MINS

#define TB_NMRL _______
#define TB_NMRC DF_BASE
#define TB_NMRR _______


#define TB_SYLL KC_LPRN
#define TB_SYLC KC_RPRN
#define TB_SYLR KC_UNDS

#define TB_SYRL _______
#define TB_SYRC _______
#define TB_SYRR DF_BASE


#define TB_FNLL KC_DEL
#define TB_FNLC KC_BSPC
#define TB_FNLR KC_TAB

#define TB_FNRL DF_BASE
#define TB_FNRC _______
#define TB_FNRR _______


#define TB_NVLL _______
#define TB_NVLC DF_BASE
#define TB_NVLR _______

#define TB_NVRL KC_ENT
#define TB_NVRC KC_SPC
#define TB_NVRR KC_ESC


#define TB_MDLL DF_BASE
#define TB_MDLC _______
#define TB_MDLR _______

#define TB_MDRL KC_MSTP
#define TB_MDRC KC_MPLY
#define TB_MDRR KC_MUTE


#define TB_MOLL _______
#define TB_MOLC _______
#define TB_MOLR DF_BASE

#define TB_MORL KC_BTN3
#define TB_MORC KC_BTN1
#define TB_MORR KC_BTN2

