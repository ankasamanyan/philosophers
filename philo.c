/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:36 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/03 15:50:50 by akasaman         ###   ########.fr       */
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
		usleep(philo->data->time_to_eat);
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

int	main(int argc, char *argv[])
{
	t_data	data;

	input_check(argc, argv);
	set_the_table(&data, argc, argv);
	invite_the_philosophers(&data);
	check_the_pulse(&data);
	get_rid_of_the_bodies(&data);
	return (0);
}
