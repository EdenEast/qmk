#include "edeneast.h"

#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif

/**
 * @brief Disable homerow mod tap combinations
 *
 * This is useful for key combinations that trigger modifiers when rolling.
 *
 * Example: In colemak you are having issues with rolling `en` and getting N
 * instead (with GASC mods). In process_record_user have a case for the second
 * key in the trouble sequence and call roll:
 *
 *      case HM_N:
 *          if (record->event.pressed && record->tap.count > 0) {
 *              return mod_roll_cancellation(KC_RSHIFT, KC_E, KC_N); // en
 *          }
 *          break;
 *
 * @param mod Modifier of the preveous key that wound have triggered
 * @param prev Keycode of the prev key that was held triggering the mod
 * @param cur Keycode of the current key that is being checked in
 * process_record_user
 */
bool mod_roll_cancellation(uint8_t mod, uint16_t prev, uint16_t cur) {
  if (get_mods() & MOD_BIT(mod)) { // [io]
    unregister_mods(MOD_BIT(mod));
    tap_code(prev);
    tap_code(cur);
    add_mods(MOD_BIT(mod));
    return false;
  }
  return true;
}

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific
 * customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
                                                 keyrecord_t *record) {
  return true;
}

/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature
 * handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) {
    return false;
  }
#endif

  // Sticky layer key
  if (keycode == STCK_LY && record->event.pressed) {
    default_layer_set(
        default_layer_state ? 0 : (1 << get_highest_layer(layer_state)));
    return false;
  }

  uint8_t mods = get_mods();
  switch (keycode) {
  case KC_COLEMAK ... KC_GAME:
    if (record->event.pressed)
      set_single_persistent_default_layer(keycode - KC_COLEMAK);
    return false;

  case TL_GAME:
    if (record->event.pressed)
      layer_invert(_GAME);
    return false;

  case TL_STNO:
    if (record->event.pressed)
      layer_invert(_STENO);
    return false;

    // Mod tap can only handle basic keycodes
  case HM_LPRN:
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_LPRN);
      return false;
    }
    break;

  case HM_RPRN:
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_RPRN);
      return false;
    }
    break;

    // TODO: Shift is currently not being registered
  case VB_UP:
    if (record->event.pressed) {
      if (mods & MOD_BIT(MOD_MASK_SHIFT)) {
        register_code16(KC_BRIU);
      } else {
        register_code16(KC_VOLU);
      }
    } else {
      unregister_code16(KC_BRIU);
      unregister_code16(KC_VOLU);
    }
    return false;

  case VB_DOWN:
    if (record->event.pressed) {
      if (mods & MOD_BIT(MOD_MASK_SHIFT)) {
        register_code16(KC_BRID);
      } else {
        register_code16(KC_VOLD);
      }
    } else {
      unregister_code16(KC_BRID);
      unregister_code16(KC_VOLD);
    }
    return false;

  case MUTE_MIC:
    if (record->event.pressed) {
      if (mods & MOD_BIT(MOD_MASK_SHIFT)) {
        tap_code16(KC_F20);
      } else {
        tap_code16(KC_MUTE);
      }
    }
    return false;

#ifndef ACHORDION_ENABLE
  case HM_O:
    if (record->event.pressed && record->tap.count > 0) {
      return mod_roll_cancellation(KC_LALT, KC_I, KC_O); // io
    }
    break;
#endif

    // case HM_T:
    //   if (record->event.pressed && record->tap.count > 0) {
    //     return mod_roll_cancellation(KC_RGUI, KC_I, KC_O); // io
    //   }
    //   break;

  default:
    return true;
  }

  return process_record_keymap(keycode, record);
}

/**
 * @brief Tri state handler
 *
 * This handles activating a layer by holding down two other layers.
 *
 * @param state Curret layer state that will be updated
 */
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJ);
}

/**
 * @brief Per key tapping term
 *
 * Get the tapping term for a specific key.
 * This handles activating a layer by holding down two other layers
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Pinky keys
  case HM_A:
  case HM_O:
  case HM_GRV:
  case HM_PRSC:
    return TAPPING_TERM + 30;

    // Thumb keys
  case LOW_TAB:
  case SFT_BSP:
  case SFT_SPC:
  case RAS_MIN:
    return TAPPING_TERM - 25;

  default:
    return TAPPING_TERM;
  }
}

#ifdef ACHORDION_ENABLE
// https://getreuer.info/posts/keyboards/achordion/index.html
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Dvorak.
  switch (tap_hold_keycode) {
  case LOW_TAB:
  case RAS_MIN:
  case SFT_SPC:
  case SFT_BSP:
    return true;

  case HM_A:
    if (other_keycode == LOW_TAB) {
      return true;
    } // cmd + tab on mac
    break;

  case HM_S:
    if (other_keycode == LOW_TAB) {
      return true;
    } // alt + tab on mac
    break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

void matrix_scan_user(void) { achordion_task(); }
#endif
