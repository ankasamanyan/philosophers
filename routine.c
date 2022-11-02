/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:29:24 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/02 04:24:37 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_eat(t_philo	*philo)
{
	long long	time;

	time = timer();
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	if (code_blue(philo))
		return (put_down_forks(philo));
	printf("%s%lld Philosopher %i has taken a fork%s\n", YELLOW,
		timer() - philo->data->start_time, philo->id, RESET);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	if (code_blue(philo))
		return (put_down_forks(philo));
	printf("%s%lld Philosopher %i has taken a fork%s\n", PURPLE,
		timer() - philo->data->start_time, philo->id, RESET);
	philo->last_meal = timer();
	if (code_blue(philo))
		return (put_down_forks(philo));
	printf("%s%lld Philosopher %i is eating%s\n", PINK,
		timer() - philo->data->start_time, philo->id, RESET);
	while (time + (philo->data->time_to_eat / 1000) > timer())
		usleep(100);
	philo->meals++;
	put_down_forks(philo);
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
	if (code_blue(philo))
		return (put_down_forks(philo));
	printf("%s%lld Philosopher %i is sleeping%s\n", GREEN,
		timer() - philo->data->start_time, philo->id, RESET);
	while (time + (philo->data->time_to_sleep / 1000) > timer())
		usleep(100);
	return (0);
}

int	time_to_think(t_philo *philo)
{
	if (code_blue(philo))
		return (1);
	printf("%s%lld Philosopher %i is thinking%s\n", SKY,
		timer() - philo->data->start_time, philo->id, RESET);
	return (0);
}

int	code_blue(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->pulse_check);
	if (philo->meals == philo->data->times_philo_must_eat
		|| philo->data->code_blue == 1)
	{
		pthread_mutex_unlock(&philo->data->pulse_check);
		return (1);
	}
	if ((timer() - philo->last_meal) * 1000 > philo->data->time_to_die)
	{
		philo->data->code_blue = 1;
		printf("%s%lld Philosopher %i died. RIP%s\n", ON_PINK,
			timer() - philo->data->start_time, philo->id, RESET);
		pthread_mutex_unlock(&philo->data->pulse_check);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->pulse_check);
	return (0);
}
