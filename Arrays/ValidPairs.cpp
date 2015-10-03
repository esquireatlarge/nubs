//Find the count of all valid tuples {a,b} in a sorted container of unique numbers such that a + b <= x.
//Esquire At Large

#include <cstdio>
#include <cstdlib>

//A binary search function.
//Operates in O(logn) time.
int bin_func(int val, int* a, size_t s, int st, int en)
{
    if(!a || s <= 0)
        return -1;

    if(st == en)
        return -1;

    int mdpt = (st + en) / 2;
    if(val == a[mdpt])
        return mdpt;
    else if(val > a[mdpt])
        return bin_func(val, a, s, mdpt + 1, en);
    else
        return bin_func(val, a, s, st, mdpt);
}

//This function will find the index of the closest value to the specified argument "val".
//If the value exists in the array then it will return that index.
//I'm sure there is a better way to achieve the same functionality.
int FindIndexOfClosestValue(int val, int* arr, size_t size)
{
    if(!arr || size <= 0)
        return -1;

    //Perform a binary search.
    int idx = -1, numTries = 0;
    while(numTries < size && ((idx = bin_func(val, arr, size, 0, size)) == -1))
    {
        val--;
        numTries++;
    }

    return idx;
}

//Function will return an array of Pair objects.
//Input is the sorted array of integers, as well as the size of the array.
//The function will output the number of valid pairs found.
int CountValidTuples(int x, int* arr, size_t arrSize)
{
    if(!arr || arrSize <= 0)
        return 0;

    //Output array to look within.
    //{0 ... n}
    printf("%s", "{");
    for(int i = 0; i < arrSize; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("%s\n", "}");

    int numFound = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] > x)
            break;

        int b = (x - arr[i]);
        int closest = FindIndexOfClosestValue(b, arr, arrSize);

        if(closest > i)
            numFound += (closest - i);
    }

    return numFound;
}

int main()
{
    int test[] = {2, 5, 10, 13, 19, 25};

    int numFound = CountValidTuples(25, test, 6);

    printf("%d", numFound);

    char k[2];
    scanf("%c", k); 

    return 0;
}