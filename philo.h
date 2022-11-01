/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:54:31 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/11/01 20:08:17 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

# define life_is_meaningless_and_we_all_gonna_die 1

# define RESET		"\033[0m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;34m"
# define PINK		"\033[0;35m"
# define SKY		"\033[0;36m"

# define ON_RED 	"\033[41m"
# define ON_PURPLE	"\033[44m"
# define ON_PINK	"\033[45m"



typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_philo_must_eat;
	int					code_blue;
	long long			start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		pulse_check;
	t_philo				*philo;	
}				t_data;

typedef struct s_philo
{
	pthread_t			thred;
	int					id;
	int					left_fork;
	int					right_fork;
	int					meals;
	long long			last_meal;
	t_data				*data;
}				t_philo;

/* initializing values */
void		set_the_table(t_data *data, int argc, char **argv);
/* time function */
long long	timer(void);
/* halp functions */
int			ft_atoi(char *stringy);
void		*ft_calloc(size_t count, size_t size);
int			code_blue(t_philo *philo);
/* thread manipulations */
void		invite_the_philosophers(t_data *data);
void		get_rid_of_the_bodies(t_data *data);
int			put_down_forks(t_philo *philo);

/* routine */
int			time_to_eat(t_philo	*philo);
int			time_to_sleep(t_philo *philo);
int			time_to_think(t_philo *philo);


#endif