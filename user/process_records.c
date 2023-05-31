#include "edeneast.h"

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

  default:
    return true;
  }
  return true;
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
    return TAPPING_TERM + 25;

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
