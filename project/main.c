#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void main(void)
{
  configureClocks();
  enableWDTInterrupts();
  
  buzzer_init();

  or_sr(0x18);
}

static short secCount = 0;

void __interrupt_vec(WDT_VECTOR) WDT() /*250 interrupts/sec */
{
  if (secCount >= 2000) {
    buzzer_off();
    secCount = 0;
  }
  if (secCount >= 500) {
    buzzer_set_period(3033.75);
  }
  secCount++;
}
