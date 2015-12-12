//Esquire At Large
//The goal of this exercise is to reverse an array recursively.

//Methodology: Swap elements from the first half of the array with those from the
//             latter half.
//Performance: O(n)
//Explanation: In order to reverse this array, we must iterate through all of it.
//             This iteration scales directly with the size of the array, hence O(n)

#include <cstdio> //printf

void reverseArray(int* array, int start, int end)
{
	if(!array)
		return;
	if(start >= end)
		return;
	
	//Swap the element in the latter half with the element
	//in the earlier half.
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;
	
	start++;
	end--;
	reverseArray(array, start, end);	
}

int main()
{
	int reverseMe[] = {1, 2, 3, 4, 5};
	int start = 0, end = (sizeof(reverseMe) / sizeof(int));
	
	for(int i = 0; i < end; i++)
		printf("%d", reverseMe[i]);
	reverseArray(reverseMe, start, end - 1);
	printf("\nAfter reversal...\n");
	for(int i = 0; i < end; i++)
		printf("%d", reverseMe[i]);
	return 0;
}