#include "init.h"

void Init_Timer1()
{
	// 16000000 Hz /64 = 250 kHz
	// Therefore we have 250000 "steps" per second
	// - and want 0,25 seconds until next overflow
	OCR1A = 0;
	OCR1B = 0;
	// Timer 1 in Normal Mode and PS = 64
	TCCR1A = 0b11110001;
	TCCR1B = 0b00000011;
	// Enable Timer 1 overflow interrupts
}