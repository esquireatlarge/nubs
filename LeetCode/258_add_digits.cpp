//Find the sum of all digits of a number until the result is only a single digit.
//Leet code #258
//The hints mention to use the digital root, which is not something I would know about unless
//I looked it up.  I've provided an iterative approach as well.
//Esquire At Large

#include <cstdio>
#include <Windows.h> //timing

//Iteratively adding each digit
int addDigitsLoop(int num)
{
    int result = 0;
    while(num > 0)
    {
        while(num > 0)
        {
            result += num % 10;
            num /= 10;
        }
        if(result > 9)
        {
            num = result;
            result = 0;
        }
    }

    return result;
}

//Using the formula for digital root
int addDigits(int num)
{
    if(num < 0)
        return -1;
    if(num <= 9)
        return num;

    return ((num - (9 * ((num -1) / 9))));
}

int main()
{
    LARGE_INTEGER f, s, e;
    QueryPerformanceFrequency(&f);

    int answer1 = 3;
    QueryPerformanceCounter(&s);
    int test1 = addDigits(12);
    QueryPerformanceCounter(&e);

    printf("addDigits(12) = %d %f ms\n", test1, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));


    int answer2 = -1;
    QueryPerformanceCounter(&s);
    int test2 = addDigits(-1);
    QueryPerformanceCounter(&e);
    printf("addDigits(-1) = %d %f ms\n", test2, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));

    int answer3 = 6;
    QueryPerformanceCounter(&s);
    int test3 = addDigits(4362);
    QueryPerformanceCounter(&e);
    printf("addDigits(4362) = %d %f ms\n", test3, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));

    int answer4 = 2;
    QueryPerformanceCounter(&s);
    int test4 = addDigits(2);
    QueryPerformanceCounter(&e);
    printf("addDigits(2) = %d %f ms\n", test4, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));

    int answer5 = 0;
    QueryPerformanceCounter(&s);
    int test5 = addDigits(0);
    QueryPerformanceCounter(&e);
    printf("addDigits(0) = %d %f ms\n", test5, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));

    int answer6 = 7;
    QueryPerformanceCounter(&s);
    int test6 = addDigits(4893298);
    QueryPerformanceCounter(&e);
    printf("addDigits(4893298) = %d %f ms\n", test6, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));

    QueryPerformanceCounter(&s);
    int looped = addDigitsLoop(4893298);
    QueryPerformanceCounter(&e);
    printf("addDigitsLoop(4893298) = %d %f ms\n", test6, (((e.QuadPart - s.QuadPart) * 1000.0) / f.QuadPart));


    return 0;
}