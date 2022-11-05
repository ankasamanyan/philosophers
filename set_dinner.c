/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:42:30 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/05 16:41:39 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(2, "\033[44mWrong number of arguments!\033[0m\n", 36);
		return (0);
	}
	
	while (argv[i])
	{
		if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[2]) == 0 
			|| ft_atoi(argv[3]) == 0 || ft_atoi(argv[4]) == 0)
			return(write(2, "\033[44mInvalid input!\033[0m\n", 25));
		if (argc == 6 && ft_atoi(argv[5]) == 0)
			return(write(2, "\033[44mStahp being so mean! Let them eat!\033[0m\n", 45));
			
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return(write(2, "\033[44mInvalid input!\033[0m\n", 25));
			j++;
		}
		if (ft_strlen(argv[i]) > 10)
			return(write(2, "\033[44mInvalid input!\033[0m\n", 25));
		if (ft_strlen(argv[i]) > 10)
			return (420);
		if ((ft_strncmp("2147483647", argv[i], 11) < 0
			&& ft_strlen(argv[i]) == 10))
			return(write(2, "\033[44mInvalid input!\033[0m\n", 25));
		i++;
	}
	return (0);
}

int	no_one_showed_up(t_philo *philo)
{
	if (philo->data->number_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%s%lld Philosopher %i has taken a fork%s\n", YELLOW,
			timer() - philo->data->start_time, philo->id, RESET);
		usleep(philo->data->time_to_die);
		put_down_forks(philo);
		return (1);
	}
	return (0);
}

void	set_the_table(t_data *data, int argc, char **argv)
{
	data->start_time = timer();
	data->code_blue = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	else
		data->times_philo_must_eat = -1;
	data->philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	data->forks = ft_calloc(data->number_of_philosophers,
			sizeof(pthread_mutex_t));
}

void	invite_the_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philo[i].data = data;
		data->philo[i].meals = 0;
		data->philo[i].id = i + 1;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].left_fork = &data->forks[i];
		if (i != (data->number_of_philosophers - 1))
			data->philo[i].right_fork = &data->forks[i + 1];
		else
			data->philo[i].right_fork = &data->forks[0];
		pthread_create(&data->philo[i].thred, NULL, &halp, &data->philo[i]);
		i++;
	}
	pthread_mutex_init(&data->pulse_check, NULL);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
