#pragma once
#include "edeneast.h"

// Homerow mod keys
// Colemak-DH Base layer
#define HMA_A LGUI_T(KC_A)
#define HMA_R LALT_T(KC_R)
#define HMA_S LSFT_T(KC_S)
#define HMA_T LCTL_T(KC_T)
#define HMA_Z LT(_RAISE, KC_Z)

#define HMA_O RGUI_T(KC_O)
#define HMA_I RALT_T(KC_I)
#define HMA_E RSFT_T(KC_E)
#define HMA_N RCTL_T(KC_N)
#define HMA_SLSH LT(_RAISE, KC_SLSH)

// Engram base layer
#define HME_C LGUI_T(KC_C)
#define HME_I LALT_T(KC_I)
#define HME_E LSFT_T(KC_E)
#define HME_A LCTL_T(KC_A)

#define HME_N RGUI_T(KC_N)
#define HME_S RALT_T(KC_S)
#define HME_T RSFT_T(KC_T)
#define HME_H RCTL_T(KC_H)

#define HM_MUX LGUI_T(TMUX_PX)
#define HM_ENT LGUI_T(KC_ENT)

// Lower
// #define HM_ LGUI_T(KC_)
#define HM_UNDS LALT_T(KC_UNDS)
#define HM_PLUS LSFT_T(KC_PLUS)
#define HM_EQL LCTL_T(KC_EQL)

#define HM_LPRN RCTL_T(KC_LPRN)
#define HM_RPRN RSFT_T(KC_RPRN)
#define HM_RBRC LALT_T(KC_RBRC)
#define HM_GRV RGUI_T(KC_GRV)

// Adj
#define HM_PRSC LGUI_T(KC_PSCR)
// #define HM_ LALT_T(KC_)
// #define HM_ LSFT_T(KC_)
// #define HM_ LCTL_T(KC_)

#define HM_MIC RCTL_T(MUTE_MIC)
// #define HM_ RSFT_T(KC_)
// #define HM_ LALT_T(KC_)

#define CTR_ESC LCTL_T(KC_ESC)
#define CTR_QOT LCTL_T(KC_QUOT)

// Thumb keys

#define LOW_TAB LT(_LOWER, KC_TAB)
#define SFT_BSP LSFT_T(KC_BSPC)
#define SFT_SPC RSFT_T(KC_SPC)
#define RAS_MIN LT(_RAISE, KC_MINS)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific
 * customization
 */
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

/**
 * @brief Per key tapping term for keymaps
 *
 * Get the tapping term for a specific key at the keymap level.
 */
uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record);

void matrix_scan_keymap(void);

#ifndef ACHORDION_ENABLE
/**
 * @brief Achordion handler for keymaps
 *
 * This determines tap-hold keys at the keymap level, useful for keyboard
 * specific customization
 *
 * @paran tap_hold_keycode Key to be decided if key is tapped of held
 * @paran tap_hold_record The matrix information for the tap hold key
 * @paran other_keycode The other key that will determine the state of the
 * tap_hold key
 * @paran other_record The matrix information for the other key
 * @return true considered tap-hold, false considered both tap keys
 */
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record);
#endif

/**
 * Send Make Command
 *
 * Sends 'qmk compile -kb keyboard -km keymap' command to compile firmware
 * Uses 'qmk flash' and resets keyboard, if flash_bootloader set to true
 */
void send_make_command(bool flash_bootloader);
