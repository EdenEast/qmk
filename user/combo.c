#include "edeneast.h"

// Examples:
// https://github.com/qmk/qmk_firmware/blob/6f54286/users/ibnuda/combo.h

enum combos
{
    DOTCOM_EXLM,
};

const uint16_t PROGMEM dotcom_exlm[] = { KC_COMM, KC_DOT, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    [DOTCOM_EXLM] = COMBO(dotcom_exlm, KC_EXLM),
};
