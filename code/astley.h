/*
 * astley.h
 * The chorus from Never Gonna Give You Up by Rick Astley, you know the one
 *
 * Created: 3/19/2022 10:39:49 PM
 *  Author: Sam Ettinger <ettingersam@gmail.com>
 */

#ifndef SONG_H_
#define SONG_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "scale.h"

#define VOICES 1

// 114 BPM, so a quarter note is approximately 64 tone cycles
#define s  16 // sixteenth note
#define e  32 // eighth note 
#define q  64 // quarter note
#define h 128 // half note
#define w 255 // whole note

const uint8_t notes0[] PROGMEM = {
//      Ne-ver  gon-na  give you  up, ne-ver  gon-na let you down,
	XX, A4, B4, D5, B4, Fs5, Fs5, E5, A4, B4, D5, B4, E5, E5, D5,
//  Ne-ver  gon-na  run  a--ro--und'n'de-sert you
	A4, B4, D5, B4, D5, E5, Cs5, A4, A4, E5, D5, XX
};

const uint8_t times0[] PROGMEM = {
	h, s, s, s, s, e+s, e+s, q+e, s, s, s, s, e+s, e+s, q+e,
	s, s, s, s, q, e, q, q, e, q, h, w
};

#define SONG_LENGTH sizeof(notes0) / sizeof(notes0[0]) // When array ends, the chip shuts off

#undef s
#undef e
#undef q
#undef h
#undef w

#endif /* SONG_H_ */