#include "edeneast.h"
#include "process_records.h"

#ifdef ACHORDION_ENABLE
#  include "features/achordion.h"
#endif

#ifdef SENTENCE_CASE_ENABLE
#  include "features/sentence_case.h"
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
 *      case HMA_N:
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

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
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
#ifdef SENTENCE_CASE_ENABLE
  if (!process_sentence_case(keycode, record)) {
    return false;
  }
#endif

#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) {
    return false;
  }
#endif

  if (!process_smart_case(keycode, record)) {
    return false;
  }

  // Sticky layer key
  if (keycode == STCK_LY && record->event.pressed) {
    default_layer_set(default_layer_state ? 0 : (1 << get_highest_layer(layer_state)));
    return false;
  }

  const uint8_t mods         = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();
  switch (keycode) {
    case KC_CLMK ... KC_GAME:
      if (record->event.pressed) set_single_persistent_default_layer(keycode - KC_CLMK);
      return false;

    case TL_GAME: // TODO: save state of sentence case and turn it off
      if (record->event.pressed) layer_invert(_GAME);
      return false;

    case TL_ENGM: // TODO: save state of sentence case and turn it off
      if (record->event.pressed) layer_invert(_ENGRAM);
      return false;

#ifdef STENO_ENABLE
    case TL_STNO: // TODO: save state of sentence case and turn it off
      if (record->event.pressed) layer_invert(_STENO);
      return false;
#endif

#ifdef SENTENCE_CASE_ENABLE
    case TG_SENT:
      if (record->event.pressed) sentence_case_toggle();
      return false;
#endif

    case TRP_GRV:
      if (record->event.pressed) {
        tap_code16(KC_GRV);
        tap_code16(KC_GRV);
        tap_code16(KC_GRV);
      }
      return false;

    case ED_UNDO:
      if (record->event.pressed) {
        uint16_t mod = KC_LCTL;
        register_code(mod);
        tap_code(KC_Z);
        unregister_code(mod);
      }
      break;

    case ED_CUT:
      if (record->event.pressed) {
        uint16_t mod = KC_LCTL;
        register_code(mod);
        tap_code(KC_X);
        unregister_code(mod);
      }
      break;

    case ED_COPY:
      if (record->event.pressed) {
        uint16_t mod = KC_LCTL;
        register_code(mod);
        tap_code(KC_C);
        unregister_code(mod);
      }
      break;

    case ED_PASTE:
      if (record->event.pressed) {
        uint16_t mod = KC_LCTL;
        register_code(mod);
        tap_code(KC_V);
        unregister_code(mod);
      }
      break;

    case UP_DIR:
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      return false;

    case KC_RARW:
      if (record->event.pressed) {
        SEND_STRING("<-");
      }
      return false;

    case DB_QUOT:
      if (record->event.pressed) {
        clear_oneshot_mods(); // Temporarily disable mods.
        unregister_mods(MOD_MASK_CSAG);
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("''");
        } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
          SEND_STRING("``");
        } else {
          SEND_STRING("\"\"");
        }
        tap_code(KC_LEFT);
        register_mods(mods);
      }
      return false;

    case KC_MAKE: // Sends 'qmk compile' or 'qmk flash'
      if (record->event.pressed) {
        bool flash = false;
// If is a keyboard and auto-flash is not set in rules.mk,
// then Shift will trigger the flash command
#if !defined(FLASH_BOOTLOADER) && !defined(IS_MACROPAD)
        uint8_t temp_mod = get_mods();
        uint8_t temp_osm = get_oneshot_mods();
        clear_mods();
        clear_oneshot_mods();
        if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
#endif
        {
          flash = true;
        }
        send_make_command(flash);
      }
      break;

    case HM_MUX:
      if (record->tap.count && record->event.pressed) {
        tap_code16(C(KC_A));
        return false;
      }
      record->event.pressed ? register_code(KC_LGUI) : unregister_code(KC_LGUI);
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
        if (mods & MOD_MASK_SHIFT) {
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
        if (mods & MOD_MASK_SHIFT) {
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
        tap_code(KC_F20);
      }
      return false;

    case HM_MIC:
      if (!record->tap.count) { // not tapped and key is held
        if (record->event.pressed) {
          register_code(KC_RCTL);
        } else {
          unregister_code(KC_RCTL);
        }
      } else {
        tap_code(KC_F20);
      }
      return false;

#ifndef ACHORDION_ENABLE
    case HMA_O:
      if (record->event.pressed && record->tap.count > 0) {
        return mod_roll_cancellation(KC_LALT, KC_I, KC_O); // io
      }
      break;
#endif

      // case HMA_T:
      //   if (record->event.pressed && record->tap.count > 0) {
      //     return mod_roll_cancellation(KC_RGUI, KC_I, KC_O); // io
      //   }
      //   break;
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

__attribute__((weak)) uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record) {
  return TAPPING_TERM;
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
    case HMA_A:
    case HMA_O:
    case HME_C:
    case HME_N:
    case HM_GRV:
    case HM_PRSC:
      return TAPPING_TERM + 40;

      // Thumb keys
    case LOW_TAB:
    case SFT_BSP:
    case SFT_SPC:
    case RAS_MIN:
      return TAPPING_TERM - 25;

    default:
      return get_tapping_term_keymap(keycode, record);
  }
}

#ifdef ACHORDION_ENABLE
__attribute__((weak)) bool achordion_chord_keymap(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  return false;
}

/**
 * @brief Bilateral combinations
 *
 * Decide the outcome of tap-hold key depending on the other key pressed.
 * When return is true the tap-hold key is concidered held, else it is
 * determined to be both tapped.
 *
 * @see
 * https://getreuer.info/posts/keyboards/achordion/index.html#achordion_chord
 *
 * @paran tap_hold_keycode Key to be decided if key is tapped of held
 * @paran tap_hold_record The matrix information for the tap hold key
 * @paran other_keycode The other key that will determine the state of the
 * tap_hold key
 * @paran other_record The matrix information for the other key
 * @return true considered tap-hold, false considered both tap keys
 */
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  if (achordion_chord_keymap(tap_hold_keycode, tap_hold_record, other_keycode, other_record)) {
    return true;
  }

  switch (tap_hold_keycode) {
    // Keys that should be considered tap-hold regardless of the other key.
    // Achordion should not consider these keys.
    case CTR_ESC:
    case CTR_QOT:
    case HM_MUX:
    case HM_ENT:
      return true;

      // Allow one handed ctrl/super key combinations for non-homerow keys
    case HMA_A:
      switch (other_keycode) {
        case KC_Z:
        case KC_X:
        case KC_C:
        case KC_D:
        case KC_V:
        case KC_Q:
        case KC_W:
        case KC_F:
          return true;
      }
      break;
    case HMA_T:
      switch (other_keycode) {
        case KC_Z:
        case KC_X:
        case KC_C:
        case KC_D:
        case KC_V:
        case KC_Q:
        case KC_W:
        case KC_F:
          return true;
      }
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
#endif

__attribute__((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
  matrix_scan_keymap();
#ifdef ACHORDION_ENABLE
  achordion_task();
#endif
}

void send_make_command(bool flash_bootloader) {
  SEND_STRING_DELAY("qmk ", TAP_CODE_DELAY);
  if (flash_bootloader) {
    SEND_STRING_DELAY("flash ", TAP_CODE_DELAY);
  } else {
    SEND_STRING_DELAY("compile ", TAP_CODE_DELAY);
  }
  SEND_STRING_DELAY("-j0 -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER), TAP_CODE_DELAY);
}
