/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:28:09 by sgath             #+#    #+#             */
/*   Updated: 2021/07/14 15:17:21 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_one_philo(t_all *all)
{
	size_t	i;

	i = -1;
	all->one = malloc(sizeof(t_one_philo) * all->num_of_philo);
	if (!all->one)
		error_exit(MEMORY, NULL);
	while (++i <= all->num_of_philo)
	{
		all->one[i].num_one = i + 1;
		all->one[i].left_fork = i;
		all->one[i].right_fork = (i + 1) % all->num_of_philo;
		all->one->last_time = init_time();
		all->one[i].all = all;
	}
}

void	init_mutex(t_all *all)
{
	size_t	i;

	i = -1;
	while (++i < all->num_of_philo)
		if (pthread_mutex_init(&(all->forks[i]), NULL))
			error_exit(MEMORY, NULL);
	if (pthread_mutex_init(&all->print, NULL))
		error_exit(MEMORY, NULL);
	i = -1;
	while (++i < all->num_of_philo)
	{
		pthread_create(all->thred + i, NULL, thread_fun, (void *)&(all->one[i]));
		pthread_detach(*(all->thred + i));
		usleep(50);
	}
}

void	init_option(char **av, t_all *all)
{
	all->num_of_philo = super_atoi(av[1]);
	if (all->num_of_philo < 1 || all->num_of_philo)
		error_exit(OPTIONS, "Number of philosophers should be from 1 to 250");
	all->time_to_die = super_atoi(av[2]);
	if (all->time_to_die < 0 || all->time_to_die > 1000) //60?
		error_exit(OPTIONS, "Time to die should be from 0 to 1000");
	all->time_to_eat = super_atoi(av[3]);
	if (all->time_to_eat < 0 || all->time_to_eat > 1000)
		error_exit(OPTIONS, "Time to eat should be from 0 to 1000");
	all->time_to_sleep = super_atoi(av[4]);
	if (all->time_to_sleep < 0 || all->time_to_sleep > 1000)
		error_exit(OPTIONS, "Time to sleep should be from 0 to 1000");
	if (av[5])
		all->num_of_must_eat = super_atoi(av[5]);
	else
		all->num_of_must_eat = 0;
	if (all->num_of_must_eat < 0 || all->num_of_must_eat > 250)
		error_exit(OPTIONS,
			"Number of times each philo must eatshould be from 0 to 1000");
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
