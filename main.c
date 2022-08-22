#define MIN_NUMBER 1
#define MAX_NUMBER 30
#define INCORRECT_RANGE_MESSAGE "Incorrect range of numbers!"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void validateRange(void);
int randomNumber(void);
int numbersAreNotEqual(int a, int b);

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

		if(numbersAreNotEqual(givenNumber, randomisedNumber))
		{
			printf("Wrong! Try again.\n");
		}
	}
	while (numbersAreNotEqual(givenNumber, randomisedNumber));

	printf("You guessed right! It is %d!\nTRIES: %d", randomisedNumber, tries);

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

int numbersAreNotEqual(int a, int b)
{
	return a != b;
}