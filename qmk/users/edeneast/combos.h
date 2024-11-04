#pragma once

/**
 * An adaptation of filterpaper's adaptation of Jane Bernhardt's Combos on Steroids
 * - filterpaper's adaptation: https://github.com/filterpaper/qmk_userspace/blob/43f8eb1/features/combos.h
 * - Jane Bernhardt's Combos on Steroids: http://combos.gboards.ca/
 *
 * These preprocessors will build combo source codes from the following macros:
 * COMB(name, keycode_shortcut, combo_sequence...)
 * SSTR(name, "string to send", combo_sequence...)
 * FNCT(name, function_call(),  combo_sequence...)
 * ADVC(name, combo_sequence...)
 *
 * Use the COMB macro for simple keycode shortcuts
 * Example: COMB(vol_up, KC_VOLU, KC_Y, KC_U).
 *
 * Use the SSTR macro for sending strings
 * Example: SSTR(which, "which ", KC_W, KC_H).
 *
 * Use the FNCT macro for function callbacks
 * Example: FNCT(rgb_tog, rgb_matrix_toggle(), KC_Z, KC_X)
 *
 * Use the ADVC macro for advanced combos that require process_combo_event
 * Example: ADVC(advanced, KC_Z, KC_X)
 *
 * To define keymap combos define `COMBOS_KEYMAP` in your config.h file and point this to
 * a file that contains you combo definitions.
 *
 * Example:
 *
 * - keymap/<name>/config.h
 *   #define COMBOS_KEYMAP "combos.inc"
 *
 * - keymap/<name>/combos.inc
 *   COMB(vol_up, KC_VOLU, KC_Y, KC_U).
 */

/**
 * @brief User defined combo for custom combo handling
 *
 * This function is used to handle ADVC macros that require to be handled in `process_combo_event`
 *
 * @param combo_index enum of combo that was activated
 * @param pressed if the action was pressed and activated
 * @return true Continue processing combo | false Stop processing combo
 */
bool process_combo_event_user(uint16_t combo_index, bool pressed);

/**
 * @brief Keymap defined combo for custom combo handling
 *
 * @param combo_index enum of combo that was activated
 * @param pressed if the action was pressed and activated
 * @return true Continue processing combo | false Stop processing combo
 */
bool process_combo_event_keymap(uint16_t combo_index, bool pressed);
