/*
** EPITECH PROJECT, 2018
** get_ai
** File description:
** get_ai
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "matchstick.h"

int get_all_xor(map_t *map)
{
	int xor = map->match[0];

	for (int i = 1; i < map->row; i++) {
		xor = xor ^ map->match[i];
	}
	return (xor);
}

void emergency_remove(map_t *map)
{
	int ok = 0;
	int line;

	srand(time(NULL));
	while (!ok) {
		line = (rand() % map->row);
		if (map->match[line] != 0)
			ok = 1;
	}
	sub_matches(map, (line + 1), 1);
}

void get_ai(map_t *map)
{
	int xor = 0;

	for (int i = 0; i < map->row; i++) {
		for (int j = 0; j < map->match[i]||j < map->max_matches; j++) {
			map->match[i] -= j;
			xor = get_all_xor(map);
			map->match[i] += j;
			if (xor == 1 && j != 0) {
				sub_matches(map, (i + 1), j);
				return ;
			}
		}
	}
	emergency_remove(map);
}

void ai_turn(map_t *map)
{
	map->turn = 1;
	get_ai(map);
}