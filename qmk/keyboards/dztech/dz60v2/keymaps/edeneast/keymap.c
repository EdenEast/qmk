#include "edeneast.h"
#include "features/sentence_case.h"
#include QMK_KEYBOARD_H

// clang-format off

#define MOR MO(_RAISE)
#define TGG TG(_GAME)
#define MIC MUTE_MIC
#define OSSL OSM(MOD_LSFT)
#define OSSR OSM(MOD_RSFT)

enum keymap_keycodes {
  TG_SETT = NEW_SAFE_RANGE, // Toggle settings
  BOOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/** Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Esc     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |------------------------------^-----------------^----------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     RShift      |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl | Super |  Alt  |   Bkspc   |  Fn  |     Space      | Alt | Lft  | Dwn | Up  | Rgh |
 * `-----------------------------------------------------------------------------------------'
 */

  [_BASE] = LAYOUT_60_ansi_split_arrow(
    TD_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    CTR_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    OSSL,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSSR,
    KC_LCTL, KC_LGUI, TD_LALT,          KC_SPC,  MOR,     KC_SPC,           TD_LALT, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

/** Game
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |------------------------------^-----------------^----------------------------------------+
 * |   Shift   |     |     |     |     |     |     |     |     |     |     |      Shift      |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl | Super |  Alt  |   Space   |      |     Space      |     |      |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */

  [_GAME] = LAYOUT_60_ansi_split_arrow(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,
    _______, _______, KC_LALT,          KC_SPC,  _______, KC_SPC,           KC_LALT, _______, _______, _______, _______
  ),


/** Layer
 * ,-----------------------------------------------------------------------------------------.
 * | Boot|  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   Del     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |  Game  |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     | Left| Down|  Up |Right|     |NxPrv|    Play     |
 * |------------------------------^-----------------^----------------------------------------+
 * |           |     |     |     | Mic |     |     |     |Vol D| Mute|Vol U|                 |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |           |      |                 |     |     |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_60_ansi_split_arrow(
    BOOT,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG_SETT,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, TD_MDNP, KC_MPLY,
    _______,          _______, _______, _______, MIC,     _______, _______, _______, VB_DOWN, KC_MUTE, VB_UP,   _______,
    _______, _______, _______,          _______, _______, _______,          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

/** Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |------------------------------^-----------------^----------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |                 |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |           |      |                |     |      |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */

  // [_BASE] = LAYOUT_60_ansi_split_arrow(
  //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //   _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______
  // ),

};

// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  uint8_t mods = get_mods();
  switch (keycode) {
  case TG_SETT:
    if (record->event.pressed) {
      if (mods & MOD_MASK_SHIFT) {
        sentence_case_toggle();
      } else {
        layer_invert(_GAME);
      }
    }
    return false;
  case BOOT:
    if (record->event.pressed) {
      if ((mods & MOD_MASK_SHIFT) || (mods & MOD_MASK_CTRL)) {
        clear_mods();
        send_make_command(mods & MOD_MASK_SHIFT);
        set_mods(mods);
      } else {
        reset_keyboard();
      }
    }
    return false;
  default:
    return true;
  }
}
