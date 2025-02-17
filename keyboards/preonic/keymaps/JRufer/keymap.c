#include QMK_KEYBOARD_H
#include "../../preonic.h"
#include "config.h"
#include "audio.c"
#include "oled.c"
#include "rgb.c"


enum preonic_layers {
  _QWERTY = 0,
  _GAME = 1,
  _LOWER = 2,
  _RAISE = 3,
  _ADJUST = 4
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  ADJUST,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Lead | LOWER|    Space    |RAISE | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_1x2uC( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LEAD, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Raise - Programming
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   (  |   )  |   -  |   =  |      |      |      |      |  _   |   =  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   }  |   ;  |   '  |      |      |      |      |      |   \  | Home |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   [  |   ]  |   ,  |   .  |   /  |      |      |      |      |   /  | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME |   <  |   >  |      |      |             |      | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_1x2uC( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  _______, _______, _______, _______, KC_UNDS, KC_EQL,  KC_DEL,  \
  _______, KC_LCBR, KC_RCBR, KC_SCLN, KC_QUOT, _______, _______, _______, _______, _______, KC_BSLS, KC_HOME, \
  KC_LSFT, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______, _______, _______, _______, KC_SLSH, KC_END, \
  GAME,    KC_LT,   KC_GT,   _______, KC_TRNS,      _______,     KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | RESET|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      |  INS | HOME | PGDN |  7   |  8   |  9   |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | DEBUG|      |      |      |      |  DEL | END  | PGUP |  4   |  5   |  6   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |BLSEP |RGBMOD|      |      |      |      |      |  1   |  2   |  3   | ENTR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME |BLTOG |RGBTOG|      |      |             |      |  0   |  .   |      | ENTR |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_1x2uC( \
  RESET,   KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  RESET,   _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, KC_7,    KC_8,    KC_9,    KC_F12,  \
  DEBUG,   _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, KC_4,    KC_5,    KC_6,    _______, \
  _______, BL_STEP, RGB_MOD, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ENT,  \
  GAME,    BL_TOGG, RGB_TOG, _______, KC_TRNS,     _______,      KC_TRNS, KC_0,    KC_DOT,  _______, KC_ENT   \
),

/* GAME
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      | ESC  |   5   |  4  |  1   |  2   |  3   |   M  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | PgUp |   T  |  R   |  Q   |  W   |  E   |  I   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | 5MIN | SSVID|      |      | PgDn |   G  |  F   |   A  |   S  |   D  |  H   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |GFSS  |  F12 | GFPHO|      |  N   |   B  |  V   |   Z  |  X   |  C   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|      |      |      | left |    space    | DOWN | RIGHT|  0   |  .   | ENTR |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_1x2uC( \
  KC_ESC,  _______,       _______,    _______,     _______, KC_ESC,  KC_5,    KC_4,    KC_1,    KC_2,    KC_3,    KC_M,    \
  _______, _______,        _______,   _______,     _______, KC_PGUP, KC_T,    KC_R,    KC_Q,    KC_W,    KC_E,    KC_I,    \
  _______, LCTL(KC_PGUP), LALT(KC_Y), _______,     _______, KC_PGDN, KC_G,    KC_F,    KC_A,    KC_S,    KC_D,    KC_H,    \
  _______, LCTL(KC_HOME), KC_F12,     LALT(KC_F2), _______, KC_N,    KC_B,    KC_V,    KC_Z,    KC_X,    KC_C,    KC_SLSH, \
  QWERTY,  _______,       _______,    _______,     KC_LEFT,      KC_SPC,      KC_DOWN, KC_RGHT, KC_0,    KC_DOT,  KC_ENT   \
),

/* adjust ( LOWER + RAISE )
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ASTG |Voice-|Voice+|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MU_TOG|MU_MOD|      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_1x2uC( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_ASTG, MUV_DE,  MUV_IN,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, MU_TOG,  MU_MOD,  _______, _______,      _______,     _______, _______, _______, _______, _______ \
)
};

//kb startup custom code
void startup_user() {
    #ifdef AUDIO_ENABLE
    PLAY_SONG(tone_one_up);
    #endif
}
//kb shutdown custom code
void shutdown_user() {
    #ifdef AUDIO_ENABLE
    //PLAY_SONG(GOODBYE_SONG);
    #endif
}

// hook into kb startup
void matrix_init_user(void) {
  startup_user();
}

bool did_leader_succeed;
#ifdef AUDIO_ENABLE
float leader_s[][2] = SONG(ONE_UP_SOUND);
float leader_succeed[][2] = SONG(ALL_STAR);
float leader_fail[][2] = SONG(RICK_ROLL);
#endif
LEADER_EXTERNS();
// Scope out Leader paterns
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
      did_leader_succeed = leading = false;

        SEQ_ONE_KEY(KC_C) {
            // Copy
            SEND_STRING(SS_LCTL("c"));
            did_leader_succeed = true;
        } else
        SEQ_ONE_KEY(KC_V) {
            // Paste
            SEND_STRING(SS_LCTL("v"));
            did_leader_succeed = true;
        }
        leader_end();
    }
}

void leader_start(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_s);
#endif
}

void leader_end(void) {
  if (did_leader_succeed) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_succeed);
#endif
  } else {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_fail);
#endif
  }
}

// custom behavior for encoder interaction
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(default_layer_state)) {
        case _LOWER:
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP); // Cycle Tabs in Chrome
            break;
        case _RAISE:
            clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT); // Alt left and right
            break;
        case _ADJUST:
            break;
        default:
            clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU); // Adjust volume
            break;
    }
}
#endif  // ENCODER_ENABLE


// key intercept to assign custom behavior
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_move(_QWERTY);

      }
      break;
    case GAME:
      if (record->event.pressed) {
        layer_move(_GAME);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    default:
      return true;
  }
  return false;
};

//custom actions on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0xFF);
        break;
    case _RAISE:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _ADJUST:
        rgblight_setrgb (0x00,  0x00, 0x00);
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_coin);
        #endif
        break;
    case _GAME:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_one_up);
        #endif
        break;
    case _QWERTY: //the default layer
        rgblight_setrgb (0xFF,  0xFF, 0xFF);
        break;
    }
    return state;
}

void keyboard_post_init_user(){
    rgblight_setrgb (0xFF,  0xFF, 0xFF);
    rgblight_mode(1);

    #ifdef OLED_DRIVER_ENABLE
    render_logo();
    #endif
}
