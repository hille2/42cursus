/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:28:09 by sgath             #+#    #+#             */
/*   Updated: 2021/07/17 15:04:47 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_one_philo(t_all *all)
{
	size_t	i;

	i = -1;
	all->one = malloc(sizeof(t_one_philo) * all->num_of_philo);
	if (!all->one)
		error_exit(MEMORY, NULL, all);
	while (++i < all->num_of_philo)
	{
		all->one[i].num_one = i + 1;
		all->one[i].left_fork = i + 1;
		all->one[i].right_fork = (i + 1) % all->num_of_philo;
		all->one->last_time = 0;
		all->one[i].all = all;
	}
}

void	init_mutex(t_all *all)
{
	size_t	i;

	i = -1;
	all->forks = malloc(sizeof(pthread_mutex_t) * all->num_of_philo);
	all->thred = malloc(sizeof(pthread_t) * all->num_of_philo);
	if (!all->thred || !all->thred)
		error_exit(MEMORY, NULL, all);
	while (++i < all->num_of_philo)
		if (pthread_mutex_init(&(all->forks[i]), NULL))
			error_exit(MEMORY, NULL, all);
	if (pthread_mutex_init(&all->print, NULL))
		error_exit(MEMORY, NULL, all);
}

void	init_option(char **av, t_all *all)
{
	all->num_of_philo = super_atoi(av[1]);
	if (all->num_of_philo < 1 || all->num_of_philo == MAX_SIZE || all->num_of_philo > MAX_PHILO)
		error_exit(OPTIONS, "Num of philosophers should be from 1 to 250", all);
	all->time_to_die = super_atoi(av[2]);
	if (all->time_to_die == 0 || all->time_to_die > LIMIT_TIME)
		error_exit(OPTIONS, "Time to die should be from 0 to 1000", all);
	all->time_to_eat = super_atoi(av[3]);
	if (all->time_to_eat == 0 || all->time_to_eat > LIMIT_TIME)
		error_exit(OPTIONS, "Time to eat should be from 0 to 1000", all);
	all->time_to_sleep = super_atoi(av[4]);
	if (all->time_to_sleep == 0 || all->time_to_sleep > LIMIT_TIME)
		error_exit(OPTIONS, "Time to sleep should be from 0 to 1000", all);
	if (av[5])
		all->num_of_must_eat = super_atoi(av[5]);
	else
		all->num_of_must_eat = 0;
	if (all->num_of_must_eat == MAX_SIZE || all->num_of_must_eat > LIMIT_TIME)
		error_exit(OPTIONS,
			"Number of times each philo must eatshould be from 0 to 1000", all);
}

size_t	init_time(void)
{
	struct timeval	tp_start;

	gettimeofday(&tp_start, NULL);
	return (tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000);
}

void	init_all(char **av, t_all *all)
{
	all->time_start = init_time();
	init_option(av, all);
	init_mutex(all);
	init_one_philo(all);
}
