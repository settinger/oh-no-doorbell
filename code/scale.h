/*
 * scale.h
 * Holds the defined note names and the relative rates of accumulation to achieve the desired frequencies
 *
 * Created: 3/19/2022 10:25:15 PM
 *  Author: Sam Ettinger <ettingersam@gmail.com>
 */ 


#ifndef SCALE_H_
#define SCALE_H_

#include <avr/io.h>
//#include <avr/pgmspace.h>

#define XX   0  // Silence
#define A3   1  //  220.00 Hz   451 added to accumulator on each interrupt
#define As3  2  //  233.08      477
#define Bb3 As3
#define B3   3  //  246.94      506
#define C4   4  //  261.63      536
#define Cs4  5  //  277.18      568
#define Db4 Cs4
#define D4   6  //  293.66      601
#define Ds4  7  //  311.13      637
#define Eb4 Ds4
#define E4   8  //  329.63      675
#define F4   9  //  349.23      715
#define Fs4 10  //  369.99      758
#define Gb4 Fs4
#define G4  11  //  392.00      803
#define Gs4 12  //  415.30      851
#define Ab4 Gs4
#define A4  13  //  440.00      901
#define As4 14  //  466.16      955
#define Bb4 As4
#define B4  15  //  493.88     1011
#define C5  16  //  523.25     1072
#define Cs5 17  //  554.37     1135
#define Db5 Cs5
#define D5  18  //  587.33     1203
#define Ds5 19  //  622.25     1274
#define Eb5 Ds5
#define E5  20  //  659.25     1350
#define F5  21  //  698.46     1430
#define Fs5 22  //  739.99     1515

// Lazy hack
#define Gs3 23
#define G3 24

const uint16_t scale[] = { 0, 451, 477, 506, 536, 568, 601, 637, 675, 715, 758, 803, 851, 901, 955, 1011, 1072, 1135, 1203, 1274, 1350, 1430, 1515,
	// lazy hack
	425, 401
	}; // Should be in progmem maybe?

#endif /* SCALE_H_ */
