/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:52:18 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 18:00:59 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

# define MAX_SIZE	140737488345912

enum e_error_code
{
	OPTIONS = 1,
	MEMORY = 2,
	ERROR = 0,
	LIMIT_TIME = 1000,
	MAX_PHILO = 250,
	ITS_TRUE = 0,
	ITS_FALSE = 1,
};

typedef struct s_all	t_all;

typedef struct s_option
{
	long			p_count;
	long			time_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			count_eat;
}					t_option;

typedef struct s_one_philo
{
	long			num;
	pthread_mutex_t	*smallest_fork;
	pthread_mutex_t	*largest_fork;

	long			time_die;
	long			count_eating;
	pthread_mutex_t	eat;
	pthread_mutex_t	*print;
	t_all			*all;
	t_option		*opt;
}					t_one_philo;

typedef struct s_all
{
	pthread_t		*thred;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;

	long			t_start;
	t_one_philo		*one;
	t_option		opt;
}					t_all;

long				super_atoi(const char *str);
void				error_exit(int error, char *des_error, t_all *all);
void				clear_all(t_all *all);
long				what_time(long start);
void				my_usleep(long t_start, long timer);

void				init_all(char **av, t_all *all);
long				init_time(void);
long				init_time(void);

void				life_cycle_of_philo(t_all *all);
#endif
