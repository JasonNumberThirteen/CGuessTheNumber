#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "constants.h"
#include "communicator.h"

int main(void)
{
	srand(time(NULL));
	puts(GAME_TITLE);
	validateRange();
	loop();
	printSuccess();

	return 0;
}