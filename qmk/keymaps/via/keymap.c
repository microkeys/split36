#include QMK_KEYBOARD_H

/*
#define LAYOUT(\
    k00,  k01,  k02,  k03,  k04,    k45,  k46,  k47,  k48,  k49,\
    k10,  k11,  k12,  k13,  k14,    k55,  k56,  k57,  k58,  k59,\
    k20,  k21,  k22,  k23,  k24,    k65,  k66,  k67,  k68,  k69,\
                k32,  k33,  k34,    k75,  k76,  k77\
) {\
   {k00,  k01,  k02,  k03,  k04,    k45,  k46,  k47,  k48,  k49 },\
   {k10,  k11,  k12,  k13,  k14,    k55,  k56,  k57,  k58,  k59 },\
   {k20,  k21,  k22,  k23,  k24,    k65,  k66,  k67,  k68,  k69 },\
   {KC_NO,KC_NO,k32,  k33,  k34,    k75,  k76,  k77,  KC_NO,KC_NO}\
}
*/

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * .------+------+------+------+------.                    .------+------+------+------+------.
 * |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------|                    |------+------+------+------+------+
 * |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |
 * +------+------+------+------+------|                    |------+------+------+------+------+
 * |   Z  |   X  |   C  |   V  |   B  |-------.    .-------|   N  |   M  |   ,  |   .  |   /  |
 * '----------------------------------/       /     \      \----------------------------------'
 *                   | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR |
 *                   |      |      |/       /         \      \ |      |      |
 *                   '---------------------'           '---------------------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
   KC_Q,     KC_W,     KC_E,     KC_R,       KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
   KC_A,     KC_S,     KC_D,     KC_F,       KC_G,            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
   KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                     KC_LCTL,  MO(_LOWER), KC_ENT,            KC_SPC,  MO(_RAISE), KC_RCTL
),

/* LOWER
 * .------+------+------+------+------.                    .------+------+------+------+------.
 * |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |
 * +------+------+------+------+------|                    |------+------+------+------+------+
 * |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |
 * +------+------+------+------+------|                    |------+------+------+------+------+
 * |  =   |  -   |  +   |   {  |   }  |-------.    .-------|   [  |   ]  |   ;  |   :  |   \  |
 * '----------------------------------/       /     \      \----------------------------------'
 *                   | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR |
 *                   |      |      |/       /         \      \ |      |      |
 *     -             '---------------------'           '---------------------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
 KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,                 KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS,
                   KC_LCTL, MO(_LOWER), KC_ENT,               KC_SPC,MO(_RAISE), KC_RCTL
),

/* RAISE
 * .------+------+------+------+------.                    .------+------+------+------+------.       
 * | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine|       
 * +------+------+------+------+------|                    |------+------+------+------+------+       
 * | LAt  | LCtl |LShift|      | Caps |                    |      | Left | Down | Rigth|  Del |       
 * +------+------+------+------+------|                    |------+------+------+------+------+       
 * | Undo |  Cut | Copy | Paste|      |-------.    .-------|      | LStr |      | LEnd |      |       
 * '----------------------------------/       /     \      \----------------------------------'       
 *                   | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR |
 *                   |      |      |/       /         \      \ |      |      |
 *                   '---------------------'           '---------------------'
 */
[_RAISE] = LAYOUT_split_3x5_3(
  KC_INS,KC_PSCR, KC_APP,XXXXXXX,XXXXXXX,                    KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE,
 KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,KC_CAPS,                    KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,
 KC_UNDO, KC_CUT,KC_COPY,KC_PASTE,XXXXXXX,                   XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX,
                   KC_LCTL, MO(_LOWER), KC_ENT,              KC_SPC,MO(_RAISE), KC_RCTL
),
/* ADJUST
 * .------+------+------+------+------.                    .------+------+------+------+------.
 * QK_BOOT|QWERTY|      |      |      |                    |      |      |      |      |      |
 * +------+------+------+------+------|                    |------+------+------+------+------+
 * |      |MACWIN|      |      |      |                    |      | VOLDO| MUTE | VOLUP|      |
 * +------+------+------+------+------|                    |------+------+------+------+------+
 * |      |      |      |      |      |-------.    .-------|      | PREV | PLAY | NEXT |      |
 * '----------------------------------/       /     \      \----------------------------------'
 *                   | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR |
 *                   |      |      |/       /         \      \ |      |      |
 *                   '---------------------'           '---------------------'
 */
[_ADJUST] = LAYOUT_split_3x5_3(
 QK_BOOT, KC_QWERTY,XXXXXXX,CG_TOGG,XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 XXXXXXX, CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,          XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,
 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,         XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,
                   KC_LCTL, MO(_LOWER), KC_ENT,           KC_SPC,MO(_RAISE), KC_RCTL
)
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYOUT_split_3x5_3"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
