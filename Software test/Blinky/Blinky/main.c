/*
 * Blinky.c
 *
 * Created: 17/03/2020 14:56:26
 * Author : elias
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= (1 << DDB0);
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1 << PORTB0);
		_delay_ms(100);
		PORTB &= ~(1 << PORTB0);
		_delay_ms(100);

		
		
    }
	return(0);
}

