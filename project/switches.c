#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_s1_state, switch_s2_state, switch_s3_state, switch_s4_state;
char switch_s0_state = 1;

void switch_s0_init()
{
  P1REN |= S0;
  P1OUT |= S0;
  P1IES |= S0;
  P1IE |= S0;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2OUT |= SWITCHES;
  P2IES |= SWITCHES;
  P2IE |= SWITCHES;
}

void switch_interrupt_handler()
{
  char p2val = P2IN;
  switch_s1_state = (p2val & S1) ? 0 : 1;
  switch_s2_state = (p2val & S2) ? 0 : 1;
  switch_s3_state = (p2val & S3) ? 0 : 1;
  switch_s4_state = (p2val & S4) ? 0 : 1;
}

 void switch_s0_interrupt()
 {
   P1OUT ^= LED_RED;
   switch_s0_state = (switch_s0_state == 0) ? 1 : 0;
 }
