//Convert all spaces in a string to URI compliant %20.
//Esquire At Large

//Assumptions that can be made include that the string has enough space to hold the extra characters at the end.
//Could also use strtok.

#include <cstring>
#include <cstdio>

//Time complexity: O(2n) => O(n) We have to iterate through the entire string to replace all spaces.
//Space complexity: O(3n) => O(n) Where n is the string length and y is the count of spaces.  Could this be better?
char* makeUriCompliant(const char* original)
{
    int len = strlen(original);

    //Count spaces
    int numSpaces = 0;
    
    //O(n)
    for(int i = 0; i < len; i++)
    {
        if(original[i] == ' ')
            numSpaces++;
    }

    //Make new string.
    int newLen = len + (3 * numSpaces) + 1;
    char* buff = new char[newLen];

    //O(n) again
    int x = 0;
    for(int i = 0; i < len; i++)
    {
        if(original[i] != ' ')
        {
            buff[x++] = original[i];
        }
        else
        {
            buff[x++] = '%';
            buff[x++] = '2';
            buff[x++] = '0';
        }
    }

    buff[x] = '\0';

    return buff;
}

int main()
{
    char* original = "a b c d e f g h j u g d s c g ";
    char* noSpaces = makeUriCompliant(original);

    printf("From %s to %s", original, noSpaces);

    return 0;
}