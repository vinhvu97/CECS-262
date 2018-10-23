// Vinh Vu & Hung Le
// Final Project, calculator
#include <ds89c4xx.h>

// Transfer function
// The function intakes in a variable from main
// and outputs onto hyperterminal
void transfer(unsigned char send){
	SBUF0 = send;
	while(TI_0 == 0);
	TI_0 = 0;
} 

// Receive function
// The function receives the ASCII code
// for any particular character and
// returns it to main 
unsigned char receive(void){
		while (RI_0 == 0);
		RI_0 = 0;
		return SBUF0;
}

// Main function
void main (void)
{
// Variable declarations
unsigned char op1, op2, operation, op4, op5 ;
unsigned char operand1, operand2;
unsigned char i = 1;
unsigned int  result_9, result_8, result_7, result_6, result_5;
unsigned int  result_4, result_3, result_2, result_1 ;	
long          result1, temp_result; 

	// Set values for input
	TMOD  = 0x20; // 8-bit auto reload
	TH1   = 0xFD; // baud rate for 9600
	SCON0 = 0x50; // 8-bit data, 1 stop bit, 1 start bit
	TR1   = 1;    // start timer 
	while (1)
	{
	 // Clearing all of the bits for a new arithmetic
	 result_9 = 0;
	 result_8 = 0;
	 result_7 = 0;	
 	 result_6 = 0;
 	 result_5 = 0;
   result_4 = 0;
   result_3 = 0;
	 result_2 = 0;
	 result_1 = 0;
	 result1  = 1; 	
	 temp_result = 0;
		
		// 1st input bit 
		op1 = receive();
		transfer(op1);
		
		// Convert ASCII to numerical value 
		op1 = op1 - 48;
	
		// 2nd input bit
		op2 = receive();
		transfer(op2);
		
		// Convert ASCII to numerical value 
		op2 = op2 - 48;
		
		// Combine the 2 inputs for the first operand
		operand1 =(op1*10)+op2;
		
		// operation
		operation = receive();
		transfer(operation);
		
		//4th input bit
	  op4 = receive();
		transfer(op4);
		
		// Convert ASCII to numerical value 
		op4 = op4 - 48;
		
		// 5th input bit
		op5 = receive();
		transfer(op5);
		
		// Convert ASCII to numerical value 
		op5 = op5 - 48;
		
		// Combine the 2 inputs for the send operand
		operand2 = (op4*10) + op5;
		
// If, elif, else statements for the arithmetic operations
	 if(operation == '+')
			result1 = operand1 + operand2;
	 
	 else if(operation == '-')
			result1 = operand1 - operand2;
	 
	 else if(operation == '*')
			result1 = operand1 * operand2;
	 
	 else if(operation == '/' )
			result1 = operand1 / operand2;
	 
	 else if(operation == '^')
			while ( i < operand2)
			{
				result1 = result1 * operand1;
				i = i + 1; 
			}
	 else
			result1 = 'z';
	 
	 // Assign result1 to temp_result to get the bits in 
	 // each location
		temp_result = result1;

	  // Getting value at hundred-millionth place
		while (temp_result >= 100000000)
		{
			temp_result = temp_result - 100000000; 
			result_9 = result_9 + 1; 
		}
		// Getting value at ten-millionth place
		while (temp_result >= 10000000)
		{
			temp_result = temp_result  - 10000000; 
			result_8 = result_8 + 1; 
		}
		
		// Getting value at millionth place
		while (temp_result >= 1000000)
		{
			temp_result = temp_result  - 1000000; 
			result_7 = result_7 + 1; 
		}
		
		// Getting value at hundred-thousandth place
		while (temp_result >= 100000)
		{
			temp_result = temp_result  - 100000; 
			result_6 = result_6 + 1; 
		}
	  
		// Getting value at ten-thousandth place
		while (temp_result >= 10000)
		{
			temp_result = temp_result  - 10000; 
			result_5 = result_5 + 1; 
		}
		
		// Getting value at thousandth place
		while (temp_result >= 1000)
		{
			temp_result = temp_result  - 1000; 
			result_4 = result_4 + 1; 
		}
		
		// Getting value at hundredth place
		while (temp_result >= 100)
		{
			temp_result = temp_result - 100; 
			result_3 = result_3 + 1; 
		}
		
		// Getting value at tenth place
		while (temp_result >= 10)
		{
			temp_result = temp_result - 10; 
			result_2 = result_2 + 1; 
		}
		// Getting value at oneth place
		while (temp_result >= 1)
		{
			temp_result = temp_result -1 ; 
			result_1 = result_1 + 1; 
		}
		
		// Convert each value location back to ASCII
		result_9  = result_9 + 48;
		result_8  = result_8 + 48;
		result_7  = result_7 + 48;
		result_6  = result_6 + 48;
		result_5  = result_5 + 48;
		result_4  = result_4 + 48;
		result_3  = result_3 + 48;
		result_2  = result_2 + 48;
		result_1  = result_1 + 48;
		
		// Displaying spacings 
		transfer('\n');
		transfer('\r');
		transfer(61);
		transfer(32);

		// Displaying the result 
		// If that certain place is a 0, it won't be displayed
		if ( result_9 != 48)
			transfer(result_9);
	  else if (result_8 !=48)
			transfer(result_8);
	  else if (result_7!=48)
			transfer(result_7);
	  else if (result_6 != 48)
			transfer(result_6);
	  else if (result_5 != 48)
			transfer(result_5);
	  else if (result_4 != 48)
			transfer(result_4);
	  else if (result_3 != 48)
			transfer(result_3);
	  else if (result_2 != 48)
			transfer(result_2);
	  else 
			transfer(result_1);
	 
	  // Displaying spacings for the next operation
	  transfer('\n');
	  transfer('\r');
	  transfer('>');
	  transfer('>');
	
	} // end of while loop
} // end of main 