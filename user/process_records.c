#include "process_records.h"
#include "edeneast.h"

bool is_layer_locked = false;
layer_state_t layer_save_state = 0;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
    keyrecord_t* record)
{
    return true;
}

void toggle_layer_lock(layer_state_t layer)
{
    is_layer_locked = !is_layer_locked;
    if (is_layer_locked)
    {
        layer_save_state = get_highest_layer(default_layer_state);
        default_layer_set(1U << layer);
    }
    else
    {
        default_layer_set(layer_save_state);
    }
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    return update_tri_layer_state(state, _SYM, _NAV, _ADJ);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    // uint8_t mod_state = get_mods();

    switch (keycode)
    {
    case KC_COLEMAK ... KC_GAME:
        if (record->event.pressed)
            set_single_persistent_default_layer(keycode - KC_COLEMAK);
        break;

        // case KC_BSPC: // SHIFT + BSPACE for del
        // {
        //     static bool delkey_registered;
        //     if (record->event.pressed) {
        //         del_mods(MOD_MASK_SHIFT);
        //         register_code(KC_DEL);
        //         delkey_registered = true;
        //         set_mods(mod_state);
        //         return false;
        //     } else {
        //         if (delkey_registered) {
        //             unregister_code(KC_DEL);
        //             delkey_registered = false;
        //             return false;
        //         }
        //     }
        //     return true;
        // }

    case KC_LPLT:
        if (record->event.pressed)
        {
            if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
            {
                tap_code(KC_COMM); // '<' (Shift already registered)
            }
            else
            {
                tap_code16(KC_LPRN);
            }
        }
        return false;

    case KC_RPGT:
        if (record->event.pressed)
        {
            if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
            {
                tap_code(KC_DOT); // '>' (Shift already registered)
            }
            else
            {
                tap_code16(KC_RPRN);
            }
        }
        return false;

    case KC_CMEX:
        if (record->event.pressed)
        {
            if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
            {
                tap_code(KC_1); // '!' (Shift already registered)
            }
            else
            {
                tap_code16(KC_COMM);
            }
        }
        return false;

    case KC_DTPP:
        if (record->event.pressed)
        {
            if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
            {
                tap_code(KC_BSLS); // '|' (Shift already registered)
            }
            else
            {
                tap_code16(KC_DOT);
            }
        }
        return false;

    case KC_NEQL:
        if (record->event.pressed)
        {
            SEND_STRING("!=");
        }
        return false;
    case KC_AROW:
        if (record->event.pressed)
        {
            SEND_STRING("->");
        }
        return false;

    case TLR_GME:
        layer_invert(_GAME);
        return false;

    case TLR_STN:
        layer_invert(_STENO);
        return false;
    }

    return process_record_keymap(keycode, record);
}
