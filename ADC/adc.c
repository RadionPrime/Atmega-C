#include <avr/io.h>

//-------------------------------------
// Get ADC conversion value
//-------------------------------------

int getADC(char channel)
{
	
	/*
	unsigned int W = 0;
    ADMUX |= channel;

	ADCSRA |= (1 << ADSC);

	while(ADCSRA & (1 << ADIF));
	ADCSRA |= (1 << ADIF);
	W = ADCL;
	W |= (ADCH << 8);
	return W;
	*/


ADCL = 0;
ADCH = 0;
ADMUX &= ~(1<<MUX0);			// kana³ 0 
ADMUX &= ~(1<<MUX1);
ADMUX &= ~(1<<MUX2);

channel=channel & 0x7;				// 3 m³odsze bity
		
   ADMUX = (ADMUX & 0xF8) | channel;  	// ustaw kanal
    
   ADCSRA |=(1<<ADSC);         			// rozpoczêcie przetwarzania (pomiar)
   while(ADCSRA & (1<< ADSC));
   return ADCW;  
}


void ADC_Init(void)
{

ADMUX = (1 << REFS0);
ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
 
//ADCSRA = (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0); 
}

