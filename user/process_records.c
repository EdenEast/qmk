#include "edeneast.h"
#include "process_records.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COLEMAK ... KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(keycode - KC_COLEMAK);
            }
            break;
    }
    return process_record_keymap(keycode, record);
}
