/*
 * goose.cpp
 *
 * Created: 3/20/2022 10:54:02 PM
 *  Author: Sam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "honk.h"

uint8_t interruptCounter = 0;       // Just counts from 0 to 3 so we know when 4 of the 32k pulses have elapsed
uint16_t pointer = 0;               // Which sample we are on (start 500 samples from overflowing to give 1/8 of a second pause before starting)
uint8_t fade_in = 0x70;
uint8_t fade_out = 0;

int main(void)
{
	CCP = 0xD8;                          // Enable clock speed change
	CLKPSR = 0;                          // Clock speed 8 MHz
	
	DDRB = 1 << DDB0;                    // PB0 as output
	
	TCCR0A = 2 << WGM00 | 2 << COM0A0;   // Fast PWM ICR0 high | Clear OCOA on compare match
	TCCR0B = 3 << WGM02 | 1 << CS00;     // Fast PWM ICR0 high | No prescaling
	ICR0 = 256;                          // Interrupt every 250ish cycles (nominally 32k interrupts per second) (I made it 256 instead of 250 to make 2-voice mixing a little easier)
	OCR0A = 0x70;                         // The compare value that sets duty cycle of PB0 PWM
	
	TIMSK0 = 1 << TOIE0;                 // Enable timer/counter 0 overflow interrupt
	TIFR0 |= 1 << TOV0;                  // Clear TC0 interrupt flag
	sei();                               // Enable interrupts
	
	set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Tell chip to shut down if sleep command is issued
	
    while (1) 
    {
    }
}

// Interrupt occurs 32k(-ish) times per second
// On the (8*n)th interrupt, we need a new sample from the left 4 bits of the current byte
// On the (8*n + 4)th interrupt, we need a new sample from the right 8 bits of the current byte
ISR(TIM0_OVF_vect) {
	if (fade_out > 0) {
		OCR0A = --fade_out;
		if (fade_out == 0) {
			sleep_enable();
			sleep_cpu();
		}
	} else if (fade_in > 0) {
		OCR0A = --fade_in;
	} else {
		interruptCounter = (interruptCounter+1) & 7;
		if (interruptCounter == 0) {
			pointer++;
			if (pointer >= HONK_LENGTH) {
				fade_out = 0x70;
			} else {
				OCR0A = honk[pointer] & 0xF0;
			}
		} else if (interruptCounter == 4) {
			OCR0A = (honk[pointer] & 0x0F) << 4;
		}
	}
}