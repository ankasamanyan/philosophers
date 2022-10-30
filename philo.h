/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:54:31 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/10/30 09:04:41 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					argc;
	char				**argv;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_each_philo_must_eat;
	long long			start_time;
	pthread_mutex_t		*forks;
	t_philo				*philo;
	
}	t_data;

typedef struct s_philo
{
	pthread_t			thred;
	int					id;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	t_data				*data;
	
}	t_philo;

/* initializing values */
void		init(t_data *data);
/* time function */
long long	timer(void);
/* halp functions */
int			ft_atoi(char *stringy);
void		*ft_calloc(size_t count, size_t size);
/* thread manipulations */
void		create_threads(t_data *data);
void		join_threads(t_data *data);



#endif