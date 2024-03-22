#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#define FLAYER 1
#define SPACEFN 2

#define F_LT LT(FLAYER, KC_F)
#define SPCFN LT(SPACEFN, KC_SPC)
#define CTRLESC CTL_T(KC_ESC)

#define KC_LS1 LSFT(KC_1)
#define KC_LS2 LSFT(KC_2)
#define KC_LS3 LSFT(KC_3)
#define KC_LS4 LSFT(KC_4)
#define KC_LS5 LSFT(KC_5)
#define KC_LS6 LSFT(KC_6)
#define KC_LS7 LSFT(KC_7)
#define KC_LS8 LSFT(KC_8)
#define KC_LS9 LSFT(KC_9)
#define KC_LS0 LSFT(KC_0)
#define KC_LSMI LSFT(KC_MINS)
#define KC_LSEQ LSFT(KC_EQL)
#define KC_LSRB LSFT(KC_RBRC)
#define KC_LSNH LSFT(KC_NUHS)

#define KC_RA1 RALT(KC_1)
#define KC_RA2 RALT(KC_2)
#define KC_RA3 RALT(KC_3)
#define KC_RA4 RALT(KC_4)
#define KC_RA5 RALT(KC_5)
#define KC_RA6 RALT(KC_6)
#define KC_RA7 RALT(KC_7)
#define KC_RA8 RALT(KC_8)
#define KC_RA9 RALT(KC_9)
#define KC_RA0 RALT(KC_0)
#define KC_RAMI RALT(KC_MINS)
#define KC_RAEQ RALT(KC_EQL)
#define KC_RARB RALT(KC_RBRC)
#define KC_RANH RALT(KC_NUHS)
#define KC_RANU RALT(KC_NUBS)


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | §      |   1  |   2  |   3  |   4  |   5  |                           |   6  |   7  |   8  |   9  |  0   | ?      |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |  P   | Å      |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |Ctrl/Esc|   A  |   S  |   D  | F_LT |   G  |                           |   H  |   J  |   K  |   L  |  Ö   | Ä      |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,;  |  .:  |  -_  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | <>|  |      |      |      |                                         | ´`   | ¨^~  |  '*  |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Alt  | Ctrl |         | Ctrl |AGr/OS|
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           CTRLESC,KC_A   ,KC_S   ,KC_D   ,F_LT   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_NUBS,KC_NO  ,KC_NO  ,KC_NO  ,
                                   KC_LALT,KC_LCTL,
                                           KC_HOME,
                           KC_BSPC,KC_DEL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SCRL  ,KC_PAUS, KC_NO, QK_BOOT,
    KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
    KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,
    KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
    KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
            KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RCTL,RALT_T(KC_LGUI),
           KC_PGUP,
           KC_PGDN,KC_ENTER ,SPCFN
    ),
[FLAYER] = LAYOUT(
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                   KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                           KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_TRNS,KC_TRNS,
    KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,
           KC_TRNS,
           KC_TRNS,KC_TRNS, KC_SPC
    ),
[SPACEFN] = LAYOUT(
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_GRV, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TRNS,KC_LS1 ,KC_LS2 ,KC_LS3 ,KC_LS4 ,KC_LS5 ,
           KC_TRNS,KC_RA1 ,KC_RA2 ,KC_RA3 ,KC_RA4 ,KC_RA5 ,
                   KC_RANU,KC_LSEQ,KC_LSRB,KC_LSNH,
                                   KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                           KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
    KC_LS6 ,KC_LS7 ,KC_LS8 ,KC_LS9 ,KC_LS0 ,KC_LSMI,
    KC_RA6 ,KC_RA7 ,KC_RA8 ,KC_RA9 ,KC_RA0 ,KC_RAMI,
            KC_LSNH,KC_RARB,KC_RAEQ,KC_TRNS,
            KC_TRNS,KC_TRNS,
            KC_TRNS,
            KC_TRNS,KC_TRNS, KC_TRNS
    )

};
