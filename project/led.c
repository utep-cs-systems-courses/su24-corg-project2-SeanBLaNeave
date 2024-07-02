#include <msp430.h>
#include "switches.h"
#include "led.h"

void led_init()
{
  P1DIR |= LED;
  P1OUT &= ~LED;
}

static char blinkLimit = 7;
static char blinkCount = 0;
static short secCount = 0;

void led_dim_to_bright()
{
  if (blinkCount++ >= blinkLimit) {
    blinkCount = 0;
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
  if (secCount++ >= 250) {
    secCount = 0;
    if (blinkLimit-- <= 0) {
      blinkLimit = 7;
      P1OUT &= ~LED_GREEN;
      switch_interrupt_handler();
    }
  }
}

static char blinkDim = 0;

void led_bright_to_dim()
{
  if (blinkCount++ >= blinkDim) {
    blinkCount = 0;
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
  if (secCount++ >= 250) {
    secCount = 0;
    if (blinkDim++ >= 7) {
      blinkDim = 0;
      P1OUT &= ~LED_GREEN;
      switch_interrupt_handler();
    }
  }
}

static char count = 0;

void turn_on_green()
{
  if (secCount++ >= 125) {
    secCount = 0;
    P1OUT ^= LED_GREEN;
    if (count++ >= 10) {
      count = 0;
      P1OUT &= ~LED_GREEN;
      switch_interrupt_handler();
    }
  }
}
