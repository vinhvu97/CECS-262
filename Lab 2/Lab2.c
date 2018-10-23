#include <at89c51xd2.h>
// Vinh Vu, 015347252, Lab 2

// Delay function to slow down the LED
// When checking Port 0 pin 2, a 1 on the pin
// will generate a faster speed than a 0 on the pin
void delay(void)
{
	// Variable declarations
	unsigned char Result;	
	int           x;
	
	//checking of sw2 is 1 or 0
	Result = (P0&0x04);
	
	// If SW2 is a 0, the delay counter is smaller which triggers a faster speed
	if (Result) 
	{
		for (x=0; x<45000; x++);
	}
	// else, the delay counter is bigger which triggers a slower speed
	else 
	{	
		for (x=0; x<65000; x++);
	}
}
// main function
// P0 intakes a binary input from the switches while P1 drives the LED's
// The right-shifting is the driving of LED's 
void main(void)
{
	// Variable declarations
	int           i;
	unsigned char result;
	
	//Initialize 
	P0 = 0xFA;

	// Infinite while loop
	while(1)
	{			
		// Checking i SW1 is 1 or 0
		result = (P0&0x02);
		
		// If SW1 is a 1, P1 gets 0xFA as its value
		// There is a while loop that right-shifts the value
		// 8 times 
		if (result) {
			P1=0xFA;
			i=0;
			while(i<8)
			{
				delay();
				P1=P1>>1; // shifting
				i++;
			} // end of while loop for shifting 
		} // end of if statement
		
		// else SW1 is a 0, P1 gets 0x50 as its value
		// There is a for loop that right-shifts the value 8 times
		else 
		{
			i=0;
			P1=0x50;
			for (i=0;i<=8;i++)
			{
				delay();
				P1=P1>>1; // shifting
			}
		}// end of else
	} // end of while loop
} // end of main module