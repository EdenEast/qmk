// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "edeneast.h"
#include "features/layer_lock.h"

#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#define MO_NAV MO(_NAV)
#define SYM_MIN LT(_SYMBOL, KC_MINS)
#define SYM_TAB LT(_SYMBOL, KC_TAB)
#define LOW_PDN LT(_LOWER, KC_PGDN)
#define OSL_CSE OSM(MOD_LSFT)
#define OSR_CSE OSM(MOD_RSFT)

#define HMA_D LT(_RAISE, KC_D)

enum keymap_keycodes {
  TG_SETT = NEW_SAFE_RANGE, // Toggle settings
  BOOT,
  TG_PLAM,
  GM_PLAM,
  ED_COLN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_WRAPPER(
    _______, __NUMBER_LEFT______________________________,                                         __NUMBER_RIGHT_____________________________, _______,
    KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
    CTR_ESC, HMA_A,   HMA_R,   HMA_S,   HMA_T,   KC_G,                                            KC_M,    HMA_N,   HMA_E,   HMA_I,   HMA_O,   CTR_QOT,
    ED_COLN, KC_Z,    KC_X,    KC_C,    HMA_D,   KC_V,                                            KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, HM_ENT,

    MO_NAV,           KC_LBRC, KC_RBRC, SYM_TAB, KC_BSPC, OSL_CSE, QK_LEAD,     QK_LEAD, OSL_CSE, KC_SPC,  SYM_MIN, KC_UNDS, KC_BSLS,          MO_NAV,
                                        KC_LEFT, KC_PGUP, KC_RGHT,                       KC_LEFT, KC_UP,   KC_RGHT,
                                                 LOW_PDN,                                         KC_DOWN

  ),

  [_SYMBOL] = LAYOUT_WRAPPER(

    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, KC_LABK, KC_RABK, KC_AT,   UP_DIR,                                          KC_AMPR, _______, KC_LBRC, KC_RBRC, _______, KC_F12,
    _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH,                                         KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, KC_DQT,
    _______, KC_BSLS, KC_SLSH, KC_ASTR, KC_CIRC, DB_QUOT,                                         KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, _______, _______,

    _______,          _______, _______, _______, _______, _______, LLOCK,         LLOCK, _______, _______, _______, _______, _______,          _______,
                                        _______, _______, _______,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_NAV] =  LAYOUT_WRAPPER(
    __NAVIGATION_L0_____________________________________,                                         __NAVIGATION_R0_____________________________________,
    __NAVIGATION_L1_____________________________________,                                         __NAVIGATION_R1_____________________________________,
    __NAVIGATION_L2_____________________________________,                                         __NAVIGATION_R2_____________________________________,
    __NAVIGATION_L3_____________________________________,                                         __NAVIGATION_R3_____________________________________,

    _______,          _______, _______, _______, _______,  KC_SPC, LLOCK,         LLOCK, _______, _______, _______, _______, _______,          _______,
                                        KC_LEFT, KC_UP,   KC_RGHT,                       KC_MPRV, _______, KC_MNXT,
                                                 KC_DOWN,                                         KC_MPLY
  ),

  [_RAISE] =  LAYOUT_WRAPPER(
    _______, _______, _______, _______, _______, _______,                                         KC_TILD, KC_CIRC, KC_HASH, KC_DLR,  KC_AT,   KC_EXLM,
    _______, _______, _______, _______, _______, _______,                                         KC_PERC, KC_7,    KC_8,    KC_9,    KC_COLN, KC_LT,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                         KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, KC_GT,
    _______, _______, _______, _______, _______, _______,                                         KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_EQL,

    _______,          _______, _______, KC_COMM, _______, _______, LLOCK,         LLOCK, KC_DOT,  KC_SPC,  KC_0,    KC_LPRN, KC_RPRN,          _______,
                                        _______, _______, _______,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_ADJ] = LAYOUT_WRAPPER(
    __ADJUSTMENT_L0_____________________________________,                                         __ADJUSTMENT_R0_____________________________________,
    __ADJUSTMENT_L1_____________________________________,                                         __ADJUSTMENT_R1_____________________________________,
    __ADJUSTMENT_L2_____________________________________,                                         __ADJUSTMENT_R2_____________________________________,
    __ADJUSTMENT_L3_____________________________________,                                         __ADJUSTMENT_R3_____________________________________,

    _______,          _______, _______, _______, KC_DEL,  OSL_CSE, LLOCK,         LLOCK, _______, _______, _______, _______, _______,          _______,
                                        KC_CLMK, KC_ENGM, TL_GAME,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_GAME] = LAYOUT_WRAPPER(
    _______, __NUMBER_LEFT______________________________,                                         __NUMBER_RIGHT_____________________________, _______,
    __GAME_L1___________________________________________,                                         __GAME_R1___________________________________________,
    __GAME_L2___________________________________________,                                         __GAME_R2___________________________________________,
    __GAME_L3___________________________________________,                                         __GAME_R3___________________________________________,


    GM_PLAM,          KC_T,    KC_G,    KC_I,    KC_SPC,  KC_M,    KC_N,        _______, _______, KC_BSPC, _______, _______, _______,          _______,
                                       KC_MPLY, TG_PLAM, TL_GAME,                       _______, _______, _______,
                                                 MUTE_MIC,                                       _______
  ),

  [_LOWER] = LAYOUT_WRAPPER(
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_WH_D, KC_WH_U, _______,                                         _______, _______, _______, _______, _______, _______,


    _______,          _______, _______, KC_BTN2, KC_BTN1, KC_BTN3, LLOCK,       LLOCK,   _______, _______, _______, _______, _______,          _______,
                                        _______, _______, _______,                       _______, _______, _______,
                                                 _______,                                         _______
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

static bool     game_use_alt_palm = false;
static uint16_t last_game_plam    = 0;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  const uint8_t mods       = get_mods();
  const uint8_t all_mods   = (mods | get_weak_mods() | get_oneshot_mods());
  const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;

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

    case SYM_MIN:
      if (record->tap.count) {
        if (record->event.pressed) {
          clear_weak_mods();
          clear_mods();
          tap_code16(shift_mods ? KC_MINS : KC_UNDS);
          set_mods(mods);
        }
        return false;
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

    case ED_COLN: {
      static bool registered = false;
      if (record->event.pressed) {
        if (registered) {
          unregister_code16(KC_COLN);
        } else if (shift_mods) {
          clear_mods();
          SEND_STRING_DELAY("std:", TAP_CODE_DELAY);
          set_mods(mods);
        }
        register_code16(KC_COLN);
        registered = true;
      } else {
        unregister_code16(KC_COLN);
        registered = false;
      }
    }
      return false;

    default:
      return true;
  }
}

bool achordion_chord_keymap(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  switch (tap_hold_keycode) {
    case SYM_TAB:
    case SYM_MIN:
    case LOW_PDN:
    case HMA_Z:
    case HMA_D:
    case OSL_CSE:
      return true;
  }
  return false;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
  // Handle layer locking with tri layers (for ADJ layer)
  // https://github.com/getreuer/qmk-keymap/issues/61#issuecomment-2045770839
  if (!is_layer_locked(_ADJ)) {
    state = update_tri_layer_state(state, _NAV, _SYMBOL, _ADJ);
  }
  return state;
}
