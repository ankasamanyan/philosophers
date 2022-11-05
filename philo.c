/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:36 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/05 19:07:57 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*halp(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (no_one_showed_up(philo))
		return (NULL);
	if (philo->id % 2)
		usleep(30000);
	while (LIFE_IS_MEANUNGLESS_AND_WE_ALL_GONNA_DIE)
	{
		if (time_to_eat(philo))
			break ;
		if (time_to_sleep(philo))
			break ;
		if (time_to_think(philo))
			break ;
	}
	return (NULL);
}

void	get_rid_of_the_bodies(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
		pthread_join(data->philo[i++].thred, NULL);
	i = 0;
	while (i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->pulse_check);
	free(data->philo);
	free(data->forks);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (input_check(argc, argv))
		return (0);
	set_the_table(&data, argc, argv);
	invite_the_philosophers(&data);
	check_the_pulse(&data);
	get_rid_of_the_bodies(&data);
	return (0);
}
