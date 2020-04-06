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
#include <stdlib.h>

#define LED1 0
#define LED2 1
#define LED3 2

#define NUMBER_OF_REPEAT 3
#define DELAY1 2
#define DELAY2 5
#define DELAY3 7
#define DELAY4 10

void ch_delay(unsigned char n_delay){
	switch (n_delay)
	{
		case 2:
		_delay_ms(200);
		break;
		case 5:
		_delay_ms(500);
		break;
		case 7:
		_delay_ms(700);
		break;
		case 10:
		_delay_ms(1000);
		break;
	}
}

void init_ports_mcu(){
	DDRB=0xFFu;
	PORTB=0x00u;
	
	DDRC=0xFFu;
	PORTC=0x00u;
	
	DDRD=0xFFu;
	PORTD=0x00u;
	
}

void serial_mode_leds(unsigned char number_repeat, unsigned char ms_delay){
	for (unsigned char i=0;i < number_repeat; i++)
	{
		PORTB = (1 << LED1);
		ch_delay(ms_delay);
		PORTB &= ~(1 << LED1);
		ch_delay(ms_delay);
		
		PORTC = (1 << LED2);
		ch_delay(ms_delay);
		PORTC &= ~(1 << LED2);
		ch_delay(ms_delay);
		
		PORTD = (1 << LED3);
		ch_delay(ms_delay);
		PORTD &= ~(1 << LED3);
		ch_delay(ms_delay);
		
		PORTC = (1 << LED2);
		ch_delay(ms_delay);
		PORTC &= ~(1 << LED2);
		ch_delay(ms_delay);
				
	}
}

void parallel_mode_leds(unsigned char number_repeat, unsigned char ms_delay)
{
	for (unsigned char i=0;i < number_repeat; i++)
	{
		PORTB = (1 << LED1);
		PORTC = (1 << LED2);
		PORTD = (1 << LED3);
		ch_delay(ms_delay);
		
		PORTB &= ~(1 << LED1);
		PORTC &= ~(1 << LED2);
		PORTD &= ~(1 << LED3);
		ch_delay(ms_delay);
		
	}
}
int main(void)
{
	
    /* Replace with your application code */
    while (1) 
    {
		init_ports_mcu();
		
		serial_mode_leds(NUMBER_OF_REPEAT,DELAY1);
		serial_mode_leds(NUMBER_OF_REPEAT,DELAY2);
		parallel_mode_leds(NUMBER_OF_REPEAT,DELAY1);
		parallel_mode_leds(NUMBER_OF_REPEAT,DELAY2);
		
		
		
		
		
		
    }
	return(0);
}

