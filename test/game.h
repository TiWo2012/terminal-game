#pragma once
#include <initializer_list>

struct Enemy {
	short x, y;
};

struct Player {
	std::string name;
	bool ally = true;
	short x = 0, y = 0;
};

struct game_data {
	short h = 5, w = 5;
	short goal_x = 5, goal_y = 5;
	Player player;
} game;

void print_g_data(game_data game)
{
	std::cout << "game heigth = " << game.h << "\ngame width = " << game.w << "\nally ? " << std::boolalpha << game.player.ally << "\ngoal x = " << game.goal_x << "\ngoal y = " << game.goal_y << "\nplayer x = " << game.player.x << "\nplayer y = " << game.player.y << "\nplayer name = " << game.player.name;
}

void print_p_data(game_data game)
{
	std::cout << "goal x = " << game.goal_x << "\ngoal y = " << game.goal_y << "\nplayer x = " << game.player.x << "\nplayer y = " << game.player.y;
}

void print_e_data(std::initializer_list<Enemy> enemys)
{
	for (auto enemy : enemys)
	{
		static int counter = 0;
		std::cout << "x, y from number " << counter << " are x: " << enemy.x << "and the y is: " << enemy.y;
	}
}

bool check_won(game_data game)
{
	if (game.player.x == game.goal_x)
	{
		if (game.player.y == game.goal_y)
		{
			std::cout << "you won!";
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

bool check_enemy(Enemy enemy)
{
	if (game.player.x == enemy.x)
	{
		if (game.player.y == enemy.y)
		{
			std::cout << "you lost!";
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int game_loop(std::initializer_list<Enemy> enemys)
{
	static long long counter = 0;
	char in;
	std::cin >> in;
	if (counter <  1 )
	{
		print_g_data(game);
	}

	counter++;

	if (in == 'w')
	{
		for (auto enemy : enemys)
		{
			if (check_enemy(enemy) == false)
			{
				if (check_won(game) == false)
				{
					game.player.x += 1;
					print_p_data(game);
					print_e_data(enemys);
					game_loop(enemys);
				}
			}
		}
	}
	else if (in == 's')
	{
		for (auto enemy : enemys)
		{
			if (check_enemy(enemy) == false)
			{
				if (check_won(game) == false)
				{
					game.player.x += 1;
					print_p_data(game);
					print_e_data(enemys);
					game_loop(enemys);
				}
			}
		}
	}
	else if (in == 'a')
	{
		for (auto enemy : enemys)
		{
			if (check_enemy(enemy) == false)
			{
				if (check_won(game) == false)
				{
					game.player.x += 1;
					print_p_data(game);
					print_e_data(enemys);
					game_loop(enemys);
				}
			}
		}
	}
	else if (in == 'd')
	{
		for (auto enemy : enemys)
		{
			if (check_enemy(enemy) == false)
			{
				if (check_won(game) == false)
				{
					game.player.x += 1;
					print_p_data(game);
					print_e_data(enemys);
					game_loop(enemys);
				}
			}
		}
	}
	else if (in == 'p')
	{
		print_g_data(game);
		print_e_data(enemys);
		game_loop(enemys);
	}
	else if (in == 'x')
	{
		std::cout << "program finished";
		return 0;
	}
	else
	{
		std::cerr << "unrecognized move \n";
		print_e_data(enemys);
		game_loop(enemys);
	}
}