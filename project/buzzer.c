#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

void buzzer_init()
{
  timerAUpmode();
  
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR |= BIT6;
}

void buzzer_set_period(short cycles)
{
  P2DIR |= BIT6;
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void buzzer_off(){
  P2DIR &= ~BIT6;
}

static short secCount = 0;
static char index = 0;

void fur_elise()
{
  if (secCount++ >= 125) {
    buzzer_set_period(furElise[index]);
    secCount = 0;
    index = (index + 1) % 24;
    if (index == 0) {
      switch_interrupt_handler();
      buzzer_off();
    }
  }
}

static short sound = 300;

void sound_up()
{
  if (secCount++ >= 50) {
    buzzer_set_period(sound);
    secCount = 0;
    if ((sound += 50) >= 1000) {
      sound = 300;
      switch_interrupt_handler();
      buzzer_off();
    }
  }
}

void play_sound(short sound, char switch_num)
{
  switch_interrupt_handler();
  if (switch_num == 3)
    (switch_s3_state) ? buzzer_set_period(sound) : buzzer_off();
  if (switch_num == 4)
    (switch_s4_state) ? buzzer_set_period(sound) : buzzer_off();
}
