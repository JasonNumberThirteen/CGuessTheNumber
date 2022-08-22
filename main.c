#define MIN_NUMBER 1
#define MAX_NUMBER 30
#define GAME_TITLE "Guess the Number"
#define PROGRAM_EXIT_MESSAGE "Program will now exit"
#define INCORRECT_RANGE_MESSAGE "Incorrect range of numbers!"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void validateRange(void);
void loop(void);
int randomNumber(void);
int numberFromInput(void);
int cleanedStream(void);
int typedNumbersIndex(int number);
int alreadyTypedNumber(int *typedNumbers, int number);
int numbersAreNotEqual(int a, int b);
void printTip(int givenNumber);

int tries = 0;
int randomisedNumber;

int main(void)
{
	srand(time(NULL));
	puts(GAME_TITLE);
	validateRange();
	loop();
	printf("You guessed right! It is %d!\nTRIES: %d", randomisedNumber, tries);

	return 0;
}

void validateRange()
{
	if(MIN_NUMBER > MAX_NUMBER)
	{
		puts(INCORRECT_RANGE_MESSAGE " Minimum is higher than maximum!\n" PROGRAM_EXIT_MESSAGE);
		exit(-1);
	}
	else if(!numbersAreNotEqual(MIN_NUMBER, MAX_NUMBER))
	{
		puts(INCORRECT_RANGE_MESSAGE " Minimum is equal to maximum!\n" PROGRAM_EXIT_MESSAGE);
		exit(-2);
	}
}

void loop()
{
	int givenNumber;
	int typedNumbers[MAX_NUMBER - MIN_NUMBER + 1] = {0};

	randomisedNumber = randomNumber();

	do
	{
		int index;
		
		givenNumber = numberFromInput();
		index = typedNumbersIndex(givenNumber);
		
		if(!alreadyTypedNumber(typedNumbers, givenNumber))
		{
			typedNumbers[index] = 1;
			++tries;

			if(numbersAreNotEqual(givenNumber, randomisedNumber))
			{
				printf("Wrong! Try again. ");
				printTip(givenNumber);
			}
		}
		else
		{
			puts("You have already given that number.");
		}
	}
	while (numbersAreNotEqual(givenNumber, randomisedNumber));
}

int randomNumber()
{
	return rand() % MAX_NUMBER + MIN_NUMBER;
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

int cleanedStream()
{
	while (getchar() != '\n');
	
	return 1;
}

int typedNumbersIndex(int number)
{
	return number - MIN_NUMBER;
}

int alreadyTypedNumber(int *typedNumbers, int number)
{
	return typedNumbers[typedNumbersIndex(number)];
}

int numbersAreNotEqual(int a, int b)
{
	return a != b;
}

void printTip(int givenNumber)
{
	if(givenNumber < randomisedNumber)
	{
		puts("The number is higher than yours.");
	}
	else if(givenNumber > randomisedNumber)
	{
		puts("The number is lower than yours.");
	}
}