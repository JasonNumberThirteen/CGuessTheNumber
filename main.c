#define MIN_NUMBER 1
#define MAX_NUMBER 30
#define INCORRECT_RANGE_MESSAGE "Incorrect range of numbers!"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void validateRange(void);
int randomNumber(void);

int main(void)
{
	srand(time(NULL));
	printf("Guess the Number\n");
	validateRange();

	int tries = 0;
	int givenNumber;
	int randomisedNumber = randomNumber();

	do
	{
		givenNumber = randomNumber();
		++tries;

		printf("Given number = %d, Randomised number = %d, Tries = %d\n", givenNumber, randomisedNumber, tries);
	}
	while (givenNumber != randomisedNumber);

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

int randomNumber()
{
	return rand() % MAX_NUMBER + MIN_NUMBER;
}