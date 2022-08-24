#include "edeneast.h"
#include "process_records.h"

bool is_layer_locked = false;
layer_state_t layer_save_state = 0;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

void toggle_layer_lock(layer_state_t layer) {
    is_layer_locked = !is_layer_locked;
    if (is_layer_locked) {
        layer_save_state = get_highest_layer(default_layer_state);
        default_layer_set(1U << layer);
    } else {
        default_layer_set(layer_save_state);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

    switch (keycode) {
        case KC_COLEMAK ... KC_GAME:
            if (record->event.pressed)
                set_single_persistent_default_layer(keycode - KC_COLEMAK);
            break;

        // case KC_RAISE ... KC_FN:
        //     if (record->event.pressed)
        //         toggle_layer_lock(keycode - KC_COLEMAK);
        //     break;

        case KC_BSPC: // SHIFT + BSPACE for del
        {
            static bool delkey_registered;
            if (record->event.pressed) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
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

    return process_record_keymap(keycode, record);
}
