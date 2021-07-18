/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 20:37:26 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_it_time_die(t_one_philo *one, long *glutton)
{
	if (one->count_eating >= one->opt->count_eat)
		(*glutton)++;
	pthread_mutex_lock(&one->eat);
	if (what_time(one->all->t_start) > one->time_die)
	{
		pthread_mutex_lock(one->print);
		printf("%zu\t %zu is dies\n", what_time(one->all->t_start), one->num);
		return (ITS_TRUE);
	}
	pthread_mutex_unlock(&one->eat);
	return (ITS_FALSE);
}

void	watcher(t_all *all, t_option opt)
{
	long	i;
	long	glutton;

	while (42)
	{
		i = -1;
		glutton = 0;
		while (++i < opt.p_count)
		{
			if (is_it_time_die(&all->one[i], &glutton) == ITS_TRUE)
				return ;
		}
		if (glutton == opt.p_count - 1 && opt.p_count != 1)
		{
			pthread_mutex_lock(&all->print);
			return ;
		}
	}
}

void	print_error(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		write(2, &(str[i]), 1);
	}
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 5 && ac != 6)
		error_exit(OPTIONS, "Number of arguments must be 4 or 5\n", NULL);
	init_all(av, &all);
	life_cycle_of_philo(&all);
	watcher(&all, all.opt);
	clear_all(&all);
	usleep(1000);
	return (EXIT_SUCCESS);
}
