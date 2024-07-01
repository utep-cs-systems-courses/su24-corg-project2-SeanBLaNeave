#ifndef switches_included
#define switches_included

#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3
#define SWITCHES (S1 | S2 | S3 | S4)

void switch_init();
void switch_interrupt_handler();

extern char switch_s1_state, switch_s2_state, switch_s3_state, switch_s4_state;

#endif
