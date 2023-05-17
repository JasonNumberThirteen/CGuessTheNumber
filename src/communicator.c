#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "constants.h"
#include "communicator.h"

extern int tries;
extern int randomisedNumber;

void printGameTitle(void)
{
	puts(GAME_TITLE);
}

void printWrongGuess(int number)
{
	if(!numbersAreEqual(number, randomisedNumber))
	{
		printf("Wrong! Try again. ");
		printTip(number);
	}
}

void printAlreadyTypedNumber(void)
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

void printSuccess(void)
{
	printf("You guessed right! It is %d!\nTRIES: %d", randomisedNumber, tries);
}