//Matt Sguerri
//Varius methods for intersecting arrays.

#include <iostream>
#include <set>
#include <Windows.h>

//method one, O(n^2)
void IntersectSquared(const char** one, int oneLength, const char** two, int twoLength, const char**& out, int& resultSize)
{
    if(oneLength < 1 || twoLength < 1)
        return;

    resultSize = 0;

    //Create array as large as the shortest input array.
    if(oneLength > twoLength)
        out = new const char*[twoLength];
    else
        out = new const char*[oneLength];

    for(int i = 0; i < oneLength; i++)
    {
        for(int j = 0; j < twoLength; j++)
        {
            if(strcmp(one[i], two[j]) == 0)
                out[resultSize++] = one[i];
        }
    }
}

//method 2, O(n) but more memory
void Intersect(const char** one, int oneLength, const char** two, int twoLength, const char**& out, int& resultSize)
{
    if(oneLength < 1 || twoLength < 1)
        return;

    resultSize = 0;

    //Create array as large as the largest input array.
    if(oneLength > twoLength)
        out = new const char*[twoLength];
    else
        out = new const char*[oneLength];

    std::set<const char*> tester;
    
    //Store one array's elements in set
    for(int i = 0; i < oneLength; i++)
        tester.insert(one[i]);

    std::pair<std::set<const char*>::iterator, bool> ret;

    //Iterate through second array
    for(int j = 0; j < twoLength; j++)
    {
        ret = tester.insert(two[j]);
        if(!ret.second) //insertion failed
        {
            //This is a duplicate
            out[resultSize++] = two[j];
        }
    }
}

//This method will absolutely not work if the arrays are unsorted.
void IntersectSorted(const char** one, int oneLength, const char** two, int twoLength, const char**& out, int& resultSize)
{
    const char** s = NULL;
    int shortSize = 0;
    const char** l = NULL;
    int longSize = 0;
    //Iterate through both arrays at the same time, but first find the shortest.
    if(oneLength < twoLength)
    {
        //Array one is the shorter array.
        s = one;
        shortSize = oneLength;
        l = two;
        longSize = twoLength;
    }
    else
    {
        s = two;
        shortSize = twoLength;
        l = one;
        longSize = oneLength;
    }

    out = new const char*[shortSize];

    int i = 0, j = 0;
    while(i < shortSize && j < longSize)
    {
        //Look through the longer array.  Since it should be sorted, we can iterate until 
        //we either find a duplicate, or an item greater.
        while((j < longSize) && (strcmp(s[i], l[j]) > 0))
            j++;

        //Error check
        if(j >= longSize)
            return;

        //Now the item is either equal to, or greater.
        if(!strcmp(s[i], l[j]))
        {
            //Store item in array.
            out[resultSize++] = s[i];

            //The item is equal, upgrade both pointers.
            i++;
            j++;
        }
        else
        {
            //The item is greater.  Increment the short array pointer.
            //Leave long array pointer as is.
            i++;
        }
    }
}

int main()
{
    //Input arrays are sorted.  Assume no duplicates.
    const char* one[] = {"cat", "dog", "fat", "hat"};
    const char* two[] = {"bob", "dog", "hog"};

    const char** res = NULL;
    int resSize = 0;

    LARGE_INTEGER freq;
    LARGE_INTEGER start, end;
    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    IntersectSquared(one, 4, two, 3, res, resSize);
    QueryPerformanceCounter(&end);
    std::cout << "O(n2) Results: " << resSize << " ";
    for(int i = 0; i < resSize; i++)
        std::cout << res[i];
    std::cout << std::endl;
    std::cout << "Took " << ((end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart) << " seconds." << std::endl;

    const char** res2 = NULL;
    int resSize2 = 0;
    QueryPerformanceCounter(&start);
    Intersect(one, 4, two, 3, res2, resSize2);
    QueryPerformanceCounter(&end);
    std::cout << "Set Results: " << resSize2 << " ";
    for(int i = 0; i < resSize2; i++)
        std::cout << res2[i];
    std::cout << std::endl;    
    std::cout << "Took " << ((end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart) << " seconds." << std::endl;

    const char** res3 = NULL;
    int resSize3 = 0;
    QueryPerformanceCounter(&start);
    IntersectSorted(one, 4, two, 3, res3, resSize3);
    QueryPerformanceCounter(&end);
    std::cout << "Sorted Results: " << resSize3 << " ";
    for(int i = 0; i < resSize3; i++)
        std::cout << res3[i];
    std::cout << std::endl;
    std::cout << "Took " << ((end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart) << " seconds." << std::endl;

    std::cin.get();

    return 0;
}