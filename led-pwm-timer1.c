// good source on dimming an led using pwm
//source=http://www.nerdkits.com/forum/thread/190/

#define F_CPU 14745600
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

// Simply bright then dim an LED (on PB1)

int main(void)
{
	OCR1AH = 0;
	DDRB |= (1<<PB1);         //PortB 1 as output
	TCCR1A = (1<<COM1A1)|(1<<1);   // OC1A to zero, 8-Bit PWM
	TCCR1B = 1;             //Start PWM
	for (;;) {
		int i;
		for (i=0; i<255; i++) {
			OCR1AL = i;         //Change lowbyte of OCR1A
			_delay_ms(15);
		}
		for (i=255; i>0; i--) {
			OCR1AL = i;
			_delay_ms(15);
		}
	}
	return 0;
}