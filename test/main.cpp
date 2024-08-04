#include <iostream>
#include <string>
#include "libs/random.h"
#include "game.h"

int main()
{
	auto enem1 = Enemy{ .x = 2, .y = 3 };

	game_loop({enem1, });

	return 0; 
} 