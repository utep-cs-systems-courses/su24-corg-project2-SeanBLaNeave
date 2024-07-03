#ifndef led_included
#define led_included

#define LED_GREEN BIT0
#define LED_RED BIT6
#define LED (LED_GREEN | LED_RED)

void led_init();
void led_dim_to_bright();
void led_bright_to_dim();
void turn_on_green();
void led_blink();
void led_blink_as();

#endif
