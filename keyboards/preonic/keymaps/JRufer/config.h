


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
    }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#define AUTO_SHIFT_TIMEOUT 350

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK

// wait DELAY ms before unregistering media keys
#define MEDIA_KEY_DELAY 10
#define TAP_CODE_DELAY 10

#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10

#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }
#define ENCODER_DIRECTION_FLIP

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 350

#define TEMPO_DEFAULT 120
#define COIN \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),

#define ONE_UP \
    Q__NOTE(_E6  ),  \
    Q__NOTE(_G6  ),  \
    Q__NOTE(_E7  ),  \
    Q__NOTE(_C7  ),  \
    Q__NOTE(_D7  ),  \
    Q__NOTE(_G7  ),

#define SONIC \
    E__NOTE(_E6),  \
    E__NOTE(_G6),  \
    HD_NOTE(_C7),

#define ZELDA \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),
