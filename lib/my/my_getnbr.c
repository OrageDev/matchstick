/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
**
*/

int my_getnbr(char const *str)
{
	int neg = 1;
	int i = 0;
	int nbr = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			neg = neg * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i]) {
		nbr = nbr * 10 + (str[i] - '0');
		i++;
		if (nbr < 0)
			return 0;
	}
	nbr = nbr * neg;
	if (nbr == 0 && str[1] != '0')
		nbr = -2147483648;
	return nbr;
}
