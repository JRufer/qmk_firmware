/**
 * This contains all of the code specific to addressing the oled display
 */
#ifdef OLED_DRIVER_ENABLE
//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
  oled_write_P(qmk_logo, false);
}

//Custom Logo for kb startup
static void render_nininin_logo(void) {
    static const char PROGMEM nininin_logo[] = {
    // 'ninininOL', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x0c, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
    0x00, 0x00, 0x03, 0xc0, 0x00, 0x1e, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x3c, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x1e, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x3c, 0x00,
    0x00, 0x00, 0x03, 0x80, 0x00, 0x1c, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x78, 0x38, 0x00,
    0x00, 0xef, 0x80, 0x07, 0x7c, 0x00, 0x3b, 0xe0, 0x01, 0xdf, 0x00, 0x01, 0xf0, 0x38, 0x78, 0x00, 0x00, 0xff, 0xc7, 0x07, 0xfe, 0x38, 0x3f, 0xf1, 0xc1, 0xff, 0x80, 0x03, 0xe0, 0x38, 0x78, 0x00,
    0x01, 0xff, 0xc7, 0x0f, 0xfe, 0x38, 0x7f, 0xf1, 0xc3, 0xff, 0x80, 0x03, 0xc0, 0x38, 0x70, 0x00, 0x01, 0xfb, 0xc7, 0x0f, 0xde, 0x38, 0x7e, 0xf1, 0xc3, 0xf7, 0x87, 0x07, 0x80, 0x38, 0xf0, 0x00,
    0x01, 0xf3, 0xc7, 0x0f, 0x9e, 0x38, 0x7c, 0xf1, 0xc3, 0xe7, 0x8f, 0x07, 0x80, 0x78, 0xf0, 0x00, 0x03, 0xe3, 0x8f, 0x1f, 0x1c, 0x78, 0xf8, 0xe3, 0xc7, 0xc7, 0x0f, 0x0f, 0x00, 0x70, 0xe0, 0x00,
    0x03, 0xc7, 0x8e, 0x1e, 0x3c, 0x70, 0xf1, 0xe3, 0x87, 0x8f, 0x0e, 0x0f, 0x00, 0xf0, 0xe0, 0x00, 0x03, 0x87, 0x8e, 0x1c, 0x3c, 0x70, 0xe1, 0xe3, 0x87, 0x0f, 0x00, 0x0e, 0x01, 0xe1, 0xe0, 0x70,
    0x07, 0x87, 0x0e, 0x3c, 0x38, 0x71, 0xe1, 0xc3, 0x8f, 0x0e, 0x00, 0x0e, 0x03, 0xe1, 0xc3, 0xf0, 0x07, 0x0f, 0x1e, 0x38, 0x78, 0xf1, 0xc3, 0xc7, 0x8e, 0x1e, 0x00, 0x0f, 0x0f, 0xc1, 0xcf, 0xf0,
    0x07, 0x0f, 0x1c, 0x38, 0x78, 0xe1, 0xc3, 0xc7, 0x0e, 0x1e, 0x00, 0x0f, 0xff, 0x81, 0xff, 0xc0, 0x07, 0x0e, 0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x00, 0x07, 0xfe, 0x01, 0xfe, 0x00,
    0x07, 0x0e, 0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x00, 0x03, 0xf8, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(nininin_logo, sizeOf(nininin_logo));
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    render_nininin_logo();
    oled_write_P(PSTR("Preonic rev3.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            oled_write_P(PSTR("WTF?\n"), false);
    }

    // Host Keyboard LED Status
    //uint8_t led_usb_state = host_keyboard_leds();
    //oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    //oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    //oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_nininin_logo();
    }
}





//fade the display out
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


#endif
