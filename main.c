#define MIN_NUMBER 1
#define MAX_NUMBER 30
#define INCORRECT_RANGE_MESSAGE "Incorrect range of numbers!"

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
		printf(INCORRECT_RANGE_MESSAGE " Minimum is higher than maximum!\nProgram will now exit\n");
		exit(-1);
	}
	else if(MIN_NUMBER == MAX_NUMBER)
	{
		printf(INCORRECT_RANGE_MESSAGE " Minimum is equal to maximum!\nProgram will now exit\n");
		exit(-2);
	}
}