#define MIN_NUMBER 1
#define MAX_NUMBER 30

#include <stdio.h>
#include <stdlib.h>

void validateRange(void);

int main(void)
{
	printf("Guess the Number\n");
	validateRange();

	return 0;
}

void validateRange()
{
	if(MIN_NUMBER > MAX_NUMBER)
	{
		printf("Incorrect range of numbers! Minimum is higher than maximum!\nProgram will now exit\n");
		exit(-1);
	}
	else if(MIN_NUMBER == MAX_NUMBER)
	{
		printf("Incorrect range of numbers! Minimum is equal to maximum!\nProgram will now exit\n");
		exit(-2);
	}
}