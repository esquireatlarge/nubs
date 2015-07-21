#include <iostream>
#include <string.h>

void toBits(int value)
{
	int size = sizeof(value);
	char* buf = new char[size];
	memset(buf, '0', size);
	for(int i = size - 1; i >= 0; i--)
	{
		if(value & 1 == 1)
			buf[i] = '1';
		value >>= 1;
	}
	
	printf(buf);
	delete buf;
}

int main()
{
	toBits(1);
	printf("\n");
	toBits(2);
	printf("\n");
	toBits(3);
	printf("\n");
	toBits(4);
	printf("\n");
	toBits(5);
	
	return 0;
}