/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:54:31 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/10/24 16:06:55 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

// typedef struct s_philo;

typedef struct s_data
{
	int		argc;
	char	**argv;
	// t_philo	philo;
	
}	t_data;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			last_meal;
	// pthread_t	philo;
	// t_data		data;
	
}	t_philo;

int			ft_atoi(char *stringy);
long long	time_thingy(void);


#endif