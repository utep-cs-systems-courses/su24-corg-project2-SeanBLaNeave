#include <msp430.h>
#include "switches.h"

char switch_s1_state, switch_s2_state, switch_s3_state, switch_s4_state;

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


