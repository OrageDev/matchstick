/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "matchstick.h"

int is_won(map_t map)
{
	for (int i = 0; i < map.row; i++)
		if (map.match[i])
			return (0);
	print_void_map(map);
	return (1);
}

void exit_match(int turn)
{
	char *ai_lost = "I lost... snif... but I'll get you next time!!\n";
	char *player_lost = "You lost, too bad...\n";

	if (turn == 0) {
		write(1, ai_lost, my_strlen(ai_lost));
		exit(1);
	} else {
		write(1, player_lost, my_strlen(player_lost));
		exit(2);
	}
}

void matchstick(map_t map, int turn)
{
	char *u_turn = "Your turn:\n";

	if (map.success == 0) {
		print_map(map);
		write(1, u_turn, my_strlen(u_turn));
		map = player_turn(map);
		turn = 1;
	} else if (turn == 0) {
		print_map(map);
		write(1, u_turn, my_strlen(u_turn));
		map = player_turn(map);
		turn = 1;
	} else {
		print_map(map);
		map = ai_turn(map);
		turn = 0;
	}
}

void main_loop(map_t map)
{
	int end = 0;
	static int turn = 0;

	while (!end) {
		matchstick(map, turn);
		end = is_won(map);
	}
	free(map.match);
	exit_match(turn);
}

int main(int ac, char **av)
{
	map_t map;

	if (ac != 3)
		return (84);
	map.row = my_atoi(av[1]);
	map.max_matchs = my_atoi(av[2]);
	map.success = 1;
	map = prepare_map(map);
	if ((map.success == 1) && (map.row > 0 && map.row < 100)) {
	        main_loop(map);
	} else {
		return (84);
	}
	return (0);
}
