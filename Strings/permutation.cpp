//Esquire At Large
//Determines whether one string is a permutation of another.
//For example:
//tathery is a permutation of hattery
//manbat is a permutation of batman
//sashboogie is not a permutation of cake

#include <cstring>
#include <stdio.h>

bool isPermutation(const char* source, const char* target)
{
    int srcLen = strlen(source);
    int tgtLen = strlen(target);

    //If the strings aren't even of equal length there is no reason to
    //continue checking.
    if(srcLen != tgtLen)
        return false;

    //There are a couple of approaches:
    //Store all characters in a set / map for source.
    //Repeat this for target, and ideally if target is indeed a permutation of source
    //All the inserts should fail.  If this is the case, target is a permutation of source.
    //For this approach let's observe the following complexities:
    //Time: O(n) - we have to cycle through the two strings to completion. [O(2n) => O(n)]
    //Space: O(n) - we have a separate data structure the size of the string.

    //Another approach is to use a bit vector, toggling the bits for source and again for target;
    //if any bits are set after this approach then target is not a palindrome of source.
    //For this implementation we observe the following complexities:
    //Time: O(n) - we have to cycle through the two strings to completion. [O(2n) => O(n)]
    //Space: O(1) - we use only a single integer (assuming we are using an int and not bit_set).
    //RESTRICTIONS:  Only characters a - z.

    //Let's use the latter approach.
    int vector = 0; //All bits zero.
    for(int i = 0; i < srcLen; i++)
    {
        //Toggle the bit with the source string.
        vector ^= (1 << (source[i] - 'a'));

        //Toggle the bit with the target string.
        vector ^= (1 << (target[i] - 'a'));
    }

    //If one is a permutation of the other, the vector should be zero.
    return (vector == 0);
}