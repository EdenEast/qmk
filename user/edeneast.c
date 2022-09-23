#include "edeneast.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record)
{
    switch (keycode)
    {
    case SFT_BSP:
        return TAPPING_TERM - 80;
    case SYM_TAB:
    case NAV_MNS:
        return TAPPING_TERM - 50;
    default:
        return TAPPING_TERM;
    }
}
