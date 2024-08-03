#include <iostream>
#include <string>

struct Player {
	std::string name;
	bool ally;
	short x, y;
};


struct game_data {
	short h, w;
	short enemys;
	short goal_x, goal_y;

	Player player;
};

void print_g_data(game_data game)
{
	std::cout << "game heigth = " << game.h << "\ngame width = " << game.w << "\nally ? " << std::boolalpha << game.player.ally << "\nhow many enemys? " << game.enemys << "\ngoal x = " << game.goal_x << "\ngoal y = " << game.goal_y << "\nplayer x = " << game.player.x << "\nplayer y = " << game.player.y << "\nplayer name = " << game.player.name;
}

void print_g_data(game_data game)
{
	std::cout << "goal x = " << game.goal_x << "\ngoal y = " << game.goal_y << "\nplayer x = " << game.player.x << "\nplayer y = " << game.player.y;
}

int main()
{
	Player p1 = { .name = "p1", .ally = 1, .x = 0, .y = 0};
	game_data game = {.h = 5, .w = 5, .enemys = 1, .goal_x = 5, .goal_y = 5, .player = p1};
	std::cout << "Hello CMake." << std::endl;
	while (true)
	{
		char in;
		std::cin >> in;
		if (in == 'w')
		{
			game.player.y -= 1;
		}
		else if (in == 's')
		{
			game.player.y += 1;
		}
		else if (in == 'a') 
		{
			game.player.x -= 1;
		}
		else if (in == 'd') 
		{
			game.player.x += 1;
		}
		else if (in == 'p')
		{
			print_g_data(game);
		}
		else if (in == 'x')
		{
			break;
		} 
		else
		{ 
			std::cerr << "unrecognized move \n";
		} 
	}
	return 0; 
} 