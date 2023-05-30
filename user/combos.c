#include "edeneast.h"

enum combos {
  COMBO_LEFT_BOOT,
  COMBO_RGHT_BOOT,
  COMBO_COPY,
  COMBO_PASTE,
  COMBO_LPRN_RPRN, /* (|) */
  COMBO_LBRC_RBRC, /* [|] */
  COMBO_LCBR_RCBR, /* {|} */
  COMBO_LT_GT,     /* <|> */
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_left_boot[] = {KC_GRV, KC_B, COMBO_END};
const uint16_t PROGMEM combo_rght_boot[] = {KC_J, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_lprn_rprn[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM combo_lbrc_rbrc[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM combo_lcbr_rcbr[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM combo_lt_gt[] = {KC_LT, KC_GT, COMBO_END};

combo_t key_combos[] = {
    [COMBO_LEFT_BOOT] = COMBO(combo_left_boot, QK_BOOT),
    [COMBO_RGHT_BOOT] = COMBO(combo_rght_boot, QK_BOOT),

    [COMBO_COPY] = COMBO(combo_copy, COPY),
    [COMBO_PASTE] = COMBO(combo_paste, PASTE),

    [COMBO_LPRN_RPRN] = COMBO_ACTION(combo_lprn_rprn),
    [COMBO_LPRN_RPRN] = COMBO_ACTION(combo_lprn_rprn),
    [COMBO_LBRC_RBRC] = COMBO_ACTION(combo_lbrc_rbrc),
    [COMBO_LCBR_RCBR] = COMBO_ACTION(combo_lcbr_rcbr),
    [COMBO_LT_GT] = COMBO_ACTION(combo_lt_gt),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case COMBO_LPRN_RPRN:
    if (pressed) {
      tap_code16(KC_LPRN);
      tap_code16(KC_RPRN);
      tap_code16(KC_LEFT);
    }
    break;
  case COMBO_LBRC_RBRC:
    if (pressed) {
      tap_code16(KC_LBRC);
      tap_code16(KC_RBRC);
      tap_code16(KC_LEFT);
    }
    break;
  case COMBO_LCBR_RCBR:
    if (pressed) {
      tap_code16(KC_LCBR);
      tap_code16(KC_RCBR);
      tap_code16(KC_LEFT);
    }
    break;
  case COMBO_LT_GT:
    if (pressed) {
      tap_code16(KC_LT);
      tap_code16(KC_GT);
      tap_code16(KC_LEFT);
    }
    break;
  }
}
