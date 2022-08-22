#define MIN_NUMBER 1
#define MAX_NUMBER 30
#define INCORRECT_RANGE_MESSAGE "Incorrect range of numbers!"
#define PROGRAM_EXIT_MESSAGE "Program will now exit\n"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void validateRange(void);
int randomNumber(void);
int numbersAreNotEqual(int a, int b);
int cleanedStream(void);
int numberFromInput(void);

int main(void)
{
	srand(time(NULL));
	printf("Guess the Number\n");
	validateRange();

	int tries = 0;
	int givenNumber;
	int randomisedNumber = randomNumber();
	int typedNumbers[MAX_NUMBER] = {0};

	do
	{
		givenNumber = numberFromInput();
		
		if(!typedNumbers[givenNumber - 1])
		{
			typedNumbers[givenNumber - 1] = 1;
			++tries;

			if(numbersAreNotEqual(givenNumber, randomisedNumber))
			{
				printf("Wrong! Try again.\n");
			}
		}
		else
		{
			printf("You have already given that number.\n");
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
		printf(INCORRECT_RANGE_MESSAGE " Minimum is higher than maximum!\n" PROGRAM_EXIT_MESSAGE);
		exit(-1);
	}
	else if(!numbersAreNotEqual(MIN_NUMBER, MAX_NUMBER))
	{
		printf(INCORRECT_RANGE_MESSAGE " Minimum is equal to maximum!\n" PROGRAM_EXIT_MESSAGE);
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

int cleanedStream()
{
	while (getchar() != '\n');
	
	return 1;
}

int numberFromInput()
{
	int number;
	char c;

	do
	{
		printf("Type number from %d to %d: ", MIN_NUMBER, MAX_NUMBER);
	}
	while ((scanf("%d%c", &number, &c) != 2 || c != '\n') && cleanedStream() || number < MIN_NUMBER || number > MAX_NUMBER);

	return number;
}