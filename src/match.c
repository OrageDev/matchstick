/*
** EPITECH PROJECT, 2018
** match
** File description:
** match
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "matchstick.h"

int get_player_input(int input, map_t map)
{
	int lines = 0;
	int matchs = 0;

	if (input == 1) {
		lines = get_line(map);
		return (lines);
	} else if (input == 2) {
		matchs = get_matchs(map);
		return (matchs);
	}
	return (0);
}

map_t player_turn(map_t map)
{
	int lines = 0;
	int matchs = 0;

        lines = get_player_input(1, map);
	if (lines < 1 || lines > map.row) {
		map.success = 0;
		error_line();
		return (map);
	}
	matchs = get_player_input(2, map);
	if (!(matchs > 0 && matchs <= map.max_matchs)) {
		map.success = 0;
		error_match(map.max_matchs);
		return (map);
	}
	if (matchs > map.match[lines - 1])
		map.match[lines - 1] = 0;
	else if (map.match[lines - 1] == 0)
		map.match[lines - 1] = 0;
	else
		map.match[lines - 1] = map.match[lines - 1] - matchs;
	map.success = 1;
	return (map);
}

int *get_xor_line(map_t map)
{
	int *xor_line = malloc (sizeof(int) * 2);

	xor_line[0] = map.match[0];
	for (int i = 1; i < map.row; i++)
		if (map.match[i] > map.max_matchs)
			xor_line[0] = xor_line[0]^map.max_matchs;
		else
			xor_line[0] = xor_line[0]^map.match[i];
	for (int i = 0; i < map.row; i++) {
		if ((map.match[i]^xor_line[0]) < map.match[i]) {
			xor_line[0] = map.match[i]^xor_line[0];
			xor_line[1] = i;
			return (xor_line);
		}
	}
	return (xor_line);
}

int get_free_line(map_t map)
{
	for (int i = 0; i < map.row; i++)
		if (map.match[i] > 0)
			return (i);
	return (-1);
}

map_t ai_turn(map_t map)
{
	char *ai[3] = {"AI's turn...\n", "AI removed ", " match(es) from line "};
	int *xor_line = get_xor_line(map);

	if (xor_line[0] <= 0)
		xor_line[0] = 1;
	if (xor_line[1] <= 0)
		xor_line[1] = get_free_line(map);
	map.match[xor_line[1]] = map.match[xor_line[1]] - xor_line[0];
	write(1, ai[0], my_strlen(ai[0]));
	write(1, ai[1], my_strlen(ai[1]));
	my_put_nbr(xor_line[0]);
	write(1, ai[2], my_strlen(ai[2]));
	my_put_nbr(xor_line[1]);
	write(1, "\n", 1);
	free(xor_line);
	return (map);
}
