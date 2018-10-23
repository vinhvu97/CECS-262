#include <ds89c4xx.h>
// Vinh Vu & Hung Le
// Lab 3 Stepper Motor

// Delay function for clock wise
void delay_cw(void)
{
		
		TH0 = 0xEF;
		TL0 = 0x6C;
		TR0 = 1;
		while (TF0 == 0); 
		TR0 = 0;
		TF0 = 0;
}

// Delay function for counter clock wise 
void delay_ccw(void)
{
	
	TH0 = 0x44;
	TL0 = 0x7B;
	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}


// Main function
void main(void)
{
	TMOD = 0x01;
	while (1)
	{
		int i; 
		int j; 
		//turning cw
		// Stepping 16 times for 180 degrees
		for (j = 0 ; j <16; j=j+1)
		{
			// Each step has 64 cranks so shifting right 64 times each step 
			for (i = 0 ; i <16 ; i = i+1)
			{	
				P1 = 0x66;
				delay_cw();
				P1 = 0x33;
				delay_cw();
				P1 = 0x99;
				delay_cw();
				P1 = 0xCC;
				delay_cw();
			}
		}
		//turning ccw
		// Stepping 3 times for 30 degrees
		for (j = 0 ; j <3 ; j=j+1)
		{
			// Each step has 64 cranks so shifting left 64 times each step
			for (i = 0 ; i <16 ; i = i+1)
			{	
				P1 = 0x66;
				delay_ccw();
				P1 = 0xCC;
				delay_ccw();
				P1 = 0x99;
				delay_ccw();
				P1 = 0x33;
				delay_ccw();
			}
		}

	}
	
}