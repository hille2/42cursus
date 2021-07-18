/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:52:18 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 11:33:27 by sgath            ###   ########.fr       */
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

typedef struct s_one_philo
{
	size_t			num;
	pthread_mutex_t	*smallest_fork;
	pthread_mutex_t	*largest_fork;

	size_t			time_die;
	size_t			count_eating;
	pthread_mutex_t	eat;
	pthread_mutex_t	*print;
	t_all			*all;
}					t_one_philo;

typedef struct s_all
{
	size_t			p_count;
	size_t			time_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			count_eat;

	pthread_t		*thred;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;

	t_one_philo		*one;
	size_t			t_start;
}					t_all;

size_t				super_atoi(const char *str);
void				error_exit(int error, char *des_error, t_all *all);
void				clear_all(t_all *all);
size_t				what_time(size_t start);
void				my_usleep(size_t t_start, size_t timer);

void				init_all(char **av, t_all *all);
size_t				init_time(void);
size_t				init_time(void);

//void				*thread_one(void *one);
void				life_cycle(t_all *all);
#endif
