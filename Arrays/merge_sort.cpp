#include <iostream>

void join(int* array, int start, int middle, int end)
{
    int numLeft = middle - start + 1;
    int numRight = end - middle;

    //At this point merge sort is no longer in-place.
    //We are declaring temporary arrays.
    int* left = new int[numLeft];
    int* right = new int[numRight];

    //Copy into the temporary arrays.
    for(int i = 0; i < numLeft; i++)
        left[i] = array[start + i];
    for(int i = 0; i < numRight; i++)
        right[i] = array[middle + 1 + i];

    //Merge the temp arrays back into the original array in sorted order.
    int xLeft = 0, xRight = 0, xSave = start;
    while(xLeft < numLeft && xRight < numRight)
    {
        //The goal is that the next element in the original array
        //should be the next smallest integer from both our arrays.
        if(left[xLeft] <= right[xRight])
        {
            array[xSave] = left[xLeft];
            xLeft++;
        }
        else
        {
            array[xSave] = right[xRight];
            xRight++;
        }

        xSave++;
    }

    //Copy the remaining elements on the left side, should there
    //be any.
    while(xLeft < numLeft)
    {
        array[xSave] = left[xLeft];
        xLeft++;
        xSave++;
    }

    //Do the same for the remaining elements on the right side.
    while(xRight < numRight)
    {
        array[xSave] = right[xRight];
        xSave++;
        xRight++;
    }

    //Cleanup.
    if(left)
        delete [] left;

    if(right)
        delete [] right;
}

void merge(int* array, int start, int end)
{
    if(start < end)
    {
        //(start + (end - start)) / 2
        int middle = (start + end) / 2;

        merge(array, start, middle);

        merge(array, middle + 1, end);

        join(array, start, middle, end);
    }
}

int main()
{
    int array[] = {4,1,7,3,8,9,0,2,6,5};

    //Using the constant value 9 below is not the best approach.
    //It makes the exercise easier to understand; however the proper
    //value to use is "sizeof(array)/sizeof(int)."  We can then
    //change the size of the array without having to change this magic value as well.
    merge(array, 0, 9);

    for(int i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    std::cin.get();

    return 0;
}