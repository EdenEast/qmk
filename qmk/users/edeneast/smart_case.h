#pragma once

#include QMK_KEYBOARD_H

typedef enum {
  NO_CASE = 1 << 0,
  CAPS_LOCK = 1 << 1,
  WORD_CASE = 1 << 2,
  SNAKE_CASE = 1 << 3,
  KEBAB_CASE = 1 << 4,
  CAMEL_CASE = 1 << 5,
  SLASH_CASE = 1 << 6,
} smart_case_type_t;

typedef struct {
  smart_case_type_t type;
  uint16_t timer;
} smart_case_t;

/**
 * @brief Set smart case for mods
 *
 * Sets the smart case for the current mods being held
 */
void set_smart_case_for_mods(void);

/**
 * @brief Determine smart case via mods for keymap
 *
 * @param mods The current mods being held
 * @param type The smart case type to set
 *
 * @return true if smart case was set and should be overridden
 */
bool set_smart_case_for_mods_keymap(uint8_t mods, smart_case_type_t *type);

/**
 * @brief Process smart case
 *
 * @param keycode The keycode being processed
 * @param record The keyrecord being processed
 *
 * @return false if process_record_user should stop processing keycode and not
 * send to host
 */
bool process_smart_case(uint16_t keycode, keyrecord_t *record);
