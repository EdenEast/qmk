// This file is modified from @rafaelromao's smart_case feature.
// https://raw.githubusercontent.com/rafaelromao/keyboards/a428ab8/src/qmk/users/rafaelromao/features/smart_case.c

#include "smart_case.h"

smart_case_t smart_case = {.timer = 0, .type = NO_CASE};
static bool caps_lock_enabled = false;

void start_smart_case_timer(void) { smart_case.timer = timer_read(); }

void clear_smart_case_timer(void) { smart_case.timer = 0; }

bool smart_case_timer_expired(void) {
#if (defined(ONESHOT_TIMEOUT) && (ONESHOT_TIMEOUT > 0))
  return smart_case.timer > 0 &&
         (timer_elapsed(smart_case.timer) > 5 * ONESHOT_TIMEOUT);
#else
  return false;
#endif
}

void clear_shift(void) {
  del_oneshot_mods(MOD_MASK_SHIFT);
  unregister_mods(MOD_MASK_SHIFT);
}

void disable_smart_case(void) {
  smart_case.type = NO_CASE;
  clear_smart_case_timer();
  clear_shift();
  if (caps_lock_enabled) {
    tap_code(KC_CAPS);
    caps_lock_enabled = false;
  }
}

bool has_any_smart_case(void) { return smart_case.type != NO_CASE; }

bool has_smart_case(smart_case_type_t smart_case_types) {
  return smart_case.type & smart_case_types;
}

uint16_t extract_tapping_keycode(uint16_t keycode) {
  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
  case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    return keycode &= 0xFF;
  default:
    return keycode;
  }
}

void enable_smartcase(smart_case_type_t smart_case_types) {
  if (smart_case.type == NO_CASE) {
    smart_case.type = smart_case_types;
  } else {
    smart_case.type = smart_case.type | smart_case_types;
  }
  start_smart_case_timer();
}

void enable_capslock(void) {
  enable_smartcase(CAPS_LOCK);
  if (!caps_lock_enabled) {
    tap_code(KC_CAPS);
    caps_lock_enabled = true;
  }
}

void set_smart_case(smart_case_type_t smart_case_types) {
  if (smart_case_types & CAPS_LOCK) {
    enable_capslock();
    return;
  }
  if (smart_case_types & CAMEL_CASE) {
    // Setting CapsWord with CamelCase already set, makes Pascal Case
    if (has_smart_case(WORD_CASE)) {
      disable_smart_case();
      add_oneshot_mods(MOD_MASK_SHIFT);
    }
  }
  enable_smartcase(smart_case_types);
}

void toggle_capslock(void) {
  if (!caps_lock_enabled) {
    set_smart_case(CAPS_LOCK);
  } else {
    disable_smart_case();
  }
}

void toggle_smart_case(smart_case_type_t smart_case_types) {
  if (has_smart_case(smart_case_types)) {
    disable_smart_case();
  } else {
    set_smart_case(smart_case_types);
  }
}

__attribute__((weak)) bool
set_smart_case_for_mods_keymap(uint8_t mods, smart_case_type_t *type) {
  return false;
}

void set_smart_case_for_mods(void) {
  int8_t mods = get_mods();
  disable_smart_case();
  smart_case_type_t smart_case_type = NO_CASE;
  if (set_smart_case_for_mods_keymap(mods, &smart_case_type)) {
    toggle_smart_case(smart_case_type);
    return;
  }

  /**
   * LCTRL:          WORD_CASE
   * LSHIFT:         SNAKE_CASE
   * LCTRL + LSHIFT: CONSTNAT_CASE
   * LALT:           CAMEL_CASE
   * LCTRL + LALT:   PASCAL_CASE
   * RCTRL:          CAPS_LOCK
   * RALT:           KEBAB_CASE
   * RSHIFT + RCTRL: SCREAMING_KEBAB_CASE
   * RALT:           SLASH_CASE
   * RSHIFT + RCTRL: SCREAMING_SLASH_CASE
   */
  if (mods == 0 || mods & MOD_BIT(KC_LCTL)) {
    toggle_smart_case(WORD_CASE);
    toggle_capslock();
  }
  if (mods & MOD_BIT(KC_RCTL)) {
    toggle_capslock();
  }
  if (mods & MOD_BIT(KC_LSFT)) {
    toggle_smart_case(SNAKE_CASE);
  }
  if (mods & MOD_BIT(KC_RALT)) {
    toggle_smart_case(SLASH_CASE);
  }
  if (mods & MOD_BIT(KC_LALT)) {
    toggle_smart_case(CAMEL_CASE);
  }
  if (mods & MOD_BIT(KC_RSFT)) {
    toggle_smart_case(KEBAB_CASE);
  }
}

__attribute__((weak)) bool process_smart_case_keymap(uint16_t keycode,
                                                     keyrecord_t *record) {
  return true;
}

// Double tapping space will deactivate smart case. This stores the state of the
// first space press.
static bool spacing = false;
bool process_smart_case(uint16_t keycode, keyrecord_t *record) {
  if (has_any_smart_case() && record->event.pressed) {
    switch (keycode) {
    // Earlier return if this has not been considered tapped yet.
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) {
        return true;
      }
      break;
      // Skip tapdance
    case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
      return true;
    }

    uint16_t key = extract_tapping_keycode(keycode);

    // Checking if we are not typing a space
    if (key != KC_SPC) {
      spacing = false;
    }

    if (!process_smart_case_keymap(keycode, record)) {
      return false;
    }

    switch (key) {
    case KC_SPC:
      if (spacing) {
        if (has_smart_case(SNAKE_CASE) || has_smart_case(KEBAB_CASE) ||
            has_smart_case(SLASH_CASE)) {
          tap_code(KC_BSPC);
        }
        disable_smart_case();
        tap_code(KC_SPC);
        return false;
      } else {
        spacing = true;
      }
      if (has_smart_case(WORD_CASE) && !(has_smart_case(SNAKE_CASE)) &&
          !(has_smart_case(CAMEL_CASE)) && !(has_smart_case(KEBAB_CASE)) &&
          !(has_smart_case(SLASH_CASE))) {
        disable_smart_case();
        return true;
      }
      if (has_smart_case(SNAKE_CASE)) {
        tap_code16(KC_UNDS);
        start_smart_case_timer();
        return false;
      }
      if (has_smart_case(KEBAB_CASE)) {
        tap_code16(KC_MINS);
        start_smart_case_timer();
        return false;
      }
      if (has_smart_case(SLASH_CASE)) {
        tap_code(KC_SLSH);
        start_smart_case_timer();
        return false;
      }
      if (has_smart_case(CAMEL_CASE)) {
        add_oneshot_mods(MOD_LSFT);
        start_smart_case_timer();
        return false;
      }
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_MINS:
    case KC_UNDS:
    case KC_LEFT:
    case KC_RIGHT:
    case KC_UP:
    case KC_DOWN:
    case KC_HOME:
    case KC_END:
      start_smart_case_timer();
      break;
    case KC_DOT:
    case KC_SLSH:
      if (has_smart_case(SLASH_CASE)) {
        start_smart_case_timer();
        break;
      }
    case KC_ESC:
      disable_smart_case();
      return false;
      break;
    default:
      disable_smart_case();
      tap_code16(key);
      return false;
    }
  }
  return true;
}
