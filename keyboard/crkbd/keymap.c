#include "edeneast.h"
#include QMK_KEYBOARD_H

// clang-format off
#define LAYOUT_WRAPPER(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_base( \
    k01, k02, k03, k04, k05, k06,     k07, k08, k09, k0A, k0B, k0C, \
    k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1A, k1B, k1C, \
    k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2A, k2B, k2C  \
  ) \
  LAYOUT_WRAPPER ( \
    k01, k02, k03, k04, k05, k06,     k07, k08, k09, k0A, k0B, k0C, \
    k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1A, k1B, k1C, \
    k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2A, k2B, k2C, \
    _______, LOW_TAB, SFT_BSP, SFT_SPC, RAS_MIN, _______ \
  )

#define LAYOUT_base_wrapper(...)       LAYOUT_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_base_wrapper(
    __COLEMAK_DH_L1_____________________________________, __COLEMAK_DH_R1_____________________________________,
    __COLEMAK_DH_L2_____________________________________, __COLEMAK_DH_R2_____________________________________,
    __COLEMAK_DH_L3_____________________________________, __COLEMAK_DH_R3_____________________________________
  ),

  [_LOWER] = LAYOUT_base_wrapper(
    __LOWER_L1__________________________________________, __LOWER_R1__________________________________________,
    __LOWER_L2__________________________________________, __LOWER_R2__________________________________________,
    __LOWER_L3__________________________________________, __LOWER_R3__________________________________________
  ),

  [_RAISE] = LAYOUT_base_wrapper(
    __RAISE_L1__________________________________________, __RAISE_R1__________________________________________,
    __RAISE_L2__________________________________________, __RAISE_R2__________________________________________,
    __RAISE_L3__________________________________________, __RAISE_R3__________________________________________
  ),

  [_ADJ] = LAYOUT_base_wrapper(
    __ADJUST_L1_________________________________________, __ADJUST_R1_________________________________________,
    __ADJUST_L2_________________________________________, __ADJUST_R2_________________________________________,
    __ADJUST_L3_________________________________________, __ADJUST_R3_________________________________________
  ),

  [_GAME] = LAYOUT_WRAPPER(
    __GAME_L1___________________________________________,                            __GAME_R1___________________________________________,
    __GAME_L2___________________________________________,                            __GAME_R2___________________________________________,
    __GAME_L3___________________________________________,                            __GAME_R3___________________________________________,
                                        KC_M,    KC_I,    KC_SPC,           KC_BSPC, KC_ENT,  KC_DEL
  ),

#ifdef STENO_ENABLE
  [_STENO] = LAYOUT_WRAPPER(
    __STENO_L1__________________________________________,                            __STENO_R1__________________________________________,
    __STENO_L2__________________________________________,                            __STENO_R2__________________________________________,
    __STENO_L3__________________________________________,                            __STENO_R3__________________________________________,
                                        _______, STN_A,   STN_O,            STN_E,   STN_U,   _______
  ),
  #endif

};

    // _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //                                     _______, _______, _______,          _______, _______, _______

// clang-format on
