/*
 * ATtiny4/5/9/10 3-pin doorbell circuit
 * Upon powering up, PB0 (pin 1) outputs a tune and when it's done the chip shuts off.
 * One or two voices, square waves only
 *
 * Created: 3/19/2022 10:12:55 PM
 * Author : Sam Ettinger <ettingersam@gmail.com>
 * "The absence of limitation is the enemy of art" -- Orson Welles (apocryphal)
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>



// Choose one of the following tunes to insert, or add your own:
// (Whichever one is defined first will get used below, comment out the others)
//#include "frerejacques.h"
#include "flood.h"
//#include "astley.h"


uint8_t interruptCounter = 0;       // Just counts from 0 to 3 so we know when 4 of the 32k pulses have elapsed
uint8_t songPointer0 = 0;           // Which note in the song array we are on (should make this an int probably)
uint16_t noteAccumulator0 = 0;      // We add the value of note0/note1 to whatever's in this int in order to calculate the waveform
uint16_t note0 = 0;                 // A measure of how much to increment the note accumulator at each interrupt
uint16_t duration0 = 0;             // How many 8 ms intervals to hold for (maybe could make this more modular as tempo and beats)

#if VOICES == 2                     // There's probably a better way to do this for additional voices, but will that be applicable ever?
uint8_t songPointer1 = 0;
uint16_t note1 = 0;
uint16_t duration1 = 0;
uint16_t noteAccumulator1 = 0;
#endif

int main(void)
{
	CCP = 0xD8;                          // Enable clock speed change
	CLKPSR = 0;                          // Clock speed 8 MHz
									     
	DDRB = 1 << DDB0;                    // PB0 as output
									     
	TCCR0A = 2 << WGM00 | 2 << COM0A0;   // Fast PWM ICR0 high | Clear OCOA on compare match
	TCCR0B = 3 << WGM02 | 1 << CS00;     // Fast PWM ICR0 high | No prescaling
	ICR0 = 256;                          // Interrupt every 250ish cycles (nominally 32k interrupts per second) (I made it 256 instead of 250 to make 2-voice mixing a little easier)
	OCR0A = 0;                           // The compare value that sets duty cycle of PB0 PWM
									     
	TIMSK0 = 1 << TOIE0;                 // Enable timer/counter 0 overflow interrupt
	TIFR0 |= 1 << TOV0;                  // Clear TC0 interrupt flag
	sei();                               // Enable interrupts
	
	set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Tell chip to shut down if sleep command is issued
	
	while (1)
	{
	}
}

// Interrupt occurs 32k(-ish) times per second
// Add the values note0/note1 to noteAccumulator0/1
// Every 4th interrupt, recalculate values of note0/note1
ISR(TIM0_OVF_vect) {
	// Set PWM duty cycle
	noteAccumulator0 += note0;
	#if VOICES == 2
		noteAccumulator1 += note1;
		OCR0A = ((noteAccumulator0 & 0x8000) >> 8) + ((noteAccumulator1 & 0x8000) >> 8);
	#else
		OCR0A = (noteAccumulator0 & 0x8000) >> 7;
	#endif
	
	// Every fourth interrupt, update value of note0/note1
	interruptCounter = (interruptCounter+1) & 3;
	if (interruptCounter == 0) {
		// If the current note has just ended, fetch the next note
		// If there is no next note, shut down
		// If the current note is in its last 256 cycles, mute the note to mark the transition to next note
		// (to do: find a satisfying value instead of arbitrarily choosing 256; or, make it parametric)
		if (duration0 == 0) {
			if (songPointer0 >= SONG_LENGTH) {
				sleep_enable();
				sleep_cpu();
			}
			duration0 = times0[songPointer0] << 6;
			note0 = scale[notes0[songPointer0]];
			songPointer0++;
		} else if (!(duration0 & 0xFF00)) {
			note0 = 0;
		}
		duration0--;
		
		#if VOICES == 2
		if (duration1 == 0) {
			duration1 = times1[songPointer1] << 6;
			note1 = scale[notes1[songPointer1]];
			songPointer1++;
		} else if (!(duration1 & 0xFF00)) {
			note1 = 0;
		}
		duration1--;
		#endif
	}
}