#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_off();
void fur_elise();
void sound_up();
void play_sound(short sound, char switch_num);

extern const unsigned short furElise[24];

#endif
