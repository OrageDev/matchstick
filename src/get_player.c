/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "gnl.h"
#include "matchstick.h"

int get_line(void)
{
	char *str_line;
	int line;

	write(1, "Line: ", 6);
	str_line = get_next_line(0);
	if (!str_line)
		exit (84);
	line = my_atoi(str_line);
	return (line);
}

int get_matches(void)
{
	char *str_matches;
	int matches;

	write(1, "Matches: ", 9);
	str_matches = get_next_line(0);
	if (!str_matches)
		exit (84);
	matches = my_atoi(str_matches);
	return (matches);
}

void get_player_turn(map_t *map)
{
	int line;
	int matches;

	line = get_line();
	if (line < 1 || line > map->row) {
		write(1, "Error: this line is out of range\n", 33);
		map->success = 0;
		return;
	}
	matches = get_matches();
	if (matches < 1 || matches > map->max_matches) {
		my_printf("%s %d %s", "Error: you cannot remove more than", \
		       map->max_matches, "matches per turn\n");
		map->success = 0;
		return;
	}
	map->success = 1;
	map->turn = 2;
	sub_matches(map, line, matches);
	return;
}
