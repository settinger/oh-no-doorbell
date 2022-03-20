/*
 * flood.h
 * "Theme From Flood" by They Might Be Giants
 * Based on the score found here:
 * https://musescore.com/user/29754868/scores/6203268
 *
 * Created: 3/19/2022 11:11:30 PM
 *  Author: Sam Ettinger <ettingersam@gmail.com>
 */ 


#ifndef SONG_H_
#define SONG_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "scale.h"

#define VOICES 2

// 115 BPM, so a quarter note is approximately 64 tone cycles
#define s  16 // sixteenth note
#define e  32 // eighth note
#define q  64 // quarter note
#define h 128 // half note
#define w 255 // whole note

// Melody notes and lengths
const uint8_t notes0[] PROGMEM = {
//      Why  is the world in love   a-gain?
	XX, E4, Fs4, Gs4, A4, B4, Gs4, A4, Fs4,
//      Why are  we mar-ching hand in hand?
	XX, E4, Fs4, Gs4, A4, B4, Gs4, A4, Cs5,
//      Why  are  the   o-cean  le-vels  ri-sing  up?
	XX, Fs4, Gs4, Bb4, B4, Cs5, As4, B4, Cs5, D5, B4,
//  It's a brand new  re-cord  for nine-teen-nine-ty,
	A4, B4, Cs5, Cs5, Cs5, A4, B4, Cs5, Cs5, Cs5, A4,
// They Might Be Gi-ants' brand new al-bum FLOOD
	D5, D5, Cs5, D5, Cs5, D5, Cs5, D5, E5, E5, XX
};
const uint8_t times0[] PROGMEM = {
	h+e, e, e, e, q, q, q, q, h,
	e, e, e, e, q, q, q, q, h,
	e, e, e, e, q, q, q, q, q, q, q,
	e, e, q, q, e, q, e, q, q, e, q+e,
	e, q, e, q, q, q, q, q, q, w, w
};

// Harmony notes and lengths
// Bb trumpet line 2 from the above source
// Transposed into concert tuning and changing the last two measures because they sounded funny to me (maybe I made them worse, idk)
const uint8_t notes1[] PROGMEM = {
	XX, As3, D4, D4, XX, As3, As3, A3, A3, As3, D4, D4,
	XX, B3, B3, B3, B3, C4, B3, As3, A3, F4, F4, F4, D4,
	F4, F4, F4, D4, Eb4, Eb4, D4, Eb4, D4, Bb4, A4, E4, XX
};

const uint8_t times1[] PROGMEM = {
	w, h, q, q, e, q, e, q, q, h, q, q,
	e, q, e, q, q, h, h, h, h, q, q, e, q+e,
	q, q, e, q+e, e, q, e, q, q, h, h, w, w
};

#define SONG_LENGTH sizeof(notes0) / sizeof(notes0[0]) // Length of the *melody* line; when melody ends the chip shuts off

#undef s
#undef e
#undef q
#undef h
#undef w

#endif /* SONG_H_ */