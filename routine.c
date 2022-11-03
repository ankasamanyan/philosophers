/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:29:24 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/03 13:51:06 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_eat(t_philo	*philo)
{
	long long	time;

	time = timer();
	// while (philo->data->code_blue == 0)
	// {
		
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		if (philo->data->code_blue)
			return (put_down_forks(philo));
		printf("%s%lld Philosopher %i has taken a fork%s\n", YELLOW,
			timer() - philo->data->start_time, philo->id, RESET);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		if (philo->data->code_blue)
			return (put_down_forks(philo));
		printf("%s%lld Philosopher %i has taken a fork%s\n", PURPLE,
			timer() - philo->data->start_time, philo->id, RESET);
		philo->last_meal = timer();
		if (philo->data->code_blue)
			return (put_down_forks(philo));
		printf("%s%lld Philosopher %i is eating%s\n", PINK,
			timer() - philo->data->start_time, philo->id, RESET);
		while (time + (philo->data->time_to_eat / 1000) > timer())
			usleep(100);
		philo->meals++;
		put_down_forks(philo);
	// }
	return (0);
}

int	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	return (1);
}

int	time_to_sleep(t_philo *philo)
{
	long long	time;

	time = timer();
	// while (philo->data->code_blue == 0)
	// {		
		if (philo->data->code_blue)
			return (put_down_forks(philo));
		printf("%s%lld Philosopher %i is sleeping%s\n", GREEN,
			timer() - philo->data->start_time, philo->id, RESET);
		while (time + (philo->data->time_to_sleep / 1000) > timer())
			usleep(100);
	// }
	return (0);
}

int	time_to_think(t_philo *philo)
{
	// while(philo->data->code_blue == 0)
	// {
		if (philo->data->code_blue)
			return (1);
		printf("%s%lld Philosopher %i is thinking%s\n", SKY,
			timer() - philo->data->start_time, philo->id, RESET);
		if (philo->data->code_blue)
			return (1);
	// }
	return (0);
}

void	code_blue(t_data *data)
{
	int	i;

	i = 0;
	while (LIFE_IS_MEANUNGLESS_AND_WE_ALL_GONNA_DIE)
	{
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->pulse_check);
			// if (data->philo[i].meals == data->times_philo_must_eat)
			// {
			// 	pthread_mutex_unlock(&data->pulse_check);
			// 	return ;
			// }
			if ((timer() - data->philo[i].last_meal) * 1000 > data->time_to_die)
			{
				data->code_blue = 1;
				printf("%s%lld Philosopher %i died. RIP%s\n", ON_PINK,
					timer() - data->start_time, data->philo[i].id, RESET);
				pthread_mutex_unlock(&data->pulse_check);
				return ;
			}
			pthread_mutex_unlock(&data->pulse_check);
			i++;
		}
		if(data->code_blue)
			break ;
	}
	// return (0);
}
