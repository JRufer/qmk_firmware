#include QMK_KEYBOARD_H
#include "muse.h"
#include "../../preonic.h"
#include "config.h"


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
  ADJUST
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
 * | Ctrl | GUI  | Alt  |MU_TOG| LOWER|    Space    |RAISE | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_LALT, AU_TOG,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Raise - Programming
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   (  |   )  |   -  |   =  |      |      |      |      |  _   |   =  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   }  |   ;  |   '  |      |      |      |      |      |      | Home |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   [  |   ]  |   ,  |   .  |   /  |      |      |      |      |      | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME |      |      |      |      |             |      | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  _______, _______, _______, _______, KC_UNDS, KC_EQL,  KC_DEL,  \
  _______, KC_LCBR, KC_RCBR, KC_SCLN, KC_QUOT, _______, _______, _______, _______, _______, _______, KC_HOME, \
  KC_LSFT, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______, _______, _______, _______, _______, KC_END, \
  GAME,    KC_LT,   KC_GT,   _______, KC_TRNS, _______, _______, KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT \
),

/* Lower - SETTINGS
 * ,-----------------------------------------------------------------------------------.
 * | RESET|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | DEBUG|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  RESET,   KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  RESET,   _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, KC_7,    KC_8,    KC_9,    KC_F12,  \
  DEBUG,   _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, KC_4,    KC_5,    KC_6,    _______, \
  _______, BL_STEP, RGB_MOD, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_ENT,  \
  GAME,    BL_TOGG, RGB_TOG, _______, KC_TRNS, _______, _______, KC_TRNS, KC_0,    KC_DOT,  _______, KC_ENT   \
),

/* GAME
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      | ESC  |   5   |  4  |  1   |  2   |  3   |   M  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | PgUp |   T  |  R   |  Q   |  W   |  E   |  I   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | PgDn |   G  |  F   |   A  |   S  |   D  |  H   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |  N   |   B  |  V   |   Z  |  X   |  C   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|MU_TOG|MU_MOD|      | left |    space    | DOWN | RIGHT|  0   |  .   | ENTR |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid( \
  KC_ESC,  _______, _______, _______, _______, KC_ESC,  KC_5,    KC_4,    KC_1,    KC_2,    KC_3,    KC_M,    \
  _______, _______, _______, _______, _______, KC_PGUP, KC_T,    KC_R,    KC_Q,    KC_W,    KC_E,    KC_I,    \
  _______, _______, _______, _______, _______, KC_PGDN, KC_G,    KC_F,    KC_A,    KC_S,    KC_D,    KC_H,    \
  _______, _______, _______, _______, _______, KC_N,    KC_B,    KC_V,    KC_Z,    KC_X,    KC_C,    KC_SLSH, \
  QWERTY,  MU_TOG,  MU_MOD,  _______, KC_LEFT, _______, KC_SPC,  KC_DOWN, KC_RGHT, KC_0,    KC_DOT,  KC_ENT   \
),

/* adjust
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, _______, _______, _______, _______ \
)
};

#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
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
    if (get_mods() & MOD_MASK_CTRL)
        clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP); // Cycle Tabs in Chrome
    else if (get_mods() & MOD_MASK_ALT)
        clockwise ? tap_code(KC_LEFT) : tap_code(KC_RIGHT); // Alt left and right
    else
        clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU); // Adjust volume
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
        autoshift_enable();
      }
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_game);
        #endif
        layer_move(_GAME);
        autoshift_disable();
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);

      } else {
        layer_off(_ADJUST);
      }
      break;
    default:
      return true;
  }

  return false;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0xFF);
        break;
    case _RAISE:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _GAME:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    default: //  for any other layers, or the default layer
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

#ifdef OLED_DRIVER_ENABLE
//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}

//Custom Logo for display
static void render_logo(void) {
    static const char PROGMEM logo[] = {
        // 'ninininOL', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x80, 0x00, 0x0c, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
0x00, 0x00, 0x03, 0xc0, 0x00, 0x1e, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x3c, 0x00,
0x00, 0x00, 0x03, 0xc0, 0x00, 0x1e, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x3c, 0x00,
0x00, 0x00, 0x03, 0x80, 0x00, 0x1c, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x38, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x78, 0x38, 0x00,
0x00, 0xef, 0x80, 0x07, 0x7c, 0x00, 0x3b, 0xe0, 0x01, 0xdf, 0x00, 0x01, 0xf0, 0x38, 0x78, 0x00,
0x00, 0xff, 0xc7, 0x07, 0xfe, 0x38, 0x3f, 0xf1, 0xc1, 0xff, 0x80, 0x03, 0xe0, 0x38, 0x78, 0x00,
0x01, 0xff, 0xc7, 0x0f, 0xfe, 0x38, 0x7f, 0xf1, 0xc3, 0xff, 0x80, 0x03, 0xc0, 0x38, 0x70, 0x00,
0x01, 0xfb, 0xc7, 0x0f, 0xde, 0x38, 0x7e, 0xf1, 0xc3, 0xf7, 0x87, 0x07, 0x80, 0x38, 0xf0, 0x00,
0x01, 0xf3, 0xc7, 0x0f, 0x9e, 0x38, 0x7c, 0xf1, 0xc3, 0xe7, 0x8f, 0x07, 0x80, 0x78, 0xf0, 0x00,
0x03, 0xe3, 0x8f, 0x1f, 0x1c, 0x78, 0xf8, 0xe3, 0xc7, 0xc7, 0x0f, 0x0f, 0x00, 0x70, 0xe0, 0x00,
0x03, 0xc7, 0x8e, 0x1e, 0x3c, 0x70, 0xf1, 0xe3, 0x87, 0x8f, 0x0e, 0x0f, 0x00, 0xf0, 0xe0, 0x00,
0x03, 0x87, 0x8e, 0x1c, 0x3c, 0x70, 0xe1, 0xe3, 0x87, 0x0f, 0x00, 0x0e, 0x01, 0xe1, 0xe0, 0x70,
0x07, 0x87, 0x0e, 0x3c, 0x38, 0x71, 0xe1, 0xc3, 0x8f, 0x0e, 0x00, 0x0e, 0x03, 0xe1, 0xc3, 0xf0,
0x07, 0x0f, 0x1e, 0x38, 0x78, 0xf1, 0xc3, 0xc7, 0x8e, 0x1e, 0x00, 0x0f, 0x0f, 0xc1, 0xcf, 0xf0,
0x07, 0x0f, 0x1c, 0x38, 0x78, 0xe1, 0xc3, 0xc7, 0x0e, 0x1e, 0x00, 0x0f, 0xff, 0x81, 0xff, 0xc0,
0x07, 0x0e, 0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x00, 0x07, 0xfe, 0x01, 0xfe, 0x00,
0x07, 0x0e, 0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x00, 0x03, 0xf8, 0x00, 0xf8, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(logo, sizeOf(logo));

}
#endif
