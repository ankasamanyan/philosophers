/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:36 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/02 03:28:45 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*halp(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2)
		usleep(philo->data->time_to_eat * 0.5);
	while (LIFE_IS_MEANUNGLESS_AND_WE_ALL_GONNA_DIE)
	{
		if (time_to_eat(philo))
			break ;
		if (time_to_sleep(philo))
			break ;
		if (time_to_think(philo))
			break ;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	// input_check();
	set_the_table(&data, argc, argv);
	invite_the_philosophers(&data);
	get_rid_of_the_bodies(&data);
	return (0);
}
