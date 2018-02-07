/*
** EPITECH PROJECT, 2018
** print
** File description:
** print
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "matchstick.h"

void error_match(int max_matchs)
{
	char *part1 = "Error: you cannot remove more than ";
	char *part2 = " matches per turn\n";

	write(1, part1, my_strlen(part1));
	my_put_nbr(max_matchs);
	write(1, part2, my_strlen(part2));
}

void error_line(void)
{
	char *error = "Error: this line is out of range\n";

	write(1, error, my_strlen(error));
}

void print_stars(int nb)
{
	for (int i = 0; i < nb; i++)
		write(1, "*", 1);
	write(1, "\n", 1);
}

void print_map(map_t map)
{
	int space = 0;
	int width = (2 * map.row) - 1;

	print_stars(width + 2);
	for (int i = 0; i < map.row; i++) {
		space = (width - ((2 * i) + 1)) / 2;
		write(1, "*", 1);
		for (int j = 0; j < space; j++)
			write(1, " ", 1);
		for (int j = 0; j < map.match[i]; j++)
			write(1, "|", 1);
		space = width - space - map.match[i];
		for (int j = 0; j < space; j++)
			write(1, " ", 1);
		write(1, "*", 1);
		write(1, "\n", 1);
	}
	print_stars(width + 2);
	write(1, "\n", 1);
}

void print_void_map(map_t map)
{
	int space = 0;
	int width = (2 * map.row) - 1;

	print_stars(width + 2);
	for (int i = 0; i < map.row; i++) {
		space = (width - ((2 * i) + 1)) / 2;
		write(1, "*", 1);
		for (int j = 0; j < space; j++)
			write(1, " ", 1);
		for (int j = 0; j < map.match[i]; j++)
			write(1, "|", 1);
		space = width - space - map.match[i];
		for (int j = 0; j < space; j++)
			write(1, " ", 1);
		write(1, "*", 1);
		write(1, "\n", 1);
	}
	print_stars(width + 2);
}
