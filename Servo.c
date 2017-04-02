/*
 * Servostyring.c
 *
 * Created: 01-04-2017 18:34:12
 * Author: The One and Only
 * Minimum delay for step = 3 ms
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "Servo.h"

void rotateRight()
{
	DDRA = 0xFF;
	PORTA = 0b00000001;
	int steps;
	// 45 deg right
	steps = 1023 / 16;
	while (steps > 0)
	{
		goForward();
		steps--;
	}
}

void rotateLeftFromRight()
{
	DDRA = 0xFF;
	PORTA = 0b00000001;
	int steps;
	// 90 deg left
	steps = 1023 / 8;
	while (steps > 0)
	{
		goBackwards();
		steps--;
	}
}

void rotateMiddleFromLeft()
{
	DDRA = 0xFF;
	PORTA = 0b00000001;
	int steps;
	// 45 deg right
	steps = 1023 / 16;
	while (steps > 0)
	{
		goForward();
		steps--;
	}
}


void goForward()
{
	PORTA = 0b00000001;
	_delay_us(3000);
	PORTA = 0b00000011;
	_delay_us(3000);
	PORTA = 0b00000010;
	_delay_us(3000);
	PORTA = 0b00000110;
	_delay_us(3000);
	PORTA = 0b00000100;
	_delay_us(3000);
	PORTA = 0b00001100;
	_delay_us(3000);
	PORTA = 0b00001000;
	_delay_us(3000);
	PORTA = 0b00001001;
	_delay_us(3000);	
}

void goBackwards()
{
	PORTA = 0b00001001;
	_delay_us(3000);
	PORTA = 0b00001000;
	_delay_us(3000);
	PORTA = 0b00001100;
	_delay_us(3000);
	PORTA = 0b00000100;
	_delay_us(3000);
	PORTA = 0b00000110;
	_delay_us(3000);
	PORTA = 0b00000010;
	_delay_us(3000);
	PORTA = 0b00000011;
	_delay_us(3000);
	PORTA = 0b00000001;
	_delay_us(3000);
}