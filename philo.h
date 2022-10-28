/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:54:31 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/10/28 12:07:52 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int			argc;
	char		**argv;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_each_philo_must_eat;
	t_philo		*philo;
	
}	t_data;

typedef struct s_philo
{
	pthread_t			id;
	int					left_fork;
	int					right_fork;
	int					last_meal;
	t_data				*data;
	
}	t_philo;

/* halp functions */
int			ft_atoi(char *stringy);
/* initializing values */
void		init(t_data *data);
/* time function */
long long	time_thingy(void);


#endif