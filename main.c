#define MIN_NUMBER 1
#define MAX_NUMBER 30

#include <stdio.h>

int main(void)
{
	printf("Guess the Number\n");

	if(MIN_NUMBER > MAX_NUMBER)
	{
		printf("Incorrect range of numbers! Minimum is higher than maximum!\nProgram will now exit\n");

		return -1;
	}
	else if(MIN_NUMBER == MAX_NUMBER)
	{
		printf("Incorrect range of numbers! Minimum is equal to maximum!\nProgram will now exit\n");

		return -2;
	}

	return 0;
}