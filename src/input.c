#include <stdio.h>

#include "input.h"
#include "constants.h"

int numberFromInput(void)
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

int cleanedStream(void)
{
	while (getchar() != NEW_LINE_CHARACTER);
	
	return 1;
}