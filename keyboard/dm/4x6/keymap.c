#include "edeneast.h"

// clang-format off
#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_base( \
    k01, k02, k03, k04, k05, k06,     k07, k08, k09, k0A, k0B, k0C, \
    k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1A, k1B, k1C, \
    k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2A, k2B, k2C  \
  ) \
  LAYOUT_WRAPPER ( \
    k01, k02, k03, k04, k05, k06,     k07, k08, k09, k0A, k0B, k0C, \
    k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1A, k1B, k1C, \
    k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2A, k2B, k2C, \
    KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, \
    SYM_TAB, SFT_BSP, SFT_SPC, NAV_MIN, \
    _______,_______, _______,_______, _______,_______, _______,_______ \
  )

#define LAYOUT_base_wrapper(...)       LAYOUT_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_base_wrapper(
    ___________________COLEMAK_DH_L1____________________, ___________________COLEMAK_DH_R1____________________,
    ___________________COLEMAK_DH_L2____________________, ___________________COLEMAK_DH_R2____________________,
    ___________________COLEMAK_DH_L3____________________, ___________________COLEMAK_DH_R3____________________
  ),

  [_SYM] = LAYOUT_base_wrapper(
    _______________________SYM_L1_______________________, _______________________SYM_R1_______________________,
    _______________________SYM_L2_______________________, _______________________SYM_R2_______________________,
    _______________________SYM_L3_______________________, _______________________SYM_R3_______________________
  ),

  [_NAV] = LAYOUT_base_wrapper(
    _______________________NAV_L1_______________________, _______________________NAV_R1_______________________,
    _______________________NAV_L2_______________________, _______________________NAV_R2_______________________,
    _______________________NAV_L3_______________________, _______________________NAV_R3_______________________
  ),

  [_ADJ] = LAYOUT_base_wrapper(
    _______________________ADJ_L1_______________________, _______________________ADJ_R1_______________________,
    _______________________ADJ_L2_______________________, _______________________ADJ_R2_______________________,
    _______________________ADJ_L3_______________________, _______________________ADJ_R3_______________________
  ),

  [_GAME] = LAYOUT_WRAPPER(
    ______________________GAME_L1_______________________,                         ______________________GAME_R1_______________________,
    ______________________GAME_L2_______________________,                         ______________________GAME_R2_______________________,
    ______________________GAME_L3_______________________,                         ______________________GAME_R3_______________________,
                      KC_T,    KC_G,                                                                _______, _______,
                                        KC_I,     KC_SPC,                         KC_BSPC, KC_ENT,
                                                 TG_MIC,  KC_M,           KC_DEL, OS_RSFT,
                                                 KC_PAUS, KC_F2,          _______, _______
  ),

};

    // _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //                   _______, _______,                                                             _______, _______,
    //                                     _______, _______,                         _______, _______,
    //                                              _______, _______,        _______, _______,
    //                                              _______, _______,        _______, _______

// clang-format on
