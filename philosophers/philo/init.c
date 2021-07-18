/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:28:09 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 18:06:27 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_one_philo(t_all *all, t_option *opt)
{
	long	i;

	i = -1;
	all->one = malloc(sizeof(t_one_philo) * opt->p_count);
	if (!all->one)
		error_exit(MEMORY, NULL, all);
	while (++i < opt->p_count)
	{
		all->one[i].num = i + 1;
		pthread_mutex_init(&all->one[i].eat, NULL);
		all->one[i].print = &all->print;
		if (i == opt->p_count - 1)
		{
			all->one[i].largest_fork = &all->forks[i];
			all->one[i].smallest_fork = &all->forks[0];
		}
		else
		{
			all->one[i].largest_fork = &all->forks[i + 1];
			all->one[i].smallest_fork = &all->forks[i];
		}
		all->one[i].time_die = opt->time_die;
		all->one[i].all = all;
		all->one[i].opt = opt;
	}
}

void	init_mutex(t_all *all)
{
	long	i;

	i = -1;
	all->forks = malloc(sizeof(pthread_mutex_t) * all->opt.p_count);
	if (!all->forks)
		error_exit(MEMORY, NULL, all);
	while (++i < all->opt.p_count)
		if (pthread_mutex_init(&(all->forks[i]), NULL))
			error_exit(MEMORY, NULL, all);
	if (pthread_mutex_init(&all->print, NULL))
		error_exit(MEMORY, NULL, all);
}

void	init_option(char **av, t_option *all)
{
	all->p_count = super_atoi(av[1]);
	if (all->p_count == MAX_SIZE
		|| all->p_count > MAX_PHILO)
		error_exit(OPTIONS, "Num of philo should be from 1 to 250", NULL);
	all->time_die = super_atoi(av[2]);
	if (all->time_die > LIMIT_TIME)
		error_exit(OPTIONS, "Time to die should be from 0 to 1000", NULL);
	all->time_to_eat = super_atoi(av[3]);
	if (all->time_to_eat > LIMIT_TIME)
		error_exit(OPTIONS, "Time to eat should be from 0 to 1000", NULL);
	all->time_to_sleep = super_atoi(av[4]);
	if (all->time_to_sleep > LIMIT_TIME)
		error_exit(OPTIONS, "Time to sleep should be from 0 to 1000", NULL);
	if (av[5])
	{
		all->count_eat = super_atoi(av[5]);
		if (all->count_eat > LIMIT_TIME)
			error_exit(OPTIONS, "Numb of times each philo", NULL);
	}
	else
		all->count_eat = 0;
}

long	init_time(void)
{
	struct timeval	tp_start;

	gettimeofday(&tp_start, NULL);
	return (tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000);
}

void	init_all(char **av, t_all *all)
{
	all->t_start = init_time();
	init_option(av, &(all->opt));
	init_mutex(all);
	init_one_philo(all, &(all->opt));
}
