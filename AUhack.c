/********************************************
* MSYS, LAB 13. Del 2                       *
* ADC using "Start on Timer 1 overflow".    *
* Also using ADC interrupts.                *
*                                           *
* Henning Hargaard 27/11 2015               *
*********************************************/
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"
#include "init.h"
#include "motor.h"

volatile int dist = 0;
volatile int distVenstre = 0;
volatile int distHoejre = 0;

void checkWay()
{
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	int sum = 0;
	stop();
	rotateRight();
	_delay_ms(100);
	temp1 = SendPing();
	_delay_ms(10);
	temp2 = SendPing();
	_delay_ms(10);
	temp3 = SendPing();
	sum = temp1+temp2+temp3;
	distHoejre = sum/3;
	_delay_ms(100);
	rotateLeftFromRight();
	_delay_ms(100);
	temp1 = SendPing();
	_delay_ms(10);
	temp2 = SendPing();
	_delay_ms(10);_delay_ms(10);
	temp3 = SendPing();
	sum = temp1+temp2+temp3;
	distVenstre = sum/3;
	_delay_ms(100);
	rotateMiddleFromLeft();
	
	if ((distHoejre < distVenstre) && (distVenstre > 50))
	{
		venstre();
		_delay_ms(2000);
	}
	else if (distHoejre > 50)
	{
		hoejre();
		_delay_ms(2000);
	}
	else
	{
		tilbage();
		_delay_ms(2000);
		checkWay();
	}
	
	stop();
	_delay_ms(100);
}

int SendPing()
{
	int overflow = 0;
	DDRC = 0xFF;
	PORTC = 0;
	_delay_us(2);
	PORTC = 0xFF;
	_delay_us(5);
	PORTC = 0;
	DDRC = 0;
	while (!(PINC & 1))
{}
	while (PINC & 1)
	{
		_delay_us(1);
		overflow++;
	}
	overflow /=29;
	return overflow;
}

int main()
{
	DDRC = 0xFF;
	DDRB = 0xFF;
	Init_Timer1();
	InitUART(9600, 8, 'N', 0);
	
	
	_delay_ms(2000);
	
	frem();
	
	while(1)
	{	
		_delay_ms(100);
		dist = SendPing();
		if(dist < 50)
		{
			checkWay();
			
			frem();
		}
	}
}