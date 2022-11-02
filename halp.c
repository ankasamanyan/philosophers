/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:57 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/02 03:11:15 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timer(void)
{
	struct	timeval time;
	int		time_thingy;

	gettimeofday(&time, NULL);
	time_thingy = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_thingy);
}

void	get_rid_of_the_bodies(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_philosophers)
		pthread_join(data->philo[i++].thred, NULL);
	i = 0;
	while(i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->pulse_check);
	free(data->philo);
	free(data->forks);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr_thingy;
	size_t	counter_thingy;

	counter_thingy = count * size;
	ptr_thingy = malloc (counter_thingy);
	if (!ptr_thingy)
		return (NULL);
	return (memset (ptr_thingy, 0, counter_thingy));
}
