/*
** EPITECH PROJECT, 2018
** ai
** File description:
** ai
*/

#include <stdlib.h>
#include <unistd.h>
#include "matchstick.h"

void ai_turn(map_t *map)
{
	int line;
	int matches;
	int ok = 0;

	while (!ok) {
		line = (rand() % map->row) + 1;
		if (map->match[line - 1] > 0)
			ok = 1;
	}
	ok = 0;
	matches = (rand() % map->max_matches) + 1;
	map->turn = 1;
	sub_matches(map, line, matches);
	return;
}
