#include <stdio.h>
#include <stdlib.h>

#include "communicator.h"
#include "typedNumbers.h"

extern int tries;
extern int randomisedNumber;

void printWrongGuess(int number)
{
	if(!numbersAreEqual(number, randomisedNumber))
	{
		printf("Wrong! Try again. ");
		printTip(number);
	}
}

void printAlreadyTypedNumber()
{
	puts("You have already given that number.");
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