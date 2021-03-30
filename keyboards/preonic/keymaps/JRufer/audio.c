#include "muse.h"
/**
 * This contains all of the code specific to custom audio work
 */
#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8}
};
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_game[][2]    = {
  {NOTE_E6, 10}   ,{NOTE_E6, 10}  ,{NOTE_REST, 10} ,{NOTE_E6, 10}   ,
  {NOTE_REST, 10} ,{NOTE_C6, 10}  ,{NOTE_E6, 10}   ,{NOTE_REST, 10} ,
  {NOTE_G6, 10}   ,{NOTE_REST, 30},
  {NOTE_G5, 10}   ,{NOTE_REST, 30}
};
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

float tone_coin[][2] = SONG(COIN);
float tone_one_up[][2] = SONG(ONE_UP);
float tone_sonic_ring[][2] = SONG(SONIC);
float tone_zelda[][2] = SONG(ZELDA);

//void audio_startup_custom() {
//  PLAY_SONG(tone_startup);
//}
//void audio_shutdown() {
//  PLAY_SONG(tone_goodbye);
//  stop_all_notes();
//}


void music_on_user(void) {
  music_scale_user();
}
void music_scale_user(void) {
  PLAY_SONG(music_scale);
}


#endif
