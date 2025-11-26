// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "edeneast.h"

#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#define MO_NAV MO(_NAV)
#define SYM_MIN LT(_SYMBOL, KC_MINS)
#define SYM_TAB LT(_SYMBOL, KC_TAB)
#define LOW_PDN LT(_LOWER, KC_PGDN)
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
    _______, __NUMBER_LEFT______________________________,                                         __NUMBER_RIGHT_____________________________, _______,
    KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
    CTR_ESC, HMA_A,   HMA_R,   HMA_S,   HMA_T,   KC_G,                                            KC_M,    HMA_N,   HMA_E,   HMA_I,   HMA_O,   CTR_QOT,
    HM_MUX,  HMA_Z,   KC_X,    KC_C,    KC_D,    KC_V,                                            KC_K,    KC_H,    KC_COMM, KC_DOT,  HMA_SLSH,HM_ENT,

    MO_NAV,           KC_LBRC, KC_RBRC, SYM_TAB, KC_BSPC, OSL_CSE, QK_LEAD,     QK_LEAD, OSL_CSE, KC_SPC,  SYM_MIN, KC_UNDS, KC_BSLS,          MO_NAV,
                                        KC_LEFT, KC_PGUP, KC_RGHT,                       KC_LEFT, KC_UP,   KC_RGHT,
                                                 LOW_PDN,                                         KC_DOWN
  ),

  KC_BSLS


  // [_ENGRAM] = LAYOUT_WRAPPER(
  //   _______, __NUMBER_LEFT______________________________,                                         __NUMBER_RIGHT_____________________________, _______,
  //   KC_GRV,  KC_B,    KC_Y,    KC_O,    KC_U,    KC_QUOT,                                         KC_SCLN, KC_L,    KC_D,    KC_W,    KC_V,    KC_Z,
  //   CTR_ESC, HME_C,   HME_I,   HME_E,   HME_A,   KC_COMM,                                         KC_DOT,  HME_H,   HME_T,   HME_S,   HME_N,   KC_Q,
  //   HM_MUX,  KC_G,    KC_X,    KC_J,    KC_K,    KC_EQL,                                          KC_SLSH, KC_R,    KC_M,    KC_F,    KC_P,    HM_ENT,

  //   MO_NAV,           KC_LBRC, KC_RBRC, SYM_TAB, KC_BSPC, OSL_CSE, QK_LEAD,     QK_LEAD, OSL_CSE, KC_SPC,  SYM_MIN, KC_LPRN, KC_RPRN,          MO_NAV,
  //                                       KC_LEFT, KC_PGUP, KC_RGHT,                       KC_LEFT, KC_UP,   KC_RGHT,
  //                                                LOW_PDN,                                         KC_DOWN
  // ),

  [_SYMBOL] = LAYOUT_WRAPPER(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                                         KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  _______, KC_F12,
    _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                                         KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQT,  _______,
    _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                                         KC_AT,   KC_COLN, _______, _______, _______, _______,

    _______,          _______, _______, _______, _______, _______, QK_LLCK,     QK_LLCK, _______, _______, _______, _______, _______,          _______,
                                        _______, _______, _______,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_NAV] =  LAYOUT_WRAPPER(
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,

    _______,          _______, _______, _______, _______,  KC_SPC, QK_LLCK,     QK_LLCK, _______, _______, _______, _______, _______,          _______,
                                        KC_LEFT, KC_UP,   KC_RGHT,                       KC_MPRV, _______, KC_MNXT,
                                                 KC_DOWN,                                         KC_MPLY
  ),

  [_RAISE] =  LAYOUT_WRAPPER(
    _______, _______, _______, _______, _______, _______,                                         KC_TILD, KC_CIRC, KC_HASH, KC_DLR,  KC_AT,   KC_EXLM,
    _______, _______, _______, _______, _______, _______,                                         KC_PERC, KC_7,    KC_8,    KC_9,    KC_COLN, KC_LT,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                         KC_PLUS, KC_4,    KC_5,    KC_6,    KC_MINS, KC_GT,
    _______, _______, _______, _______, _______, _______,                                         KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_EQL,

    _______,          _______, _______, KC_COMM, _______, _______, QK_LLCK,     QK_LLCK, KC_DOT,  KC_SPC,  KC_0,    KC_LPRN, KC_RPRN,          _______,
                                        _______, _______, _______,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_ADJ] = LAYOUT_WRAPPER(
    QK_BOOT, KC_MAKE, KC_CAPS, KC_ESC,  _______, _______,                                         _______, _______, _______, _______, KC_MAKE, QK_BOOT,
    OS_RST,  OS_MAC,  OS_WIN,  _______, _______, _______,                                         _______,   VB_UP, VB_DOWN, KC_MUTE, _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                         _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
    _______, ED_UNDO, ED_CUT, ED_COPY, ED_PASTE, KC_PSCR,                                         _______, MUTE_MIC, _______, _______, TG_SENT, _______,

    _______,          _______, _______, _______, KC_DEL,  OSL_CSE, QK_LLCK,     QK_LLCK, _______, _______, _______, _______, _______,          _______,
                                        KC_CLMK, KC_ENGM, TL_GAME,                       _______, _______, _______,
                                                 _______,                                         _______
  ),

  [_GAME] = LAYOUT_WRAPPER(
    _______, __NUMBER_LEFT______________________________,                                         __NUMBER_RIGHT_____________________________, _______,
    KC_GRV,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                                            KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                                            KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TL_GAME,
    KC_LALT, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                                            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,

    GM_PLAM,          KC_T,    KC_G,    KC_I,    KC_SPC,  KC_M,    KC_N,        _______, _______, KC_BSPC, _______, _______, _______,          _______,
                                       KC_MPLY, TG_PLAM, TL_GAME,                       _______, _______, _______,
                                                 MUTE_MIC,                                       _______
  ),

  [_LOWER] = LAYOUT_WRAPPER(
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, MS_BTN2, MS_UP,   MS_BTN1, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,                                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, MS_WHLD, MS_WHLU, _______,                                         _______, _______, _______, _______, _______, _______,

    _______,          _______, _______, MS_BTN2, MS_BTN1, MS_BTN3, QK_LLCK,     QK_LLCK, _______, _______, _______, _______, _______,          _______,
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
      if (record->tap.count > 0) {
        if (record->event.pressed) tap_code16(KC_MINS);
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

bool achordion_chord_keymap(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  switch (tap_hold_keycode) {
    case SYM_TAB:
    case SYM_MIN:
    case LOW_PDN:
    case HMA_SLSH:
    case HMA_Z:
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

#ifdef CHORDAL_HOLD
// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
    '*', '*', '*', '*', '*', '*',                         '*', '*', '*', '*', '*', '*',
    '*', 'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R', '*',
    '*', 'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R', '*',
    '*', 'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R', '*',
    '*',      '*', '*', '*', '*', '*', '*',     '*', '*', '*', '*', '*', '*',      '*',
                        '*', '*', '*',               '*', '*', '*',
                             '*',                         '*'
    );
// clang-format on
// Callback for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
/**
 * @Brief Per-chord customization
 *
 * Decide the outcome of tap-hold key depending on the other key pressed.
 * When return is true the tap-hold key is concidered held, else it is
 * determined to be both tapped.
 *
 * @paran tap_hold_keycode Key to be decided if key is tapped of held
 * @paran tap_hold_record The matrix information for the tap hold key
 * @paran other_keycode The other key that will determine the state of the
 * tap_hold key
 * @paran other_record The matrix information for the other key
 * @return true considered tap-hold, false considered both tap keys
 */
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  switch (tap_hold_keycode) {
    case HMA_A:
      switch (other_keycode) {
        // Allow one handed cmd + key combos on mac
        case KC_C:
        case KC_V:
          return true;
      }
      break;
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif
