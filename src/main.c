
/*
https://docs.arduino.cc/static/6ec5e4c2a6c0e9e46389d4f6dc924073/2f891/Pinout-UNOrev3_latest.png
https://www.microchip.com/en-us/product/ATmega328p
https://components101.com/sites/default/files/component_datasheet/Joystick%20Module.pdf
https://github.com/tomas-fryza/digital-electronics-2
hlava ŠIMONA BUCHTY a  ŠTĚPÁNA VEČEŘI 
ŠIMON BUCHTA MAESTRO ZAPOJENÍ
*/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <gpio.h>           // gpio
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions
#include <lcd.h>            // Peter Fleury's LCD library

static uint8_t axis = 0;      //axis determines if we measure X or Y value of 0 means x, 1 means y
static uint8_t posx = 0;
static uint8_t posy = 0;
int Val;
static uint8_t lastA;
static uint8_t currA;      //encoder CLK 
static uint8_t B;     //encoder DT
static int8_t counter = 64; 
static int8_t lastcounter = 64;
static int8_t button = 1;

int main(void)
{
    // Initialize USART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, F_CPU));

    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);

    // Select input channel ADC0 (voltage divider pin)
    ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3));
    // Select input channel ADC1
    //ADMUX &= ~ ((1<<MUX1) | (1<<MUX2) | (1<<MUX3)); ADMUX |= (1<<MUX0);
    // Enable ADC module
    ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= ((1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));

    // Configure 16-bit Timer/Counter1 to test one I2C address
    // Set prescaler to 33 ms and enable interrupt
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();

    TIM2_overflow_2ms();
    TIM2_overflow_interrupt_enable();
    // Enables interrupts by setting the global interrupt mask
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);
    lcd_gotoxy(0, 0);                 //starting position is left up

    GPIO_mode_input_nopull(&DDRB, PB4);      //encoder DT
    GPIO_mode_input_nopull(&DDRB, PB5);      //encoder clock
    GPIO_mode_input_pullup(&DDRB, PB3);         //switch

    lastA = GPIO_read(&PINB, PB5);

    sei();
    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


ISR(TIMER1_OVF_vect)
{ 
  static uint8_t no_of_overflows = 0;
  no_of_overflows ++;
  if (no_of_overflows >= 5)
  {
    no_of_overflows =0;
   // ADCSRA |= (1<<ADSC);

    if (axis == 0)
    {
      ADMUX |= (1<<MUX0);
      axis = 1;
    }
    else if (axis == 1)
    {
       ADMUX &= ~(1<<MUX0); 
       axis = 0;
    }
    ADCSRA |= (1<<ADSC);
  }
}

ISR(ADC_vect)
{
 Val = ADC;

if (axis == 0)
    {
      if (Val <10){                 //go right
        posx = posx + 1;   
        counter = 65;         
        if (posx == 16){            //there is only 15 positions on the display
          posx = 0;
        }
      }
     else if (Val > 900){            //go left
        if (posx  == 0){           
          posx = 15;
          counter = 65;
        }
        else {
          posx = posx - 1;
          counter = 65;
        }
        }
    }

if (axis == 1)
    {
      if (Val <10){             //go down
        if (posy == 0){
          posy = 1;
          counter = 65;
        }
        else {
          posy = 0;
          counter = 65;
        }
        
      }
     else if (Val > 900){       //go up
        if (posy == 0){
          posy = 1;
          counter = 65;
        }
        else {
          posy = 0;
          counter = 65;
        }
      }
      }
lcd_gotoxy(posx, posy);
} 

ISR(TIMER2_OVF_vect){
  //char string[8];
  currA = GPIO_read(&PINB, PB5);
  B = GPIO_read(&PINB, PB4);

  if (currA != lastA  && currA == 1){
    if (B != currA){
      counter ++;                   //rotating clockwise adds to counter
    }
    else {
      counter --;                   //rotating counter clockwise decreases counter
    }
  }

  lastA = currA;

  button = GPIO_read(&DDRB, PB3); 

  if (counter != lastcounter){
    //itoa(counter, string, 10);
    lcd_gotoxy(posx, posy);
    //lcd_puts(string);
    lcd_putc(counter);
    lastcounter = counter;
  }
}
