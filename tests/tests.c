/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "matchstick.h"

void print_stars(int stars);
int my_main(int ac, char **av);

map_t *map;

Test(print_map, stars_7)
{
	char *stars = "*******\n";

	cr_redirect_stdout();
	print_stars(7);
	cr_assert_stdout_eq_str(stars);
}

Test(print_map, av_to_parameters)
{
	char *av[2] = {"4", "5"};
	int line_matches[2] = {4, 5};

	cr_assert_eq(my_atoi(av[0]), line_matches[0]);
	cr_assert_eq(my_atoi(av[1]), line_matches[1]);
}

Test(print_map, parameters)
{
	char *av1[1] = {"4"};
	char *av4[3] = {"4", "5", "0"};
	int ac1 = 1;
	int ac4 = 4;
	int return_value;

	return_value = my_main(ac1, av1);
	cr_assert_eq(return_value, 84);
	return_value = my_main(ac4, av4);
	cr_assert_eq(return_value, 84);
}
