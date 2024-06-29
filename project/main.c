#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void main(void)
{
  configureClocks();
  
  buzzer_init();
  buzzer_set_period(3033.75);

  or_sr(0x18);
}
