//Implementation from Cracking the Coding Interview
//Effectively this function uses an integer as a bit_set.
//It is thus limited to 32 possible characters, and thus why this code
//makes the assumption of only lowercase a-z.  No unicode.
bool  isAllUniqueChars(const char* string)
{
    //Since I don't want to include any headers, I will get the size of this 
    //string manually.
    int len = sizeof(string) / sizeof(char);

    int checker = 0; //Our "hash table" comprised of bits.
    for (int i = 0; i < len; i++)
    {
        //For every character in this string, subtract a lowercase from it.
        //A lowercase 'a' is 97 in ASCII, so any character this is subtracted from will
        //be smaller than 32.
        int c = string[i] - 'a';

        //Let's now check our "hash table" or "bit_set".  We will AND
        //the value within checker with a value bitshifted "c" times.
        //If this and returns true, then it means we've already seen this char.
        if ((checker & (1 << c)) > 0)
        {
            return false;
        }

        //Otherwise set it to true.
        checker |= (1 << c);
    }

    return true;
}

//Some examples:
//Our checker is comprised of 32 bits:
//00000000000000000000000000000000

//Let's assume string "cc".
//Subtract a from each letter:
//c - a => 99 - 97 = 2

//Shift the value 1 leftwards by the above result
//100
//AND this value with the checker
//The result is:
//00000000000000000000000000000100

//Try that again with the next letter, which is again c.  
//You will see the value at that position is already set in checker,
//therefore our string is not unique.