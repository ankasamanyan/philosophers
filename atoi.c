#include "philo.h"

int		ft_atoi(char *stringy)
{
	int		number;
	int		sign;

	number = 0;
	sign = 1;
	while (*stringy == 32 || (*stringy >= 9 && *stringy <= 13))
		stringy++;
	if (*stringy == '-')
		sign = -1;
	if (*stringy == '-' || *stringy == '+')
		stringy++;
	while (*stringy >= '0' && *stringy <= '9')
		number = number * 10 + (*stringy++ - '0');
	return(sign * number);
}
