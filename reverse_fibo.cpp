//Reverse Fibonacci
//Esquire At Large

//When provided the two initial numbers, complete the fibonacci sequence.
//For example:
//As Input: 100, 60, 40, 20, 20, 0

#include <Windows.h> //for timing
#include <cstdio>

void ReverseFiboRecursively(int first, int second)
{
    if(first < second) //Invalid input
        return;

    int result = first - second;
    printf("%d ", result);
    if(result <= 0)
        return;

    //Tail recursion!  Yay! :-D
    ReverseFiboRecursively(second, result);
}

//By holding on to your last answer, we are creating a "dynamic programming" solution.
//I don't think I will ever understand how "dynamic programming" translates to
//keeping track of your previous answer.
//For a standard fibonacci sequence, which grows infinitely, dynamic programming becomes
//more valuable.  It is likely that fib(1) and fib(2) will be requested multiple times, so it
//only makes sense to store those values.
void ReverseFiboDynamic(int first, int second)
{
    if(first < second)
        return;

    int last = first;       
    int subtrahend = second;
    do
    {
        int temp = last - subtrahend;
        last  = subtrahend;
        subtrahend = temp;
        if(subtrahend >= 0)
            printf("%d ", subtrahend);
    }while(subtrahend > 0);
}

void reverseFibonacci(int first, int second)
{
    //This can be done a few ways.
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);

    //Here's a recursive approach.
    QueryPerformanceCounter(&start);
    ReverseFiboRecursively(first, second);
    QueryPerformanceCounter(&end);
    printf("\nRecursive reverse fibonacci took: %f ms\n", ((end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart));

    //An iterative "dynamic programming" approach.
    QueryPerformanceCounter(&start);
    ReverseFiboDynamic(first, second);
    QueryPerformanceCounter(&end);

    printf("\nIterative reverse fibonacci took: %f ms\n", ((end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart));

    //Interestingly enough, the iterative solution outperforms the recursive solution, which includes tail recursion!
    //This is expected due to the overhead of multiple recursive calls being pushed onto the stack.  The iterative solution
    //is one single function with a loop in it.  For such simple cases, a recursive example would likely be outshined by an iterative one.
}

int main()
{
    reverseFibonacci(80, 50);

    return 0;
}