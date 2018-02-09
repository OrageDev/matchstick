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
	        return (-2);
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
		return (-2);
	matches = my_atoi(str_matches);
	return (matches);
}

void is_line_good(map_t *map, int line)
{
	if (line == 0 || line > map->row) {
		write(1, "Error: this line is out of range\n", 33);
		map->success = 0;
		return;
	} else if (line < 0) {
		write(1, "Error: invalid input (positive number expected)\n", \
		      48);
		map->success = 0;
		return;
	}
}
void is_match_good(map_t *map, int matches, int line)
{
	if (matches > map->max_matches) {
		my_printf("%s %d %s", "Error: you cannot remove more than", \
			  map->max_matches, "matches per turn\n");
		map->success = 0;
		return;
	} else if (matches == 0) {
		write(1, "Error: you have to remove at least one match\n", 45);
		map->success = 0;
		return;
	}
	if (matches < 0){
		write(1, "Error: invalid input (positive number expected)\n", \
		      48);
		map->success = 0;
		return;
	} else if (matches > map->match[line - 1]) {
		write(1, "Error: not enough matches on this line\n", 39);
		map->success = 0;
		return;
	}
}

int get_player_turn(map_t *map)
{
	int line;
	int matches;

	if (map->success == 0)
		map->success = 1;
	line = get_line();
	if (line == -2)
		return (-2);
	is_line_good(map, line);
	if (map->success == 0)
		return (-1);
	matches = get_matches();
	if (matches == -2)
		return (-2);
	is_match_good(map, matches, line);
	if (map->success == 0)
		return (1);
	map->success = 1;
	map->turn = 2;
	sub_matches(map, line, matches);
	return (0);
}
