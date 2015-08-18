//Esquire At Large
//Implementation patterned after Cracking the Coding Interview
//Assumptions:
//      Only ASCII
//      Only lowercase a - z

bool isAllUniqueChars(const char* string)
{
    //Border condition.
    if(!string)
        return false;

    //Since I don't want to pass in an extra parameter to give me the length of the string,
    //I will calculate it manually.  Note to take the size of a CHAR, not CHAR*!  They are different types!
    int len = sizeof(string) / sizeof(char);

    int bitVector = 0;
    for(int i = 0; i < len; i++)
    {
        //Extract a character from the string and treat it as an integer.
        //Subtract a lowercase 'a' (97)
        int c = string[i] - 'a';
        
        //Let's find out if this value is already set in the bit vector.
        //If the AND operation returns true, then the value is already set in the bit vector, which means
        //we've seen this character before.  This string is therefore not unique, let's just return false.
        if((bitVector & (1 << c)) == 1)
            return false;

        //Set the value to 1 to mark that we've come across this character.
        bitVector = bitVector | (1 << c);
    }

    return true;
}

//Let's see an example:
//Assume a string that isn't all unique characters: bb
//Let's grab each character one by one and subtract a from it.
//This subtraction lets us get a number smaller than 32 (26 is the max in fact).
//This means we can store it in an integer if we treat that integer as a bit vector.
//Alternatively, one could use a more "involved" structure like the bit_set.

//Our 32 bit integer looks like this when set to zero.
//00000000000000000000000000000000

//b (98) - a (97) = 1
//Shift the value of 1 over by 1 to check to see if the second bit has been set.
//1 << 1 = 00010

//AND this value with our bit vector
//00000000000000000000000000000000   AND
//00000000000000000000000000000010  

//As we can see the result of this AND is not greater than zero, which means we've never seen 
//this character before.
//Let's set this value.
//00000000000000000000000000000010

//Repeat this process for the next letter, also 'b'.  Notice that this time the bit IS set, therefore
//we've run into this character before. 
//The string is not unique.