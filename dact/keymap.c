#include "edeneast.h"
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base (Colemak-DH) https://colemakmods.github.io/mod-dh/keyboards.html#matrix-keyboards
[_COLEMAK_DH] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    _________________COLEMAK_DH_L1_________________,                        _________________COLEMAK_DH_R1_________________, \
    _________________COLEMAK_DH_L2_________________,                        _________________COLEMAK_DH_R2_________________, \
    _________________COLEMAK_DH_L3_________________,                        _________________COLEMAK_DH_R3_________________, \
                    KC_DOWN,KC_UP  ,                                                        KC_LEFT,KC_RGHT,                 \
                                    TB_LDF2,TB_LDF1,                        TB_RDF1,TB_RDF2,                                 \
                                            _______,TB_LDF3,        TB_RDF3,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_GAME] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    ____________________GAME_L1____________________,                        ____________________GAME_R1____________________, \
    ____________________GAME_L2____________________,                        ____________________GAME_R2____________________, \
    ____________________GAME_L3____________________,                        ____________________GAME_R3____________________, \
                    KC_T   ,KC_G   ,                                                        _______,_______,                 \
                                    TB_GMLL,TB_GMLC,                        TB_GMRC,TB_GMRR,                                 \
                                            _______,TB_GMLR,        TB_GMRL,OS_RSFT,                                         \
                                            KC_PAUS,KC_F2  ,        _______,_______                                          \
),

[_SYML] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    ________________SYMBOLS_ONE_L1_________________,                        ________________SYMBOLS_ONE_R1_________________, \
    ________________SYMBOLS_ONE_L2_________________,                        ________________SYMBOLS_ONE_R2_________________, \
    ________________SYMBOLS_ONE_L3_________________,                        ________________SYMBOLS_ONE_R3_________________, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_SYMR] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    ________________SYMBOLS_TWO_L1_________________,                        ________________SYMBOLS_TWO_R1_________________, \
    ________________SYMBOLS_TWO_L2_________________,                        ________________SYMBOLS_TWO_R2_________________, \
    ________________SYMBOLS_TWO_L3_________________,                        ________________SYMBOLS_TWO_R3_________________, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_NUM] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    ___________________NUMBER_L1___________________,                        ___________________NUMBER_R1___________________, \
    ___________________NUMBER_L2___________________,                        ___________________NUMBER_R2___________________, \
    ___________________NUMBER_L3___________________,                        ___________________NUMBER_R3___________________, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_FUNC] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    __________________FUNCTION_L1__________________,                        __________________FUNCTION_R1__________________, \
    __________________FUNCTION_L2__________________,                        __________________FUNCTION_R2__________________, \
    __________________FUNCTION_L3__________________,                        __________________FUNCTION_R3__________________, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_ADJ] = LAYOUT_5x6_WRAPPER(
    _______,______________NUMBER_LEFT______________,                        ______________NUMBER_RIGHT_____________,_______, \
    ___________________ADJUST_L1___________________,                        ___________________ADJUST_R1___________________, \
    ___________________ADJUST_L2___________________,                        ___________________ADJUST_R2___________________, \
    ___________________ADJUST_L3___________________,                        ___________________ADJUST_R3___________________, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),
};

// ---------------------------------------------------------------------------------------------------------------------------

/**
 * Layer
 * +-----------------------------------------------+                       +-----------------------------------------------+
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * +---------------+-------+-------+---------------+                       +---------------+-------+-------+---------------+
 *                 |       |       |                                                       |       |       |
 *                 +---------------+---------------+                       +---------------+---------------+
 *                                 |       |       |                       |       |       |
 *                                 +---------------+                       +---------------+
 *                                         +---------------+       +---------------+
 *                                         |       |       |       |       |       |
 *                                         |-------+-------|       |-------+-------|
 *                                         |       |       |       |       |       |
 *                                         +---------------+       +---------------+
 */
/*
[_layer] = LAYOUT_5x6_WRAPPER(
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),
*/
