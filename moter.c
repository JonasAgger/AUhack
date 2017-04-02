#include "motor.h"

void venstre()
{
	OCR1B = 10;
	//OCR1B = 50;
}

void hoejre()
{
	OCR1A = 10;
	//OCR1B = 50;
}

void frem()
{
	OCR1A = 10;
	OCR1B = 10;
}

void tilbage()
{
	OCR1A = 200;
	OCR1B = 200;
}

void stop()
{
	OCR1A = 0;
	OCR1B = 0;
}