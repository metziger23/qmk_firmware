#pragma once

#define TAP_CODE_DELAY 5

#define POINTING_DEVICE_ENABLE 1
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1

#define CHARYBDIS_DRAGSCROLL_REVERSE_Y

#define CHARYBDIS_MINIMUM_DEFAULT_DPI 800
#define CHARYBDIS_MINIMUM_SNIPING_DPI 400

#define COMBO_MUST_TAP_PER_COMBO 1

#define COMBO_TERM 25  // Time in milliseconds to recognize combo

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 170

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// needed for building more layers
// FIXME: why do we need to undefine previous value?
#undef LAYER_STATE_8BIT
#define LAYER_STATE_32BIT

#define XXX KC_NO

#define PERMISSIVE_HOLD
#define CHORDAL_HOLD

// needed to make RGB work
// #define RGB_DI_PIN WS2812_DI_PIN
//
// disable split detection - should help with sleeping issues
// #undef SPLIT_USB_DETECT
// #define USB_VBUS_PIN GP19

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
