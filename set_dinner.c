/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_dinner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:42:30 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/02 02:44:18 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_the_table(t_data *data, int argc, char **argv)
{
	data->start_time = timer();
	data->code_blue = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]) * 1000;
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	else
		data->times_philo_must_eat = -1;
		
	data->philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	data->forks = ft_calloc(data->number_of_philosophers, sizeof(pthread_mutex_t));
}

void	invite_the_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_philosophers)
	{
		data->philo[i].data = data;
		data->philo[i].meals = 0;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].id = i + 1;
		data->philo[i].left_fork = data->philo[i].id;
		if (i != data->number_of_philosophers)
			data->philo[i].right_fork = data->philo[i].id + 1;
		else
			data->philo[i].right_fork = 0;
		pthread_create(&data->philo[i].thred, NULL, &halp, &data->philo[i]);
		i++;
	}
	i = 0;
	while(i < data->number_of_philosophers)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->pulse_check, NULL);
}
