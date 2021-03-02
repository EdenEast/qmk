/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Hardware settings
#define USE_SERIAL
#define MASTER_LEFT

// Home row mod settings
#define TAPPING_TERM 210
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover from triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD

// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

// The setting below defines how many times you need to tap a TT() to toggle the layer.
#define TAPPING_TOGGLE 3

// Limits the max. amount of layers to 8 to save firmware memory. Will not sure more then 8.
// #define LAYER_STATE_8BIT

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4
