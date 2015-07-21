#include <climits>
#include <cstdio>
#include <time.h>

int numBitsSet1(int value)
{
	int numOnes = 0;
	//A pass by value will allow us to avoid using another local variable.
	
	//This way employs a while loop until the value is zero.
	while(value)
	{
		if(value & 1 == 1)
			numOnes++;
		value >>= 1;
	}
	
	return numOnes;
}

int numBitsSet2(int value)
{
	int numOnes = 0;
	
	//This way will instead use a for loop, iterating through the size
	//of the integer in memory (32 bits).
	int size = sizeof(value); //An int32 should by 4 bytes.
	
	for(int i = 0; i < size * CHAR_BIT; i++)
	{
		if(value & 1 == 1)
			numOnes++;
		value >>= 1;
	}
	
	return numOnes;
}

int main()
{
	//Count the number of bits set to 1 for an integer.
	clock_t startOne = clock();
	printf("%d\n", numBitsSet1(5));
	clock_t endOne = clock();
	
	clock_t startTwo = clock();
	printf("%d\n", numBitsSet2(5));
	clock_t endTwo = clock();
	
	printf("First function took %f seconds\n", double(endOne - startOne) / CLOCKS_PER_SEC);
	printf("Second function took %f seconds\n", double(endTwo - startTwo) / CLOCKS_PER_SEC);
	
	return 0;
}