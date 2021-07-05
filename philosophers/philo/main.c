/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/07/05 19:34:11 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_mutex(t_all_philo *all)
{
	int	i;

	i = -1;
	while (++i < all->philo.number_of_philo)
		if (pthread_mutex_init(&all->forks[i], NULL))
			error_exit(MEMORY);
	if (pthread_mutex_init(&all->print, NULL))
		error_exit(MEMORY);
}

void	add_option(char **av, t_all_philo *all)
{
	all->philo.number_of_philo = super_atoi(av[1]);
	if (all->philo.number_of_philo < 1)
		error_exit(OPTIONS);
	all->philo.time_to_die = super_atoi(av[2]);
	if (all->philo.time_to_die < 0 || all->philo.time_to_die > 1000)
		error_exit(OPTIONS);
	all->philo.time_to_eat = super_atoi(av[3]);
	if (all->philo.time_to_eat < 0 || all->philo.time_to_eat > 1000)
		error_exit(OPTIONS);
	all->philo.time_to_sleep = super_atoi(av[4]);
	if (all->philo.time_to_die < 0 || all->philo.time_to_sleep > 1000)
		error_exit(OPTIONS);
	if (av[5])
		all->philo.number_of_must_eat = super_atoi(av[5]);
	else
		all->philo.number_of_must_eat = 0;
	if (all->philo.number_of_must_eat < 0 || all->philo.number_of_must_eat > 250)
		error_exit(OPTIONS);
	add_mutex(all);
}

void	error_exit(int error)
{
	if (error == OPTIONS)
		printf("Error!\nWrong of options!\n");
	else if (error_exit == MEMORY)
		printf("Error!\nMemory allocation error!\n");
	exit (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_all_philo		all;

	if (ac != 5 && ac != 6)
		error_exit(OPTIONS);
	add_option(av,&all);
	
	return (EXIT_SUCCESS);
}
