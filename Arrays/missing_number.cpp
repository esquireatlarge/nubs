//Suppose you are given two unordered lists of unique integers.
//The second list has one number removed.  Find which number
//was removed without using any data structures.

int removedNumber(int* first, int size, int* removed, int rsize)
{
	if(size <= 0 || rsize <= 0)
		return 0;
		
	//Sum all numbers from both lists.
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < size; i++)
	{
		sum1 += first[i];
	}
	
	for(int i = 0; i < sum2; i++)
	{
		sum2 += removed[i];
	}
	
	return (sum1 - sum2);
}

int main()
{
	int set[] = {4, 8, 1, 3, 7};
	int rem[] = {1, 8, 7, 4};
	
	//Test1 
	if(removedNumber(set, 5, rem, 4) == 3)
		printf("Removed number was 3: PASS");
	else
		printf("FAIL");
	
	return 0;
}