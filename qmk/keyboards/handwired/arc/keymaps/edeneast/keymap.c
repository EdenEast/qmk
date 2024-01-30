// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "edeneast.h"

#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#define MO_NAV MO(_NAV)
#define SYM_MIN LT(_SYMBOL, KC_MINS)
#define SYM_TAB LT(_SYMBOL, KC_TAB)
#define OSL_CSE OSM(MOD_LSFT)
#define OSR_CSE OSM(MOD_RSFT)

enum keymap_keycodes {
  TG_SETT = NEW_SAFE_RANGE, // Toggle settings
  BOOT,
  TG_PLAM,
  GM_PLAM,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_WRAPPER(
    _______, __NUMBER_OPT_LEFT__________________________,                                         __NUMBER_OPT_RIGHT_________________________, _______,
    __COLEMAK_DH_L1_____________________________________,                                         __COLEMAK_DH_R1_____________________________________,
    __COLEMAK_DH_L2_____________________________________,                                         __COLEMAK_DH_R2_____________________________________,
    __COLEMAK_DH_L3_____________________________________,                                         __COLEMAK_DH_R3_____________________________________,

    // MO_NAV,           KC_LBRC, KC_RBRC, OSL_CSE, KC_BSPC, SYM_TAB, STCK_LY,     STCK_LY, SYM_MIN, KC_SPC,  OSR_CSE, KC_LPRN, KC_RPRN,          MO_NAV,
    MO_NAV,           KC_LBRC, KC_RBRC, SYM_TAB, KC_BSPC, OSL_CSE, STCK_LY,     STCK_LY, OSR_CSE, KC_SPC,  SYM_MIN, KC_LPRN, KC_RPRN,          MO_NAV,
                                        KC_ENGM, KC_PGUP, TL_GAME,                       KC_LEFT, KC_UP,   KC_RGHT,
                                                 KC_PGDN,                                         KC_DOWN

  ),

  [_ENGRAM] = LAYOUT_WRAPPER(
    TL_ENGM, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    __ENGRAM_L1_________________________________________,                                         __ENGRAM_R1_________________________________________,
    __ENGRAM_L2_________________________________________,                                         __ENGRAM_R2_________________________________________,
    __ENGRAM_L3_________________________________________,                                         __ENGRAM_R3_________________________________________,

    // MO_NAV,           KC_LBRC, KC_RBRC, OSL_CSE, KC_BSPC, SYM_TAB, STCK_LY,     STCK_LY, SYM_MIN, KC_SPC,  OSR_CSE, KC_LPRN, KC_RPRN,          MO_NAV,
    MO_NAV,           KC_LBRC, KC_RBRC, SYM_TAB, KC_BSPC, OSL_CSE, STCK_LY,     STCK_LY, OSR_CSE, KC_SPC,  SYM_MIN, KC_LPRN, KC_RPRN,          MO_NAV,
                                        KC_CLMK, KC_PGUP, TL_GAME,                       KC_LEFT, KC_UP,   KC_RGHT,
                                                 KC_PGDN,                                         KC_DOWN
  ),

  [_SYMBOL] = LAYOUT_WRAPPER(
    __SYMBOL_L0_________________________________________,                                         __SYMBOL_R0_________________________________________,
    __SYMBOL_L1_________________________________________,                                         __SYMBOL_R1_________________________________________,
    __SYMBOL_L2_________________________________________,                                         __SYMBOL_R2_________________________________________,
    __SYMBOL_L3_________________________________________,                                         __SYMBOL_R3_________________________________________,

    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
                                        _______, _______, _______,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_NAV] =  LAYOUT_WRAPPER(
    __NAVIGATION_L0_____________________________________,                                         __NAVIGATION_R0_____________________________________,
    __NAVIGATION_L1_____________________________________,                                         __NAVIGATION_R1_____________________________________,
    __NAVIGATION_L2_____________________________________,                                         __NAVIGATION_R2_____________________________________,
    __NAVIGATION_L3_____________________________________,                                         __NAVIGATION_R3_____________________________________,

    _______,          _______, _______, KC_SPC,  _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
                                        KC_LEFT, KC_UP,   KC_RGHT,                       KC_MPRV, _______, KC_MNXT,
                                                 KC_DOWN,                                         KC_MPLY
  ),

  [_ADJ] = LAYOUT_WRAPPER(
    __ADJUSTMENT_L0_____________________________________,                                         __ADJUSTMENT_R0_____________________________________,
    __ADJUSTMENT_L1_____________________________________,                                         __ADJUSTMENT_R1_____________________________________,
    __ADJUSTMENT_L2_____________________________________,                                         __ADJUSTMENT_R2_____________________________________,
    __ADJUSTMENT_L3_____________________________________,                                         __ADJUSTMENT_R3_____________________________________,

    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
                                        _______, _______, TL_GAME,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_GAME] = LAYOUT_WRAPPER(
    _______, __NUMBER_LEFT______________________________,                                         __NUMBER_RIGHT_____________________________, _______,
    __GAME_L1___________________________________________,                                         __GAME_R1___________________________________________,
    __GAME_L2___________________________________________,                                         __GAME_R2___________________________________________,
    __GAME_L3___________________________________________,                                         __GAME_R3___________________________________________,


    GM_PLAM,          KC_T,    KC_G,    KC_I,    KC_SPC,  KC_M,    _______,     _______, _______, KC_BSPC, _______, _______, _______,          _______,
                                       KC_MPLY, TG_PLAM, TL_GAME,                       _______, _______, _______,
                                                 MUTE_MIC,                                       _______
  ),

};

    // _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    // _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    //
    // _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
    //                                     _______, _______, _______,                       _______, _______, _______,
    //                                              _______,                                         _______

// clang-format on
static bool game_use_alt_palm = false;
static uint16_t last_game_plam = 0;
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case OSL_CSE:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        set_smart_case_for_mods();
        return false;
      }
    }
    record->event.pressed ? add_mods(MOD_LSFT) : unregister_mods(MOD_LSFT);
    return false;
  case OSR_CSE:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        set_smart_case_for_mods();
        return false;
      }
    }
    record->event.pressed ? add_mods(MOD_RSFT) : unregister_mods(MOD_RSFT);
    return false;

  case SYM_MIN:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(KC_MINS);
        //   uint8_t mods = get_mods();
        //   bool is_shift_held =
        //       (mods | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
        //   uint16_t key = is_shift_held ? KC_MINS : KC_UNDS;
        //   del_weak_mods(MOD_MASK_SHIFT);
        //   del_oneshot_mods(MOD_MASK_SHIFT);
        //   unregister_mods(MOD_MASK_SHIFT);
        //   tap_code16(key);
        //   set_mods(mods);
        //   return false;
      }
    }
    record->event.pressed ? layer_on(_SYMBOL) : layer_off(_SYMBOL);
    return false;

  case TG_PLAM:
    if (record->event.pressed) {
      game_use_alt_palm = !game_use_alt_palm;
    }
    return false;

  case GM_PLAM:
    if (record->event.pressed) {
      last_game_plam = game_use_alt_palm ? KC_LALT : KC_LCTL;
      register_code16(last_game_plam);
    } else {
      unregister_code16(last_game_plam);
    }
    return false;

  default:
    return true;
  }
}

layer_state_t layer_state_set_kb(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYMBOL, _ADJ);
}
