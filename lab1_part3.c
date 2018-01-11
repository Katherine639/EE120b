#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char firstPark = 0x00;
	unsigned char secondPark = 0x00;
	unsigned char thirdPark = 0x00;
	unsigned char fourthPark = 0x00;
	unsigned char spaceAvail = 0x00;
	
    while(1)
    {
        firstPark = PINA & 0x01;
		secondPark = PINA & 0x02;
		thirdPark = PINA & 0x04;
		fourthPark = PINA & 0x08;
		
		
		spaceAvail = firstPark + (secondPark >> 1) + (thirdPark >> 2) + (fourthPark >> 3);
		if(spaceAvail == 0x04)
		{
			PORTC = 0x80;
		}
		else
		{
			spaceAvail = firstPark + secondPark + thirdPark + fourthPark;
			spaceAvail = ~spaceAvail;
			spaceAvail = spaceAvail & 0x0F;
			PORTC = spaceAvail;
		}
								
    }
}
