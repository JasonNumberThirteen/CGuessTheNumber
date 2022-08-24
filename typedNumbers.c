#include "constants.h"
#include "typedNumbers.h"

extern int tries;

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