/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:25:36 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/10/28 22:27:44 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *halp()
{
	printf("Halp ze philosophers\n");
	return 0;
}

long long	time_thingy(void)
{
	struct	timeval time;
	int		time_thingy;

	gettimeofday(&time, NULL);
	time_thingy = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_thingy);
}

void	init(t_data *data)
{
	data->number_of_philosophers = ft_atoi(data->argv[1]);
	data->time_to_die = ft_atoi(data->argv[2]);
	data->time_to_eat = ft_atoi(data->argv[3]);
	data->time_to_sleep = ft_atoi(data->argv[4]);
	if(data->argc == 6)
		data->times_each_philo_must_eat = ft_atoi(data->argv[5]);
	data->philo = ft_calloc((data->number_of_philosophers), sizeof(t_philo));
}

void	create_threads(t_data *data)
{
	int i;

	i = 0;
	while(i < data->number_of_philosophers)
	{
		pthread_create(&data->philo[i].thred, NULL, &halp, &data->philo[i]);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_philosophers)
	{
		pthread_join(data->philo[i].thred, NULL);
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
	// (void)argc;
	// (void)argv;
	// pthread_t philo1;
	// pthread_t philo2;
	//routine();
		//eat();
		//sleep();
		//think();
		//die();
	return 0;
}
