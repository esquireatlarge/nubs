#include <iostream>


void quick(int* array, int start, int end)
{
    if(!array)
        return;

    //Print out the array at each recursion.
    for(int i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    //The pivot does not necessarily have to be the middle element of the array.
    //One can even make "end" be the pivot if they wish.
    int pivot = array[(start + end) / 2];

    int s = start;
    int e = end;
    while(s <= e)
    {
        while(array[s] < pivot)
            s++;

        while(array[e] > pivot)
            e--;

        if(s <= e)
        {
            //Perform a swap.  The goal is to bring any values
            //smaller than the pivot to the left, and any values greater than the pivot
            //to the right.
            int temp = array[s];
            array[s] = array[e];
            array[e] = temp;

            s++;
            e--;
        }
    }

    if(start < e)
        quick(array, start, e);

    if(s < end)
        quick(array, s, end);
}


int main()
{
    int array[] = {4,1,7,3,8,9,0,2,6,5};

    quick(array, 0, 9);

    for(int i = 0; i < 10; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    std::cin.get();

    return 0;
}