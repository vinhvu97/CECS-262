//Vinh Vu, 015347252
#include <at89c51xd2.h>
void delay(void)
{
	int x;	
	for (x=0; x<100; x++);
}

void main(void)
{
	while(1)
	{
		P1=0x55;
		delay();
		P1=0xAA;
		delay();
	}
}


