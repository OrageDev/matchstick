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
#include "gnl.h"
#include "matchstick.h"

void sub_matches(map_t *map, int line, int matches)
{
	if (map->turn != 1)
		write(1, "Player ", 7);
	else
		write(1, "AI ", 3);
	if (matches > map->match[line - 1])
		matches = map->match[line - 1];
	map->match[line - 1] = map->match[line - 1] - matches;
	my_printf("removed %d match(es) from line %d\n", matches, line);
	print_map(map);
}

void win_message(map_t *map)
{
	char *ai_lost = "I lost... snif... but I'll get you next time!!\n";
	char *player_lost = "You lost, too bad...\n";

	if (map->turn == 1) {
		write(1, ai_lost, my_strlen(ai_lost));
		exit(1);
	} else {
		write(1, player_lost, my_strlen(player_lost));
		exit(2);
	}
}

int is_won(map_t *map)
{
	for (int i = 0; i < map->row; i++) {
		if (map->match[i] != 0)
			return (0);
	}
	return (1);
}

void matchstick(map_t *map)
{
	int end = 0;

	while (!end) {
		if (!map->success) {
			get_player_turn(map);
		} else if (map->turn == 1) {
			write(1, "\nYour turn:\n", 12);
			get_player_turn(map);
		} else {
			write(1, "\nAI's turn...\n", 13);
			ai_turn(map);
		}
		end = is_won(map);
	}
	win_message(map);
}

int main(int ac, char **av)
{
	map_t *map = malloc (sizeof(map_t));

	if (ac != 3)
		return (84);
	prepare_map(map, av);
	print_map(map);
	matchstick(map);
	return (0);
}
