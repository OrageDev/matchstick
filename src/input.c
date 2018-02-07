/*
** EPITECH PROJECT, 2018
** input
** File description:
** input
*/

#include <stdlib.h>
#include <unistd.h>
#include "matchstick.h"

int get_line(map_t map)
{
	int lines = 0;
	char *lines_str;

	write(1, "Line: ", 6);
	lines_str = get_next_line(0);
	if (!lines_str) {
		free(map.match);
		exit(0);
	}
	lines = my_atoi(lines_str);
	free(lines_str);
	return (lines);
}

int get_matchs(map_t map)
{
	int matchs = 0;
	char *matchs_str;

	write(1, "Matchs: ", 8);
	matchs_str = get_next_line(0);
	if (!matchs_str) {
		free(map.match);
		exit(0);
	}
	matchs = my_atoi(matchs_str);
	free(matchs_str);
	return (matchs);
}
