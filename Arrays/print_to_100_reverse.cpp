//Esquire At Large
//The goal of this exercise is to print the numbers 1 to 100 with a for loop
//starting at 100.

//Methodology:  A simple formula is applied through each iteration of the loop, which
//              subtracts i from 100.  Alternatively, one could just have a counter 
//              counting upwards from 1 and just print that, but it seems like cheating a bit.
//Performance:  O(1)
//Explanation:  This problem specifies 100, meaning the input is constant.  
//              For non-constant input, this would translate to O(n).

#include <cstdio> //printf

int main()
{
	//The output should be 1 2 3 4 5 ... 100
	
	for(int i = 100; i > 0; i--)
	{
		printf("%d", (100 -  (i - 1)));
	}
	
	return 0;
}