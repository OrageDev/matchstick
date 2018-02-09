/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** putstr
*/

#include "my.h"

int my_putstr(char *str)
{
	for (int i = 0; str[i]; i++)
		my_putchar(str[i]);
	return (0);
}
