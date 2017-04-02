#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

void goBackwards();
void goForward();
void rotateRight();
void rotateLeftFromRight();
void rotateMiddleFromLeft();