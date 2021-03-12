#include "edeneast.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // My pinkys are not as fast
        //
        // These two cases are covered by HOME_CA as they are all defined to the same thing once macro is expanded
        case HOME_CA:
        case HOME_WA:
        case HOME_QA:
        case HOME_CO:
        case HOME_WI:
        case HOME_QC:
            return TAPPING_TERM + 100;

        // Using the thumb keys to swich layers is the core to thes layout. Making it faster to switch layers
        case NAV_SPC:
        case MOU_TAB:
        case MED_ESC:
        case NUM_BSP:
        case SYM_DEL:
        case FN_ENTR:
            return TAPPING_TERM - 30;

        default:
            return TAPPING_TERM;
    }
}

