/*
** EPITECH PROJECT, 2018
** foo
** File description:
** foo
*/

#include <stdlib.h>
#include "my.h"
#include "matchstick.h"

int is_num(char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int my_atoi(char *str)
{
	int nbr = 0;
	int is_neg = 1;

	while (*str) {
		if (*str == '-') {
			is_neg = -1;
			str++;
		}
		if (!(is_num(*str)))
			return ((nbr * is_neg) / 10);
		nbr = ((*str - '0') + nbr);
		nbr = nbr * 10;
		str++;
	}
	return ((nbr * is_neg) / 10);
}

char *my_strcat(char *buffer, char *ret, int i)
{
	char *tmp = ret;

	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (ret);
	for (int j = 0; j < (i - 1); j++) {
		if (j > 0 && j == (i - 1))
			ret[j] = tmp[j];
		else
			ret[j] = buffer[0];
	}
	ret[i + 1] = '\0';
	return (ret);
}

map_t prepare_map(map_t map)
{
	int width = (2 * map.row) - 1;

	map.match = malloc (sizeof(int) * (1 + width));
	if (!map.match) {
		map.success = 0;
		return (map);
	}
	for (int i = 0; i < map.row; i++)
		map.match[i] = (2 * i) + 1;
	return (map);
}
