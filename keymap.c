/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef WPM_ENABLE
    #include <stdio.h>
#endif

enum layers {
    _QWERTY = 0,
    _NUMBERs,
    _FUNCTIONs,
    _MEDIA,
    _MOUSE,
};

// layers modificators
#define GO_NUMBs    MO(_NUMBERs)
#define GO_FUNCs    MO(_FUNCTIONs)
#define GO_MEDIA    TT(_MEDIA)
#define GO_MOUSE    TT(_MOUSE)

// left and right control when held, left and right parenthesis when tap
#define LCL_LPRT    KC_LCPO
#define RCL_RPRT    KC_RCPC

// left alt when held, left and right brackets when tap - the same ALT, so on the other layers doesn't mess with the position of the other modifiers
#define RALT_LBK    ALGR_T(KC_LBRC)
#define RALT_RBK    ALGR_T(KC_RBRC)

// left and right shift when held, left and right curly brackets when tap
#define LSFT_LCB    LSFT_T(KC_LCBR)
#define RSFT_RCB    RSFT_T(KC_RCBR)

// right alt when held, space and enter when tap - the same ALT, so on the other layers doesn't mess with the position of the other modifiers
#define LALT_SPC    LALT_T(KC_SPC)
#define LALT_ENT    LALT_T(KC_ENT)

#define ESC_GUI     GUI_T(KC_ESC)


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 *,---------------------------------------------.                              ,---------------------------------------------.
 *|   Tab   |   Q  |   W  |   E   |   R  |   T  |                              |   Y  |   U  |   I   |  O   |  P   | Esc Gui |
 *|---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
 *| Ctrl (  |   A  |   S  |   D   |   F  |   G  |                              |   G  |   H  |   J   |  K   | ; :  | Ctrl )  |
 *|---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
 *| Shift { |   Z  |   X  |   C   |   V  |   B  | = +  | App  |  | Ins  | - _  |   N  |   M  |  , <  | . >  | / ?  | Shift } |
 *`-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
 *                        | RAlt  |MEDIA | FUNC | Space| DEL  |  | Bcksp| Enter| NUMB |MOUSE | RAlt  |
 *                        |   [   |      |      | LAlt |      |  |      | LAlt |      |      |   ]   |
 *                         -----------------------------------    -----------------------------------
 */
    [_QWERTY] = LAYOUT(
     KC_TAB   ,KC_Q    ,KC_W     ,KC_E     ,KC_R     ,KC_T                       ,                       KC_Y,      KC_U,     KC_I,    KC_O,    KC_P,  ESC_GUI,
     LCL_LPRT, KC_A    ,KC_S     ,KC_D     ,KC_F     ,KC_G                       ,                       KC_H,      KC_J,     KC_K,    KC_L, KC_SCLN, RCL_RPRT,
     LSFT_LCB ,KC_Z    ,KC_X     ,KC_C     ,KC_V     ,KC_B    ,KC_EQL  ,KC_APP   ,   KC_INS,  KC_MINS,   KC_N,      KC_M,  KC_COMM,  KC_DOT, KC_SLSH, RSFT_RCB,
                                  RALT_LBK ,GO_MEDIA ,GO_FUNCs,LALT_SPC,KC_DEL   ,   KC_BSPC,LALT_ENT, GO_NUMBs, GO_MOUSE,RALT_RBK
    ),

/*
 * Base Layer: _NUMBERs
 *
 * ,---------------------------------------------.                              ,---------------------------------------------.
 * |  Tab    |  NO  |  $   |   #   | ` ~  |  |   |                              |  &   | ' "  |   *   |   %  |  NO  | Esc Gui |
 * |---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
 * | Ctrl (  | 1 !  | 2 @  |  3 #  | 4 $  | 5 %  |                              | 6 ^  | 7 &  |  8 *  | 9 (  | 0 )  | Ctrl )  |
 * |---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
 * | Shift { |  NO  |  UP  |  NO   | DOWN |  NO  | = +  | \ |  |  |CapsLk| - _  |  NO  | LEFT |  NO   |RIGHT |  NO  | Shift } |
 * `-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
 *                         | RAlt  | Ctrl |Shift |Space |  NO  |  |  NO  |  NO  |(NUMB)|  NO  | RAlt  |
 *                         |   [   |      |      |LAlt  |      |  |      |      |      |      |   ]   |
 *                          -----------------------------------    -----------------------------------
*/
    [_NUMBERs] = LAYOUT(
     KC_TRNS  ,KC_NO   ,KC_DLR   ,KC_HASH  ,KC_GRV  ,KC_PIPE                   ,                  KC_AMPR,  KC_QUOT,  KC_ASTR, KC_PERC,   KC_NO,  KC_TRNS,
     KC_TRNS  ,KC_1    ,KC_2     ,KC_3     ,KC_4    ,KC_5                      ,                     KC_6,     KC_7,     KC_8,    KC_9,    KC_0,  KC_TRNS,
     KC_TRNS  ,KC_NO   ,KC_UP    ,KC_NO    ,KC_DOWN ,KC_NO   ,KC_EQL  ,KC_BSLS , KC_CAPS, KC_MINS,  KC_NO,  KC_LEFT,    KC_NO,KC_RIGHT,   KC_NO,  KC_TRNS,
                                  KC_TRNS  ,KC_LCTL ,KC_LSFT ,KC_LALT ,KC_NO   ,   KC_NO,   KC_NO,KC_TRNS,    KC_NO,  KC_TRNS
    ),

/*
 * Base Layer: _FUNCTIONs
 *
 * ,---------------------------------------------.                              ,---------------------------------------------.e
 * |  Tab    |  NO  |  F9  |  F10  |  F12 |  NO  |                              |  NO  |  F4  |  F5   |  F6  |  NO  | Esc Gui |
 * |---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
 * | Ctrl (  |  NO  |  F7  |  F8   |  F9  | PgUp |                              | HOME |  F1  |  F2   |  F3  |  NO  | Ctrl )  |
 * |---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
 * | Shift { |  NO  |  UP  |  NO   |  DW  | PgDw |  NO  |  NO  |  |  NO  |  NO  | END  | LEFT |  NO   |RIGHT |  NO  | Shift } |
 * `-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
 *                         |  RAlt |  NO  |(FUNC)|  NO  |  NO  |  |  NO  | LAlt |Shift | Ctrl | RAlt  |
 *                         |   [   |      |      |      |      |  |      |      |      |      |   ]   |
 *                          -----------------------------------    -----------------------------------
*/
    [_FUNCTIONs] = LAYOUT(
     KC_TRNS  ,KC_NO   ,KC_F10   ,KC_F11   ,KC_F12  ,KC_NO                     ,                      KC_NO,    KC_F4,    KC_F5,   KC_F6,   KC_NO,  KC_TRNS,
     KC_TRNS  ,KC_NO   ,KC_F7    ,KC_F8    ,KC_F9   ,KC_PGUP                   ,                    KC_HOME,    KC_F1,    KC_F2,   KC_F3,   KC_NO,  KC_TRNS,
     KC_TRNS  ,KC_NO   ,KC_UP    ,KC_NO    ,KC_DOWN ,KC_PGDN ,KC_NO   ,KC_NO   ,   KC_NO,    KC_NO,  KC_END,  KC_LEFT,    KC_NO, KC_RGHT,   KC_NO,  KC_TRNS,
                                  KC_TRNS  ,KC_NO   ,KC_TRNS ,KC_NO   ,KC_NO   ,   KC_NO,  KC_LALT, KC_RSFT,  KC_RCTL,    KC_TRNS
    ),

/*
 * Base Layer: _MEDIA
 *
 * ,----------------------------------------------.                              ,---------------------------------------------.
 * |   SLEEP |  NO  |  NO  | VOLU  |  NO   |PAUSE |                              |RGB_F |  H_I |  S_I  | B_I  |  NO  |POWER_OFF|
 * |---------+------+------+-------+-------+------|                              |------+------+-------+------+------+---------|
 * |   NO    |  NO  | PREV | VOLD  | NEXT  | STOP |                              |RGB_R |  H_D |  S_D  | B_D  |  NO  |   NO    |
 * |---------+------+------+-------+-------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
 * |   NO    |  NO  |  NO  | MUTE  |  NO   |LAUNCH|  NO  |  NO  |  |  NO  |  NO  |  NO  |  NO  |  NO   |  NO  |  NO  |   NO    |
 * `-----------------------+-------+-------+------+------+------|  |------+------+------+------+-------+-----------------------'
 *                         |   NO  |(MEDIA)|  NO  |  NO  | ---- |  |  NO  |RGB_T |  NO  |  NO  |  NO   |
 *                         |       |       |      |      |      |  |      |      |      |      |       |
 *                          ------------------------------------    -----------------------------------
*/
    [_MEDIA] = LAYOUT(
     KC_SLEP ,KC_NO   ,KC_NO    ,KC_VOLU ,KC_NO   ,KC_MPLY                   ,                    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,   KC_NO, KC_PWR,
     KC_NO   ,KC_NO   ,KC_MPRV  ,KC_VOLD ,KC_MNXT ,KC_MSTP                   ,                   RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,   KC_NO,  KC_NO,
     KC_NO   ,KC_NO   ,KC_NO    ,KC_MUTE ,KC_NO   ,KC_MSEL ,KC_NO   ,KC_NO   ,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO   ,KC_TRNS ,KC_NO   ,KC_NO   ,KC_NO   ,   KC_NO,  RGB_TOG,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * Base Layer: _MOUSE
 *
 * ,---------------------------------------------.                              ,----------------------------------------------.
 * |  Tab    |  NO  |  NO  |  M_U  |  NO  |ACL 1 |                              |  NO  |  NO   | WHL U |  NO  |  NO  | Esc Gui |
 * |---------+------+------+-------+------+------|                              |------+-------+-------+------+------+---------|
 * | Ctrl (  |  NO  | MS_L |  M_D  | M_RG |ACL 2 |                              |  NO  |WHL L  | WHL D |WHL R |  NO  | Ctrl )  |
 * |---------+------+------+-------+------+------+-------------.  ,-------------+------+-------+-------+------+------+---------|
 * | Shift { |  NO  |  UP  |  NO   |  NO  |ACL 3 |  NO  |  NO  |  |  NO  |  NO  |  NO  |  NO   |  NO   |  NO  |  NO  | Shift } |
 * `-----------------------+-------+------+------+------+------|  |------+------+------+-------+-------+-----------------------'
 *                         |   NO  | BTN1 | BTN2 | BTN3 |  NO  |  |  NO  |  NO  |  NO  |(MOUSE)|  NO   |
 *                         |       |      |      |      |      |  |      |      |      |       |       |
 *                          -----------------------------------    ------------------------------------
*/
    [_MOUSE] = LAYOUT(
     KC_TRNS  ,KC_NO   ,KC_NO   ,KC_MS_U  ,KC_NO    ,KC_ACL0                   ,                      KC_NO,    KC_NO,  KC_WH_U,   KC_NO,   KC_NO,  KC_TRNS,
     KC_TRNS  ,KC_NO   ,KC_MS_L ,KC_MS_D  ,KC_MS_R  ,KC_ACL1                   ,                      KC_NO,  KC_WH_L,  KC_WH_D, KC_WH_R,   KC_NO,  KC_TRNS,
     KC_TRNS  ,KC_NO   ,KC_NO   ,KC_NO    ,KC_NO    ,KC_ACL2 ,KC_NO   ,KC_NO   ,   KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_TRNS,
                                 KC_NO    ,KC_BTN3  ,KC_BTN2 ,KC_BTN1 ,KC_NO   ,   KC_NO,    KC_NO,   KC_NO,  KC_TRNS,    KC_NO
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// avoids the problem that the shifted keys cannot be sent with mod tap
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_LCB:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR); // Send KC_LCBR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case RSFT_RCB:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR); // Send KC_RCBR on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}


/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

// /* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
     return OLED_ROTATION_180;
}

#ifdef WPM_ENABLE
    char wpm_str[10];
#endif

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NUMBERs:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            case _FUNCTIONs:
                oled_write_P(PSTR("Function keys\n"), false);
                break;
            case _MEDIA:
                oled_write_P(PSTR("Media keys\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("Mouse keys\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));

        #ifdef WPM_ENABLE
            sprintf(wpm_str, "WPM: %03d", get_current_wpm());
            oled_write_P(PSTR("\n"), false);
            oled_write(wpm_str, false);
        #endif
    }
    return false;
}
#endif
