// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
#pragma once

#define XXX KC_NO

// clang-format off
#define LAYOUT_miryoku( \
K00,   K01,   K02,   K03,   K04,          K05,   K06,   K07,   K08,   K09, \
K10,   K11,   K12,   K13,   K14,          K15,   K16,   K17,   K18,   K19, \
K20,   K21,   K22,   K23,   K24,          K25,   K26,   K27,   K28,   K29, \
N30,   N31,   K32,   K33,   K34,          K35,   K36,   K37,   N38,   N39 \
) \
LAYOUT_no_ball( \
K00,   K01,   K02,   K03,   K04,          K05,   K06,   K07,   K08,   K09, \
K10,   K11,   K12,   K13,   K14,          K15,   K16,   K17,   K18,   K19, \
K20,   K21,   K22,   K23,   K24,          K25,   K26,   K27,   K28,   K29, \
XXX,   XXX,   XXX,   K32,   K33,   K34,   K35,   K36,   XXX, XXX, XXX, K37 \
)
// clang-format on

// needed for building more layers
// FIXME: why do we need to undefine previous value?
#undef LAYER_STATE_8BIT
#define LAYER_STATE_32BIT

// needed to make RGB work
#define RGB_DI_PIN WS2812_DI_PIN

// disable split detection - should help with sleeping issues
#undef SPLIT_USB_DETECT
#define USB_VBUS_PIN GP19

// right half is the master
/* #define MASTER_RIGHT */
#define MASTER_RIGHT

// REPL layer for QMK
#define MIRYOKU_LAYER_REPL \
KC_Q,             KC_W,             KC_F,             KC_P,             KC_B,             KC_J,             KC_L,             KC_U,             KC_Y,             KC_QUOT,          \
KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          KC_G,             KC_M,             KC_N,             KC_E,             KC_I,             KC_O,             \
KC_Z,             KC_RALT,          KC_C,             KC_D,             KC_V,             KC_K,             KC_H,             KC_COMM,          KC_DOT,           KC_SLSH,          \
U_NP,             U_NP,             KC_LSFT,          KC_LSFT,          KC_LSFT,          KC_ENT,           KC_BSPC,          KC_DEL,           U_NP,             U_NP

// REPR layer for QMK
#define MIRYOKU_LAYER_REPR \
KC_Q,             KC_W,             KC_F,             KC_P,             KC_B,             KC_J,             KC_L,             KC_U,             KC_Y,             KC_QUOT,          \
KC_A,             KC_R,             KC_S,             KC_T,             KC_G,             KC_M,             KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          \
KC_Z,             KC_X,             KC_C,             KC_D,             KC_V,             KC_K,             KC_H,             KC_COMM,          KC_RALT,          KC_SLSH,          \
U_NP,             U_NP,             U_NP,             KC_SPC,           KC_TAB,           KC_LSFT,          KC_LSFT,          U_NP,             U_NP,             U_NP

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(REPL,   "RepL") \
MIRYOKU_X(REPR,   "RepR")

#define MIRYOKU_LAYERMAPPING_REPL MIRYOKU_MAPPING
#define MIRYOKU_LAYERMAPPING_REPR MIRYOKU_MAPPING

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_F,              LT(U_REPL, KC_P),  KC_B,              KC_J,              LT(U_REPR, KC_L),  KC_U,              KC_Y,              KC_QUOT,           \
LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              LT(U_FUN,KC_M),    LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            KC_DEL,            LSFT_T(KC_LEFT),   LCTL_T(KC_DOWN),   LALT_T(KC_UP),     LGUI_T(KC_RIGHT),  \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_BTN3,           KC_BTN1,           SCRL_MO_VRT,       SNIPER_MO,         KC_BTN2,           \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NU,              KC_BTN4,           SCRL_MO_FRE,       SCRL_MO_HOR,       KC_BTN5,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_MUTE,           U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            KC_LSFT,           KC_LSFT,           U_NA,              U_NP,              U_NP
