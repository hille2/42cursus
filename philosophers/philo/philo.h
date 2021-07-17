/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:52:18 by sgath             #+#    #+#             */
/*   Updated: 2021/07/17 15:02:19 by yu               ###   ########.fr       */
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

#define MAX_SIZE 140737488345912

enum e_error_code
{
	OPTIONS = 1,
	MEMORY = 2,
	ERROR = 0,
	LIMIT_TIME = 1000,
	MAX_PHILO = 250,
};

typedef struct s_all	t_all;

typedef struct s_one_philo
{
	size_t			num_one;
	size_t			left_fork;
	size_t			right_fork;

	time_t			last_time;
	size_t			count_eating;
	t_all			*all;
}					t_one_philo;

typedef struct s_all
{
	size_t			num_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			num_of_must_eat;

	pthread_t		*thred;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;

	t_one_philo		*one;
	size_t			time_start;
}					t_all;

size_t				super_atoi(const char *str);
void				init_all(char **av, t_all *all);
void				error_exit(int error, char *des_error, t_all *all);
void				*thread_one(void *one);
size_t				init_time(void);
size_t				what_time_is_it(size_t start);
void				clear_all(t_all *all);
#endif
