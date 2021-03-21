#include QMK_KEYBOARD_H
#include "muse.h"
#include "../../preonic.h"
#include "config.h"


enum preonic_layers {
  _QWERTY = 0,
  _GAME = 1,
  _LOWER = 2,
  _RAISE = 3,
  _SYSTEM = 4
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  SYSTEM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |MU_TOG| RAISE|    Space    |LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_LALT, AU_TOG,  RAISE,   KC_SPC,  KC_SPC,  LOWER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower - Programming
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   (  |   )  |   -  |   =  |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   }  |   ;  |   '  |      |      |      |      |      |      | Home |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   [  |   ]  |   ,  |   .  |   /  |      |      |      |      |      | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME |      |      |      |      |             |      | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  _______, _______, _______, _______, _______, _______, KC_DEL,  \
  _______, KC_LCBR, KC_RCBR, KC_SCLN, KC_QUOT, _______, _______, _______, _______, _______, _______, KC_HOME, \
  KC_LSFT, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______, _______, _______, _______, _______, KC_END, \
  GAME,    KC_LT,   KC_GT,   _______, KC_TRNS, _______, _______, KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT \
),

/* Raise - SETTINGS
 * ,-----------------------------------------------------------------------------------.
 * |      | RESET| DEBUG|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  RESET,   KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  DEBUG,   _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, KC_7,    KC_8,    KC_9,    KC_F12, \
  _______, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, KC_4,    KC_5,    KC_6,    _______, \
  _______, BL_STEP, RGB_MOD, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ENT, \
  GAME,    BL_TOGG, RGB_TOG, _______, KC_TRNS, _______, _______, KC_TRNS, KC_0,    KC_DOT,  _______, KC_ENT \
),

/* GAME
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      | ESC  |   [   |   ] |  1   |  2   |  3   |   M  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | PgUp |   T  |  R   |  Q   |  W   |  E   |  Y   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | PgDn |   G  |  F   |   A  |   S  |   D  |  H   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   B  |  UP  |   Z  |  X   |  C   | ENTR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |      | LEFT | DOWN | RIGHT|  0   |  .   | ENTR |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid( \
  KC_ESC,  _______, _______, _______, KC_ESC,  KC_LBRC, KC_RBRC, KC_Q,    KC_1,    KC_2,    KC_3,    KC_M,    \
  _______, _______, _______, _______, _______, KC_PGUP, KC_T,    KC_Q,    KC_Q,    KC_W,    KC_E,    KC_Y,    \
  _______, _______, _______, _______, _______, KC_PGDN, KC_G,    KC_Q,    KC_A,    KC_S,    KC_D,    KC_H,    \
  _______, _______, _______, _______, _______, _______, KC_B,    KC_UP,   KC_Z,    KC_X,    KC_C,    KC_ENT,    \
  QWERTY,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_0,    KC_DOT,  KC_ENT    \
)
};

#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};
float tone_colemak[][2] = SONG(COLEMAK_SOUND);
float tone_game[][2]    = {
  {NOTE_E6, 10}   ,{NOTE_E6, 10}  ,{NOTE_REST, 10} ,{NOTE_E6, 10}   ,
  {NOTE_REST, 10} ,{NOTE_C6, 10}  ,{NOTE_E6, 10}   ,{NOTE_REST, 10} ,
  {NOTE_G6, 10}   ,{NOTE_REST, 30},
  {NOTE_G5, 10}   ,{NOTE_REST, 30}
};
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

void startup_user() {
  PLAY_SONG(tone_startup);
}
void shutdown_user() {
  PLAY_SONG(tone_goodbye);
  stop_all_notes();
}

void music_on_user(void) {
  music_scale_user();
}
void music_scale_user(void) {
  PLAY_SONG(music_scale);
}

#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
     clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
}
#endif  // ENCODER_ENABLE

void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
  startup_user();
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_colemak);
        #endif
        layer_move(_QWERTY);
      }
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_game);
        #endif
        layer_move(_GAME);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);

      } else {
        layer_off(_RAISE);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);

      } else {
        layer_off(_LOWER);
      }
      break;
    default:
      return true;
  }

  return false;
};



