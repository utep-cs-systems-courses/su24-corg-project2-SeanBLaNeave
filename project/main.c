#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"

void main(void)
{
  configureClocks();
  enableWDTInterrupts();
  
  buzzer_init();
  switch_init();
  switch_s0_init();
  led_init();

  or_sr(0x18);
}

void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

void __interrupt_vec(PORT1_VECTOR) Port_1()
{
  if (P1IFG & S0) {
    P1IFG &= ~S0;
    switch_s0_interrupt();
    switch_interrupt_handler();
  }
}

void __interrupt_vec(WDT_VECTOR) WDT() /*250 interrupts/sec */
{
  if (switch_s0_state) {
    if (switch_s1_state)
      fur_elise();
    if (switch_s2_state)
      sound_up();
    if (switch_s3_state)
      play_sound(1000, 3);
    if (switch_s4_state)
      play_sound(1200, 4);
  } else {
    if (switch_s1_state)
      led_dim_to_bright();
    if (switch_s2_state)
      led_bright_to_dim();
    if (switch_s3_state)
      turn_on_green();
    if (switch_s4_state)
      led_blink();
  }
}
