#define MIN_NUMBER 1
#define MAX_NUMBER 30
#define GAME_TITLE "Guess the Number"
#define NEW_LINE_CHARACTER '\n'
#define PROGRAM_EXIT_MESSAGE "Program will now exit"
#define INCORRECT_RANGE_MESSAGE "Incorrect range of numbers!"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void validateRange(void);
void loop(void);
int randomNumber(void);
int numberFromInput(void);
int typedNumberAndChar(int *number, char *c);
int cleanedStream(void);
void checkIfNumberHasAlreadyBeenTyped(int *typedNumbers, int number);
int alreadyTypedNumber(int *typedNumbers, int number);
void countNewNumber(int *typedNumbers, int number);
int typedNumbersIndex(int number);
void printWrongGuess(int number);
int numbersAreEqual(int a, int b);
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
	else if(numbersAreEqual(MIN_NUMBER, MAX_NUMBER))
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
		givenNumber = numberFromInput();

		checkIfNumberHasAlreadyBeenTyped(typedNumbers, givenNumber);
	}
	while (!numbersAreEqual(givenNumber, randomisedNumber));
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
	while ((!typedNumberAndChar(&number, &c) || c != NEW_LINE_CHARACTER) && cleanedStream() || number < MIN_NUMBER || number > MAX_NUMBER);

	return number;
}

int typedNumberAndChar(int *number, char *c)
{
	return scanf("%d%c", number, c) == 2;
}

int cleanedStream()
{
	while (getchar() != NEW_LINE_CHARACTER);
	
	return 1;
}

void checkIfNumberHasAlreadyBeenTyped(int *typedNumbers, int number)
{
	if(!alreadyTypedNumber(typedNumbers, number))
	{
		countNewNumber(typedNumbers, number);
		printWrongGuess(number);
	}
	else
	{
		puts("You have already given that number.");
	}
}

int alreadyTypedNumber(int *typedNumbers, int number)
{
	return typedNumbers[typedNumbersIndex(number)];
}

void countNewNumber(int *typedNumbers, int number)
{
	typedNumbers[typedNumbersIndex(number)] = 1;
	++tries;
}

int typedNumbersIndex(int number)
{
	return number - MIN_NUMBER;
}

void printWrongGuess(int number)
{
	if(!numbersAreEqual(number, randomisedNumber))
	{
		printf("Wrong! Try again. ");
		printTip(number);
	}
}

int numbersAreEqual(int a, int b)
{
	return a == b;
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