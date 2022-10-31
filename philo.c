/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:36 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/10/31 19:32:10 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *halp(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	// printf("%sPhilosopher %i:%s Halp ze philosophers\n His left fork: %i\n His right fork: %i\n\n", CYAN, philo->id, RESET, philo->left_fork, philo->right_fork);	// philo->data->id++;
	if (philo->id % 2)
		usleep(philo->data->time_to_eat * 500);
	while (1)
	{
		eat(philo);
		sleep_phill(philo);
		think(philo);
	}
	//die();

	return 0;
}

void	eat(t_philo	*philo)
{
	long long	time;

	time = timer();
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	printf("%s%lld Philosopher %i has take a (left) fork (%i)%s\n", GREEN, timer() - philo->data->start_time, philo->id, philo->left_fork, RESET);
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	printf("%s%lld Philosopher %i has take a (right) fork (%i)%s\n", PURPLE, timer() - philo->data->start_time, philo->id, philo->right_fork, RESET);
	printf("%s%lld Philosopher %i is eating%s\n", PINK, timer() - philo->data->start_time, philo->id, RESET);
	while (time + philo->data->time_to_eat > timer())
		usleep(100);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void	sleep_phill(t_philo *philo)
{
	long long	time;

	time = timer();
	printf("%s%lld Philosopher %i is sleeping%s\n",  YELLOW, timer() - philo->data->start_time, philo->id, RESET);
	while (time + philo->data->time_to_sleep > timer())
		usleep(100);
}

void	think(t_philo *philo)
{
	printf("%s%lld Philosopher %i is thinking %s\n", SKY, timer() - philo->data->start_time, philo->id, RESET);
}

long long	timer(void)
{
	struct	timeval time;
	int		time_thingy;

	gettimeofday(&time, NULL);
	time_thingy = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_thingy);
}

void	init(t_data *data)
{
	data->start_time = timer();
	data->number_of_philosophers = ft_atoi(data->argv[1]);
	data->time_to_die = ft_atoi(data->argv[2]);
	data->time_to_eat = ft_atoi(data->argv[3]);
	data->time_to_sleep = ft_atoi(data->argv[4]);
	if(data->argc == 6)
		data->times_each_philo_must_eat = ft_atoi(data->argv[5]);
	data->philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	data->forks = ft_calloc(data->number_of_philosophers, sizeof(pthread_mutex_t));
}

void	create_threads(t_data *data)
{
	int	i;

	i = 1;
	while(i <= data->number_of_philosophers)
	{
		data->philo[i].data = data;
		data->philo[i].id = i;
		data->philo[i].left_fork = i;
		if (i != data->number_of_philosophers)
			data->philo[i].right_fork = i + 1;
		else
			data->philo[i].right_fork = 1;
		pthread_create(&data->philo[i].thred, NULL, &halp, &data->philo[i]);
		i++;
	}
	i = 1;
	while(i <= data->number_of_philosophers)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 1;
	while(i <= data->number_of_philosophers)
	{
		pthread_join(data->philo[i].thred, NULL);
		i++;
	}
	i = 1;
	while(i <= data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_data	data;
	data.argc = argc;
	data.argv = argv;

	// input_check();

	init(&data);
	create_threads(&data);
	//routine();
	join_threads(&data);

	// printf("number_of_philosophers: %i\ntime_to_die: %i\ntime_to_eat: %i\ntime_to_sleep: %i\n",data.number_of_philosophers, data.time_to_die,data.time_to_eat, data.time_to_sleep );
	return 0;
}
