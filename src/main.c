#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "communicator.h"

int main(void)
{
	srand(time(NULL));
	printGameTitle();
	validateRange();
	loop();
	printSuccess();

	return 0;
}