
// In the advertisement space, we have some clickstream data  that we gathered on the client’s website. Using cookies, we collected snippets of users’ anonymized URL histories while they browsed the site. Write a function that takes two users’ browsing histories as input and returns the longest contiguous sequence of URLs that appears in both.
// Answer: [Fruit, Cancer, Porn]
//User1: [Apple, Orange, Banana, Fruit, Cancer, Porn]
//User2 : [Apple, Banana, Orange, Fruit, Cancer, Porn]

// Answer: [Fruit, Cancer, Porn]
//User1 : [Fruit, Cancer, Porn, Orange, Banana, Apple]
//User2 : [Fruit, Cancer, Porn, Banana, Orange, Apple]

void cascade(char* list, int n = 0)
{
	cascade(list, n + 1);
}

void cascade1(char* master, )

int main()
{
	char first[] = {"one", "three", "four", "six", "two"};
	char second[] = { "one", "six", "four", "six", "two"};

	//Expected answer is "four", "six", "two"

	//Get object sizes
	int firstMax = sizeof(first) / sizeof(char);
	int secondMax = sizeof(second) / sizeof(char);

	//Recurse through first array 
	cascade(first);

	//Recurse through second array
	cascade(second);

	//Compare list

	return 0;
}