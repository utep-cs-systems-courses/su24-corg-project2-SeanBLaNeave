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
static char index = 0;

void __interrupt_vec(WDT_VECTOR) WDT() /*250 interrupts/sec */
{
  if (secCount >= 125) {
    buzzer_set_period(furElise[index]);
    secCount = 0;
    index++;
  }
  if (index == 24) {
    index = 0;
  }
  secCount++;
}
