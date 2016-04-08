#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//Let's use exceptions for our edge cases this time.
char firstUnique(char* str, int len)
{
    if(!str)
        throw std::exception("The string is empty...");

    //The map will keep track of how many times a character has been found.
    unordered_map<char, int> count;
    //The vector will keep track of the order as we go along.
    vector<char> uniques;
    
    for(int i = 0; i < len; i++)
    {
        count[str[i]]++;
        if(count[str[i]] == 1)
            uniques.push_back(str[i]);
        else
        {
            //If the count is greater than one, erase this letter from the vector.
            //There is room for optimization here, for example we can say that if the count is greater than 2
            //we don't need to search because the second count should have already erased it.
            vector<char>::iterator f = find(uniques.begin(), uniques.end(), str[i]);
            if(f != uniques.end())
                uniques.erase(f);
        }
    }

    if(uniques.empty())
        throw exception("No unique characters found.");

    return uniques.front();
}

int main()
{
    char* input = "recalcitrant";

    try
    {
        cout << "The first unique character in the string \"" << input << "\" is: " << firstUnique(input, 12) << endl;
    }
    catch(std::exception e)
    {
        cout << "ERROR: " << e.what() << endl;
    }

    std::cin.get();

    return 0;
}