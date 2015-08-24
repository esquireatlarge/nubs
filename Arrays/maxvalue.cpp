//Finding the maximum value in an integer array.
//Array's sort doesn't matter.  Average runtime O(n)

//Cycles through the array keeping track of the maximum value.
int findMaxValue(int* arr, int n)
{
	if(n <= 0)
	{
		throw -1;
	}
	
	int max = arr[0];
	for(int i = 1; i < len; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	
	return max;
}