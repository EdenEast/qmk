#pragma once
#include "edeneast.h"

#define TD_LAYR TD(DANCE_LAYER)
#define TD_TMUX TD(DANCE_TMUX)

enum
{
    DANCE_LAYER = 0,
    DANCE_TMUX,
};

typedef enum
{
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
} td_state_t;

typedef struct
{
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t* state);
