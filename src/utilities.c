/*
** EPITECH PROJECT, 2018
** utilities
** File description:
** utilities
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "matchstick.h"

void print_stars(int stars)
{
	for (int i = 0; i < stars; i++)
		write(1, "*", 1);
	write(1, "\n", 1);
}

void print_map(map_t *map)
{
	int space;
	int width = (2 * map->row) - 1;

	print_stars(width + 2);
	for (int i = 0; i < map->row; i++) {
		space = (width - ((2 * i) + 1)) / 2;
		write(1, "*", 1);
		for (int j = 0; j < space; j++)
			write(1, " ", 1);
		for (int j = 0; j < map->match[i]; j++)
			write(1, "|", 1);
		space = width - space - map->match[i];
		for (int j = 0; j < space; j++)
			write(1, " ", 1);
		write(1, "*\n", 2);
	}
	print_stars(width + 2);
}

int my_sec_atoi(char *str)
{
	int nbr = 0;
	int is_neg = 1;

	while (*str) {
		if (*str == '-') {
			is_neg = -1;
			str++;
		} else if (*str == ' ') {
			str++;
		} else {
			nbr = ((*str - '0') + nbr);
			nbr = nbr * 10;
			str++;
		}
	}
	return ((nbr * is_neg) / 10);
}

void prepare_map(map_t *map, char **av)
{
	map->row = my_sec_atoi(av[1]);
	map->max_matches = my_sec_atoi(av[2]);
	map->success = 1;
	map->turn = 1;
	map->match = malloc (sizeof(int) * map->row);
	if (!map->match) {
		map->success = 0;
		return;
	}
	for (int i = 0; i < map->row; i++)
		map->match[i] = (2 * i) + 1;
}
