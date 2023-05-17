#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "input.h"
#include "constants.h"
#include "communicator.h"
#include "typedNumbers.h"

int tries = 0;
int randomisedNumber;

void validateRange(void)
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

void loop(void)
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

int randomNumber(void)
{
	return rand() % MAX_NUMBER + MIN_NUMBER;
}

int numbersAreEqual(int a, int b)
{
	return a == b;
}