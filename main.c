#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "constants.h"
#include "communicator.h"
#include "typedNumbers.h"

void validateRange(void);
void loop(void);
int randomNumber(void);
void checkIfNumberHasAlreadyBeenTyped(int *typedNumbers, int number);
int numbersAreEqual(int a, int b);

int tries = 0;
int randomisedNumber;

int main(void)
{
	srand(time(NULL));
	puts(GAME_TITLE);
	validateRange();
	loop();
	printSuccess();

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

void checkIfNumberHasAlreadyBeenTyped(int *typedNumbers, int number)
{
	if(!alreadyTypedNumber(typedNumbers, number))
	{
		countNewNumber(typedNumbers, number);
		printWrongGuess(number);
	}
	else
	{
		printAlreadyTypedNumber();
	}
}

int numbersAreEqual(int a, int b)
{
	return a == b;
}