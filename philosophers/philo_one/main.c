/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/05/05 21:44:48 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	add_option(char **av, t_options_philo *philo)
{
	philo->number_of_philo = ft_atoi(av[1]);
	if (philo->number_of_philo < 2)
		return (EXIT_FAILURE);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (philo->time_to_die < 0 || philo->time_to_eat < 0 ||
		philo->time_to_sleep < 0)
		return (EXIT_FAILURE);
	if (av[5])
		philo->number_of_must_eat = ft_atoi(av[5]);
	else
		philo->number_of_must_eat = 0;
	return (EXIT_SUCCESS);
}

int	loop_do(t_options_philo *philo)
{
	return (0);
}

int	error_exit(void)
{
	printf("Error!\nWrong of options!\n");
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_options_philo	philo;
	int				rez;

	if (ac < 5 || ac < 6)
		return (error_exit());
	else
	{
		rez = add_option(av, &philo);
		if (rez == 1)
			return (error_exit());
		while (1)
		{
			rez = loop_do(&philo);
			if (rez == 1)
				return (EXIT_SUCCESS);
		}
	}
}
