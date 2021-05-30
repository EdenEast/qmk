#include "edeneast.h"
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT_split_3x6_3_WRAPPER (
        ________________COLEMAK_DH_L1__________________,                        ________________COLEMAK_DH_R1__________________,
        ________________COLEMAK_DH_L2__________________,                        ________________COLEMAK_DH_R2__________________,
        ________________COLEMAK_DH_L3__________________,                        ________________COLEMAK_DH_R3__________________,
                                        TB_LDF3,TB_LDF1,TB_LDF2,        TB_RDF2,TB_RDF1,TB_RDF3
    ),

    [_QWERTY] = LAYOUT_split_3x6_3_WRAPPER (
        __________________QWERTY_L1____________________,                        __________________QWERTY_R1____________________,
        __________________QWERTY_L2____________________,                        __________________QWERTY_R2____________________,
        __________________QWERTY_L3____________________,                        __________________QWERTY_R3____________________,
                                        TB_LDF3,TB_LDF1,TB_LDF2,        TB_RDF2,TB_RDF1,TB_RDF3
    ),

    [_GAME] = LAYOUT_split_3x6_3_WRAPPER (
        ___________________GAME_L1_____________________,                        ___________________GAME_R1_____________________,
        ___________________GAME_L2_____________________,                        ___________________GAME_R2_____________________,
        ___________________GAME_L3_____________________,                        ___________________GAME_R3_____________________,
                                        TB_GMLL,TB_GMLC,TB_GMLR,        TB_GMRL,TB_GMRC,TB_GMRR
    ),

    [_SYM] = LAYOUT_split_3x6_3_WRAPPER (
        __________________SYMBOLS_L1___________________,                        __________________SYMBOLS_R1___________________,
        __________________SYMBOLS_L2___________________,                        __________________SYMBOLS_R2___________________,
        __________________SYMBOLS_L3___________________,                        __________________SYMBOLS_R3___________________,
                                        TB_LSM3,TB_LSM1,TB_LSM2,        TB_RSM2,TB_RSM1,TB_RSM3
    ),

    [_NAV] = LAYOUT_split_3x6_3_WRAPPER (
        _________________NAVIGATION_L1_________________,                        _________________NAVIGATION_R1_________________,
        _________________NAVIGATION_L2_________________,                        _________________NAVIGATION_R2_________________,
        _________________NAVIGATION_L3_________________,                        _________________NAVIGATION_R3_________________,
                                        TB_LNV3,TB_LNV1,TB_LNV2,        TB_RNV2,TB_RNV1,TB_RNV3
    ),

    [_FUNC] = LAYOUT_split_3x6_3_WRAPPER (
        _________________FUNCTION_L1___________________,                        _________________FUNCTION_R1___________________,
        _________________FUNCTION_L2___________________,                        _________________FUNCTION_R2___________________,
        _________________FUNCTION_L3___________________,                        _________________FUNCTION_R3___________________,
                                        TB_LFN3,TB_LFN1,TB_LFN2,        TB_RFN2,TB_RFN1,TB_RFN3
    ),
};

