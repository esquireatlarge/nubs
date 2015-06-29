#include <str.h>

void reverse(char* string)
{
	int start = 0;
	int end = strlen(string) - 1;
	char tmp;
	
	
	while(start < end)
	{
		tmp = string[start];
		string[start] = string[end];
		string[end] = tmp;
		
		start++;
		end--;
	}
}

int main()
{
	char buff[6];
	strcpy(buff, "hello");
	
	reverse(string);
	
	return 0;
}