// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"
#include "keymap_russian.h"


// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

static bool is_lang_switched = false;
static bool lang_switching_started = false;
int get_ru_sym(int eng_sym);

// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t ru_hard_sign_key_override = {
    .trigger_mods           = MOD_MASK_SHIFT,
    .layers                 = ~0,
    .suppressed_mods        = MOD_MASK_SHIFT,
    .options                = ko_options_default,
    .negative_mod_mask      = 0,
    .custom_action          = NULL,
    .context                = NULL,
    .trigger                = KC_Z,
    .replacement            = RU_HARD,
    .enabled                = &is_lang_switched
};

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    &ru_hard_sign_key_override,
    NULL
};


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R',           'R'
);

/* const uint16_t PROGMEM mute_combo_base[]     = {KC_F, LT(U_REPL, KC_P), COMBO_END}; */
/* const uint16_t PROGMEM del_combo_base[]      = {LT(U_REPR, KC_L), KC_U, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_rep[]      = {KC_F, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM del_combo_rep[]       = {KC_L, KC_U, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_sftfun[]   = {LSFT(KC_F8), LSFT(KC_F9), COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_num[]      = {KC_8, KC_9, COMBO_END}; */
/* const uint16_t PROGMEM del_combo_mouse_nav[] = {U_PST, U_CPY, COMBO_END}; */
/* const uint16_t PROGMEM del_combo_media[]     = {RGB_MOD, RGB_HUI, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_fun[]      = {KC_F8, KC_F9, COMBO_END}; */
/* const uint16_t PROGMEM mute_combo_sym[]      = {KC_ASTR, KC_LPRN, COMBO_END}; */
/**/
/* combo_t key_combos[] = { */
/*     COMBO(mute_combo_base,     KC_MUTE), */
/*     COMBO(del_combo_base,      KC_DEL), */
/*     COMBO(mute_combo_rep,      KC_MUTE), */
/*     COMBO(del_combo_rep,       KC_DEL), */
/*     COMBO(mute_combo_sftfun,   KC_MUTE), */
/*     COMBO(mute_combo_num,      KC_MUTE), */
/*     COMBO(del_combo_mouse_nav, KC_DEL), */
/*     COMBO(del_combo_media,     KC_DEL), */
/*     COMBO(mute_combo_fun,      KC_MUTE), */
/*     COMBO(mute_combo_sym,      KC_MUTE), */
/* }; */

const uint16_t PROGMEM lang_switch_combo[] = {LSFT_T(KC_N), LCTL_T(KC_E), COMBO_END};

combo_t key_combos[] = {
    COMBO(lang_switch_combo, LANG_SWITCH),
};

uint32_t finish_lang_switching(uint32_t trigger_time, void *cb_arg) {
    /* do something */
    lang_switching_started = false;
    return 0;
}

bool is_non_basic_symbol(uint16_t keycode) {
    switch (keycode) {
        case KC_LCBR: return true;
        case KC_RCBR: return true;
        case KC_COLN: return true;
        case KC_AT: return true;
        case KC_HASH: return true;
        case KC_DLR: return true;
        case KC_CIRC: return true;
        case KC_AMPR: return true;

        case KC_PIPE: return true;
    }
    return false;
}

bool is_bottom_row_ru_sym(uint16_t keycode) {
    return ( keycode == MY_RU_E || keycode == MY_RU_SHCH || keycode == MY_RU_EF || keycode == MY_RU_TSE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LANG_SWITCH && record->event.pressed && !lang_switching_started) {
        is_lang_switched = !is_lang_switched;
        /* register_code(KC_LGUI); // KC_LGUI is the left Cmd/Win key */
        /* register_code(KC_SPACE); */
        /* tap_code16_delay(LGUI(KC_SPACE), 50); */
        lang_switching_started = true;
        defer_exec(30, finish_lang_switching, NULL);
        register_code(KC_LGUI);
        wait_ms(10);
        register_code(KC_SPACE);
        wait_ms(10);
        unregister_code(KC_SPACE);
        wait_ms(10);

        unregister_code(KC_LGUI);

        return false; // Skip further processing of this key
    } else if (is_lang_switched && record->event.pressed &&
        (record->tap.count || IS_BASIC_KEYCODE(keycode) ||
        is_bottom_row_ru_sym(keycode) || is_non_basic_symbol(keycode))) {
        bool is_ctrl_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL;
        bool is_alt_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_ALT;
        bool is_gui_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_GUI;
        if (is_ctrl_on || is_alt_on || is_gui_on) return true;

        int ru_key = get_ru_sym(keycode);
        if (!ru_key) return true;
        tap_code16(ru_key);
        return false; // Skip further processing of this key
    }

    return true; // Process other keycodes normally
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}

int get_ru_sym(int eng_sym) {
    bool is_shift_on = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    switch (eng_sym) {
        case KC_Q: return RU_YU;
        case KC_W: return RU_ZHE;
        case KC_F: return RU_SHA;
        case LT(U_REPL, KC_P): return RU_PE;
        case KC_P: return RU_PE;
        case KC_B: return RU_BE;
        case KC_J: return RU_SHTI;
        case LT(U_REPR, KC_L): return RU_EL;
        case KC_L: return RU_EL;
        case KC_U: return RU_U;
        case KC_Y: return RU_YERU;
        case KC_QUOTE: return RU_YA;
        case LGUI_T(KC_A): return RU_A;
        case KC_A: return RU_A;
        case LALT_T(KC_R): return RU_ER;
        case KC_R: return RU_ER;
        case LCTL_T(KC_S): return RU_ES;
        case KC_S: return RU_ES;
        case LSFT_T(KC_T): return RU_TE;
        case KC_T: return RU_TE;
        case KC_G: return RU_GHE;
        case LT(U_SFTFUN, KC_M): return RU_EM;
        case KC_M: return RU_EM;
        case LSFT_T(KC_N): return RU_EN;
        case KC_N: return RU_EN;
        case LCTL_T(KC_E): return RU_IE;
        case KC_E: return RU_IE;
        case LALT_T(KC_I): return RU_I;
        case KC_I: return RU_I;
        case LGUI_T(KC_O): return RU_O;
        case KC_O: return RU_O;
        case KC_Z: { if (is_shift_on) return KC_NO; return RU_SOFT; }
        case HYPR_T(KC_X): return RU_HA;
        case KC_X: return RU_HA;
        case MEH_T(KC_C): return RU_ZE;
        case KC_C: return RU_ZE;
        case KC_D: return RU_DE;
        case KC_V: return RU_VE;
        case KC_K: return RU_KA;
        case LT(U_FUN,KC_H): return RU_CHE;
        case KC_H: return RU_CHE;
        case MEH_T(KC_COMM): { if (is_shift_on) return RALT(S(KC_COMM)); return RU_COMM;}
        case KC_COMMA: { if (is_shift_on) return RALT(S(KC_COMMA)); return RU_COMM;}
        case HYPR_T(KC_DOT): { if (is_shift_on) return RALT(S(KC_DOT)); return RU_DOT;}
        case KC_DOT: { if (is_shift_on) return RALT(S(KC_DOT)); return RU_DOT;}
        case KC_SLSH: { if (is_shift_on) return RU_QUES; return RU_SLSH; }

        case MY_RU_E: return RU_E;
        case MY_RU_SHCH: return RU_SHCH;
        case MY_RU_EF: return RU_EF;
        case MY_RU_TSE: return RU_TSE;

        case KC_LBRC: return RALT(KC_GRV);
        case KC_RBRC: return S(RALT(KC_GRV));

        case KC_LCBR: return S(RALT(KC_LPRN));
        case KC_RCBR: return S(RALT(KC_RPRN));

        case KC_SCLN: return RU_SCLN;
        case KC_COLN: return RU_COLN;

        case KC_AT: return RALT(KC_2);
        case KC_HASH: return RALT(KC_3);
        case KC_DLR: return RALT(KC_4);
        case KC_CIRC: return RALT(KC_6);
        case KC_AMPR: return RALT(KC_7);

        case KC_PIPE: return S(RALT(KC_PIPE));
    }
    return KC_NO;
}
