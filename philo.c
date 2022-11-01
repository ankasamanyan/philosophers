/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:36 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/01 20:23:00 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *halp(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2)
		usleep(philo->data->time_to_eat * 0.5);
	while (life_is_meaningless_and_we_all_gonna_die)
	{
		if (time_to_eat(philo))
			break;
		if (time_to_sleep(philo))
			break;
		if (time_to_think(philo))
			break;
	}
	return 0;
}

int	code_blue(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->pulse_check);
	if (philo->meals == philo->data->times_philo_must_eat || philo->data->code_blue == 1)
	{
		pthread_mutex_unlock(&philo->data->pulse_check);
		return (1);
	}
	if	((timer() - philo->last_meal) * 1000 > philo->data->time_to_die)
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

int	time_to_eat(t_philo	*philo)
{
	long long	time;

	time = timer();
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	if (code_blue(philo))
		return (put_down_forks(philo));
	printf("%s%lld Philosopher %i has taken a fork%s\n", YELLOW,
		timer() - philo->data->start_time, philo->id,RESET);
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
	// usleep(philo->data->time_to_eat);
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
	printf("%s%lld Philosopher %i is sleeping%s\n",  GREEN,
		timer() - philo->data->start_time, philo->id, RESET);
	while (time + (philo->data->time_to_sleep / 1000) > timer())
		usleep(100);
	// usleep(philo->data->time_to_sleep);
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

long long	timer(void)
{
	struct	timeval time;
	int		time_thingy;

	gettimeofday(&time, NULL);
	time_thingy = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_thingy);
}

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
		// data->philo[i].code_blue = 0;
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

int main(int argc, char *argv[])
{
	t_data	data;

	// input_check();
	set_the_table(&data, argc, argv);
	invite_the_philosophers(&data);
	get_rid_of_the_bodies(&data);
	
	return 0;
}
