/*
 * frerejacques.h
 * Extremely basic demo of two voices, I know there's a much simpler way to encode this specific song, don't @ me
 *
 * Created: 3/19/2022 11:27:48 PM
 *  Author: Sam Ettinger <ettingersam@gmail.com>
 */ 


#ifndef SONG_H_
#define SONG_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "scale.h"

#define VOICES 2

#define e  40 // eighth note
#define q  80 // quarter note
#define h 160 // half note

// Round 1 notes and lengths
// Extremely basic demo of two voices, I know there's a much simpler way to encode this specific song, don't @ me
const uint8_t notes0[] PROGMEM = {XX, F4, G4, A4, F4, F4, G4, A4, F4, A4, Bb4, C5, A4, Bb4, C5, C5, D5, C5, Bb4, A4, F4, C5, D5, C5, Bb4, A4, F4, F4, C4, F4, F4, C4, F4, XX, XX, XX, XX, XX};
const uint8_t times0[] PROGMEM = {h, q, q, q, q, q, q, q, q, q, q, h, q, q, h, e, e, e, e, q, q, e, e, e, e, q, q, q, q, h, q, q, h, h, h, h, h, h};

// Round 2 notes and lengths
const uint8_t notes1[] PROGMEM = {XX, XX, XX, XX, XX, F4, G4, A4, F4, F4, G4, A4, F4, A4, Bb4, C5, A4, Bb4, C5, C5, D5, C5, Bb4, A4, F4, C5, D5, C5, Bb4, A4, F4, F4, C4, F4, F4, C4, F4, XX};
const uint8_t times1[] PROGMEM = {h, h, h, h, h, q, q, q, q, q, q, q, q, q, q, h, q, q, h, e, e, e, e, q, q, e, e, e, e, q, q, q, q, h, q, q, h, h};

#define SONG_LENGTH sizeof(notes0) / sizeof(notes0[0]) // Length of the first line; when that line ends the chip shuts off

#undef e
#undef q
#undef h

#endif /* SONG_H_ */