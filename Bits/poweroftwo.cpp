#include <iostream>

//Two ways to determine if a number is a power of two.
//One is a recursive function call, while the other does bit checking.
//The recursive function call has higher overhead and is not desireable over 
//bit checking. <mrs>

bool isPowerOfTwoByRecursion(double value)
{
	if(value == 1)
		return true;
	if(value < 1)
		return false;
	isPowerOfTwoByRecursion(value / 2.0);
}

bool isPowerOfTwoByBits(int value)
{
	//It's easy to check if something is a power of two 
	//by checking how many bits are set.
	//For an int primitive we have a max of 32 bits to check,
	//and if one and only one of the 32 is set, then we have a power of two.
	//Think of a number's binary representation:
	//1 is 0001
	//2 is 0010
	//4 is 0100
	//8 is 1000
	//Binary is a representation of a number in power of two's.
	
	int size = sizeof(value);
	int numBits = 0;
	while(value)
	{
		if(value & 1 == 1)
			numBits++;
		value >>= 1;
	}
	
	return (numBits == 1);
}

int main()
{
	int value = 5;
	isPowerOfTwoByRecursion(value) ? printf("%d is a power of two.\n", value) : printf("%d is not a power of two.\n", value);
	isPowerOfTwoByBits(value) ?  printf("%d is a power of two.\n", value) : printf("%d is not a power of two.\n", value);
	return 0;
}