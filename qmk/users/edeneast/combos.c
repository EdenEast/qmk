#include "edeneast.h"

enum combos {
  COMBO_LEFT_BOOT,
  COMBO_RGHT_BOOT,
  COMBO_SINGLE_BOOT,
  COMBO_LEFT_COMPILE,
  COMBO_RGHT_COMPILE,
  COMBO_SINGLE_COMPILE,
  COMBO_BSPC_HOLD,
  COMBO_SPC_HOLD,
  COMBO_COPY,
  COMBO_PASTE,
  COMBO_CAP_WORD,
  COMBO_LPRN_RPRN, /* (|) */
  COMBO_LBRC_RBRC, /* [|] */
  COMBO_LCBR_RCBR, /* {|} */
  // COMBO_LT_GT,     /* <|> */
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_left_boot[] = {TD_GRV, KC_B, COMBO_END};
const uint16_t PROGMEM combo_rght_boot[] = {KC_J, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_single_boot[] = {KC_BSPC, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_left_compile[] = {TD_GRV, KC_P, COMBO_END};
const uint16_t PROGMEM combo_rght_compile[] = {KC_L, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_single_compile[] = {KC_BSPC, KC_0, COMBO_END};
const uint16_t PROGMEM combo_bspc_hold[] = {KC_DEL, SFT_BSP, COMBO_END};
const uint16_t PROGMEM combo_spc_hold[] = {KC_ENT, SFT_SPC, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_cap_word[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM combo_lprn_rprn[] = {HM_LPRN, HM_RPRN, COMBO_END};
const uint16_t PROGMEM combo_lbrc_rbrc[] = {KC_LBRC, HM_RBRC, COMBO_END};
const uint16_t PROGMEM combo_lcbr_rcbr[] = {KC_LCBR, KC_RCBR, COMBO_END};
// const uint16_t PROGMEM combo_lt_gt[] = {KC_LT, KC_GT, COMBO_END};

combo_t key_combos[] = {
    [COMBO_LEFT_BOOT] = COMBO(combo_left_boot, QK_BOOT),
    [COMBO_RGHT_BOOT] = COMBO(combo_rght_boot, QK_BOOT),
    [COMBO_SINGLE_BOOT] = COMBO(combo_single_boot, QK_BOOT),

    [COMBO_LEFT_COMPILE] = COMBO(combo_left_compile, QK_MAKE),
    [COMBO_RGHT_COMPILE] = COMBO(combo_rght_compile, QK_MAKE),
    [COMBO_SINGLE_COMPILE] = COMBO(combo_single_compile, QK_MAKE),

    [COMBO_BSPC_HOLD] = COMBO(combo_bspc_hold, KC_BSPC),
    [COMBO_SPC_HOLD] = COMBO(combo_spc_hold, KC_SPC),

    [COMBO_COPY] = COMBO(combo_copy, ED_COPY),
    [COMBO_PASTE] = COMBO(combo_paste, ED_PASTE),

    [COMBO_CAP_WORD] = COMBO(combo_cap_word, QK_CAPS_WORD_TOGGLE),

    [COMBO_LPRN_RPRN] = COMBO_ACTION(combo_lprn_rprn),
    [COMBO_LPRN_RPRN] = COMBO_ACTION(combo_lprn_rprn),
    [COMBO_LBRC_RBRC] = COMBO_ACTION(combo_lbrc_rbrc),
    [COMBO_LCBR_RCBR] = COMBO_ACTION(combo_lcbr_rcbr),
    // [COMBO_LT_GT] = COMBO_ACTION(combo_lt_gt),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  uint8_t mods = get_mods();
  switch (combo_index) {
  case COMBO_LPRN_RPRN:
    if (pressed) {
      tap_code16(KC_LPRN);
      tap_code16(KC_RPRN);
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_LEFT);
      set_mods(mods);
    }
    break;
  case COMBO_LBRC_RBRC:
    if (pressed) {
      tap_code16(KC_LBRC);
      tap_code16(KC_RBRC);
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_LEFT);
      set_mods(mods);
    }
    break;
  case COMBO_LCBR_RCBR:
    if (pressed) {
      tap_code16(KC_LCBR);
      tap_code16(KC_RCBR);
      del_mods(MOD_MASK_SHIFT);
      tap_code16(KC_LEFT);
      set_mods(mods);
    }
    break;
    // case COMBO_LT_GT:
    //   if (pressed) {
    //     tap_code16(KC_LT);
    //     tap_code16(KC_GT);
    //     del_mods(MOD_MASK_SHIFT);
    //     tap_code16(KC_LEFT);
    //     set_mods(mods);
    //   }
    //   break;
  }
}
