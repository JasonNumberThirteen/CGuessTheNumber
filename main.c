#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "constants.h"
#include "typedNumbers.h"

void validateRange(void);
void loop(void);
int randomNumber(void);
void checkIfNumberHasAlreadyBeenTyped(int *typedNumbers, int number);
void printWrongGuess(int number);
void printAlreadyTypedNumber(void);
int numbersAreEqual(int a, int b);
void printTip(int givenNumber);
void printSuccess(void);

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

void printAlreadyTypedNumber()
{
	puts("You have already given that number.");
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

void printSuccess()
{
	printf("You guessed right! It is %d!\nTRIES: %d", randomisedNumber, tries);
}