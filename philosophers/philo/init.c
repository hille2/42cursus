/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:28:09 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 15:33:31 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_one_philo(t_all *all)
{
	size_t	i;

	i = -1;
	all->one = malloc(sizeof(t_one_philo) * all->p_count);
	if (!all->one)
		error_exit(MEMORY, NULL, all);
	while (++i < all->p_count)
	{
		all->one[i].num = i + 1;
		pthread_mutex_init(&all->one[i].eat, NULL);
		all->one[i].print = &all->print;
		if (i == all->p_count - 1)
		{
			all->one[i].largest_fork = &all->forks[i];
			all->one[i].smallest_fork = &all->forks[0];
		}
		else
		{
			all->one[i].smallest_fork = &all->forks[i];
			all->one[i].largest_fork = &all->forks[i + 1];
		}
		all->one[i].time_die = all->time_die;
		all->one[i].all = all;
		all->one[i].count_eating = 0;
	}
}

void	init_mutex(t_all *all)
{
	size_t	i;

	i = -1;
	all->forks = malloc(sizeof(pthread_mutex_t) * all->p_count);
	if (!all->forks)
		error_exit(MEMORY, NULL, all);
	while (++i < all->p_count)
		if (pthread_mutex_init(&(all->forks[i]), NULL))
			error_exit(MEMORY, NULL, all);
	if (pthread_mutex_init(&all->print, NULL))
		error_exit(MEMORY, NULL, all);
}

void	init_option(char **av, t_all *all)
{
	all->p_count = super_atoi(av[1]);
	if (all->p_count == 0 || all->p_count == MAX_SIZE
		|| all->p_count > MAX_PHILO)
		error_exit(OPTIONS, "Num of philo should be from 1 to 250", NULL);
	all->time_die = super_atoi(av[2]);
	if (all->time_die == 0 || all->time_die > LIMIT_TIME)
		error_exit(OPTIONS, "Time to die should be from 0 to 1000", NULL);
	all->time_to_eat = super_atoi(av[3]);
	if (all->time_to_eat == 0 || all->time_to_eat > LIMIT_TIME)
		error_exit(OPTIONS, "Time to eat should be from 0 to 1000", NULL);
	all->time_to_sleep = super_atoi(av[4]);
	if (all->time_to_sleep == 0 || all->time_to_sleep > LIMIT_TIME)
		error_exit(OPTIONS, "Time to sleep should be from 0 to 1000", NULL);
	if (av[5])
	{
		all->count_eat = super_atoi(av[5]);
		if (all->count_eat == MAX_SIZE || all->count_eat > LIMIT_TIME
			|| all->count_eat == 0)
			error_exit(OPTIONS, "Numb of times each philo", NULL);
	}
	else
		all->count_eat = 0;
}

size_t	init_time(void)
{
	struct timeval	tp_start;

	gettimeofday(&tp_start, NULL);
	return (tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000);
}

void	init_all(char **av, t_all *all)
{
	all->t_start = init_time();
	init_option(av, all);
	init_mutex(all);
	init_one_philo(all);
}
