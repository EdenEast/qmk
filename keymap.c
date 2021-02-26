/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/**
 * Base (Colemak-DH) https://colemakmods.github.io/mod-dh/keyboards.html#matrix-keyboards
 * +-----------------------------------------------+                       +-----------------------------------------------+
 * |   `   |   1   |   2   |   3   |   4   |   5   |                       |   6   |   7   |   8   |   9   |   0   |   =   |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |   -   |   q   |   w   |   f   |   p   |   b   |                       |   j   |   l   |   u   |   y   |   ;   |   _   |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |  esc  |   a   |   r   |   s   |   t   |   d   |                       |   m   |   n   |   e   |   i   |   o   |   '   |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |   :   |   z   |   x   |   c   |   d   |   v   |                       |   k   |   h   |   ,   |   .   |   /   |   \   |
 * +---------------+-------+-------+---------------+                       +---------------+-------+-------+---------------+
 *                 |   [   |   ]   |                                                       |   (   |   )   |
 *                 +---------------+---------------+                       +---------------+---------------+
 *                                 |nav_tab|bspace |                       | space |sym_ent|
 *                                 +---------------+                       +---------------+
 *                                         +---------------+       +---------------+
 *                                         | delete|1sh lsf|       |1sh rsf|   up  |
 *                                         |-------+-------|       |-------+-------|
 *                                         |qrty_tg| media |       |sw_hand|  down |
 *                                         +---------------+       +---------------+
 */
[_COLEMAK_DH] = LAYOUT_5x6(
    KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_EQL , \
    KC_MINS,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                        KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_UNDS, \
    KC_ESC ,HOME_CA,HOME_CR,HOME_CS,HOME_CT,KC_G   ,                        KC_M   ,HOME_CN,HOME_CE,HOME_CI,HOME_CO,KC_QUOT, \
    KC_COLN,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,                        KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS, \
                    KC_LBRC,KC_RBRC,                                                        KC_LPRN,KC_RPRN,                 \
                                    NAV_TAB,KC_BSPC,                        KC_SPC ,SYM_ENT,                                 \
                                            KC_DEL ,OS_LSFT,        OS_RSFT,KC_UP  ,                                         \
                                            _______,SH_OS  ,        MEDIA  ,KC_DOWN                                          \
),

[_QWERTY] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,_______, \
    _______,HOME_QA,HOME_QS,HOME_QD,HOME_QF,KC_G   ,                        KC_H   ,HOME_QJ,HOME_QK,HOME_QL,HOME_QC,_______, \
    _______,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                        KC_N   ,KC_M   ,_______,_______,_______,_______, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_SYM] = LAYOUT_5x6(
    KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 , \
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______, \
    _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_NAV] = LAYOUT_5x6(
    RESET  ,DEBUG  ,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,_______, \
    _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,                        KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
                    QRTY_TO,CLMK_TO,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            GAME_TG,_______,        _______,_______                                          \
),

[_MEDIA] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        KC_VOLU,KC_MSEL,KC_MSTP,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        KC_VOLD,_______,_______,_______,_______,_______, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),

[_GAMING] = LAYOUT_5x6(
    KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______, \
    KC_F1  ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                        KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   , \
    KC_GRV ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                        KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN, \
    KC_LALT,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,                        KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,_______, \
                    KC_T   ,KC_G   ,                                                        _______,_______,                 \
                                    KC_WH_U,KC_SPC ,                        _______,_______,                                 \
                                            KC_WH_D,KC_I   ,        KC_BSPC,_______,                                         \
                                            GAME_TG,KC_M   ,        _______,_______                                          \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
        case KC_BSPC:
        {
            static bool delkey_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    // In case only one shift is held
                    // see https://stackoverflow.com/questions/1596668/logical-xor-operator-in-c
                    // This also means that in case of holding both shifts and pressing KC_BSPC,
                    // Shift+Delete is sent (useful in Firefox) since the shift modifiers aren't deleted.
                    if (!(mod_state & MOD_BIT(KC_LSHIFT)) != !(mod_state & MOD_BIT(KC_RSHIFT))) {
                        del_mods(MOD_MASK_SHIFT);
                    }
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        }
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // My pinkys are not as fast
        //
        // These two cases are covered by HOME_CA as they are all defined to the same thing once macro is expanded
        // case HOME_QA:
        case HOME_CA:
        case HOME_CO:
        case HOME_QC:
            return TAPPING_TERM + 50;

        case SYM_ENT: // Very low tapping term so I don't hit enter actidentlly
            return TAPPING_TERM - 20;

        // The One Shot Shift thumb key is used more frequently.
        // To avoid accidental shiftings of T or N or I
        // when rolling over the home row, the tapping term
        // is increased.
        case HOME_CS:
        case HOME_CE:
        case HOME_QD:
        case HOME_QK:
            return TAPPING_TERM + 10;

        default:
            return TAPPING_TERM;
    }
}

// ---------------------------------------------------------------------------------------------------------------------------

/**
 * Layer
 * +-----------------------------------------------+                       +-----------------------------------------------+
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                       |       |       |       |       |       |       |
 * +---------------+-------+-------+---------------+                       +---------------+-------+-------+---------------+
 *                 |       |       |                                                       |       |       |
 *                 +---------------+---------------+                       +---------------+---------------+
 *                                 |       |       |                       |       |       |
 *                                 +---------------+                       +---------------+
 *                                         +---------------+       +---------------+
 *                                         |       |       |       |       |       |
 *                                         |-------+-------|       |-------+-------|
 *                                         |       |       |       |       |       |
 *                                         +---------------+       +---------------+
 */
/*
[_layer] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______, \
                    _______,_______,                                                        _______,_______,                 \
                                    _______,_______,                        _______,_______,                                 \
                                            _______,_______,        _______,_______,                                         \
                                            _______,_______,        _______,_______                                          \
),
*/
