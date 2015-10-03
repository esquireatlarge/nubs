//EsquireAtLarge
//Reducing a combination to the smallest possible string
//which still attempts all combinations.

//Let's assume a safe with two digits: 0, 1.
//The safe can be opened with any combination thereof.
//When combined, all the combinations form a string like so:
//00011011

//If we were to type in each digit of the above string one by one, 
//we would eventually be repeating combinations we previously entered.
//The reduction of this string which avoids this would look as follows:
//00110

//How can we perform this reduction?

#include <cstring> //strstr
#include <cstdio> //printf

bool exists(char* token, int tokenSize, char* string, int stringSize)
{
	return (strstr(string, token) != nullptr);
}


char* reduce(char* combination, int size, int comboLength)
{
	printf("Reducing combination %s with combination size %d\n", combination, comboLength);
	if(!combination)
		return nullptr;
	if(size <= 0)
		return nullptr;
	if(comboLength < 2)
		return nullptr;
	
	//Make a new string the same size as the current string.
	//We cannot anticipate the size of the reduced string.
	char* reduced = new char[size];
	int reducedSize = 0;
	
	printf("Assigning initial %d digits to reduced string.\n", comboLength);
	//The first two digits should be ok automatically.
	for(int i = 0; i < comboLength; i++)
		reduced[i] = combination[i];
	reducedSize = comboLength;
	
	for(int i = comboLength; i < size; i++)
	{
		printf("Reduced string is now: %s\n", reduced);
		
		//Form a string using the last digit of the reduced string
		//and the new digit we are trying to add to it.
		char* test = new char[comboLength + 1];
		test[comboLength] = '\0';
		test[comboLength - 1] = combination[i];
		
		for(int j = 0; j < comboLength - 1; j++)
			test[j] = reduced[reducedSize - ((comboLength - 1) + j)];
		
		printf("Testing string %s\n ", test);
		
		//Now that the token has been formed, check to see if it exists in the
		//reduced string already
		if(!exists(test, comboLength + 1, reduced, reducedSize))
			reduced[reducedSize++] = combination[i];
	}
	
	reduced[reducedSize] = '\0';
	
	return reduced;
}

int main()
{
	//00011011
	char* combo = new char[9];
	strncpy(combo, "00011011", 8);
	combo[8] = '\0';
	
	char* reduced = reduce(combo, 8, 2);
	printf("Reduced: %s\n", reduced);
	
	return 0;
}

//   _ _ _
//   000 001 010 011 100 101 110 111
//   000001010011100101110111
//   0001