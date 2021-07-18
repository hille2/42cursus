/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:51:03 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 18:08:34 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	super_atoi(const char *str)
{
	long	number;
	long	checknum;

	number = 0;
	if (*str == '-')
		error_exit(OPTIONS, "Сheck the spelling of the arguments!\n", NULL);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		checknum = number;
		number = number * 10 + (*str - '0');
		str++;
		if (checknum > number)
			error_exit(OPTIONS, "Сheck the spelling of the arguments!\n", NULL);
	}
	if (*str || number == 0)
		error_exit(OPTIONS, "Сheck the spelling of the arguments!\n", NULL);
	return (number);
}

long	what_time(long start)
{
	struct timeval	tp_start;
	long			now;

	gettimeofday(&tp_start, NULL);
	now = tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000;
	return (now - start);
}

void	clear_all(t_all *all)
{
	long	i;

	i = -1;
	if (!all)
		return ;
	if (all->forks)
	{
		while (++i < all->opt.p_count)
			pthread_mutex_destroy(&all->forks[i]);
		free(all->forks);
		free(all->one);
	}
	pthread_mutex_destroy(&all->print);
}

void	error_exit(int error, char *des_error, t_all *all)
{
	if (error == OPTIONS)
		printf("Error!\nWrong of options!\n%s\n", des_error);
	else if (error == MEMORY)
	{
		printf("Error!\nMemory allocation error!\n");
	}
	if (all)
		clear_all(all);
	exit (EXIT_FAILURE);
}

void	my_usleep(long timer, long t_start)
{
	long	stop;
	long	start;

	stop = what_time(t_start) + timer;
	start = what_time(t_start);
	while (start < stop)
	{
		usleep(50);
		start = what_time(t_start);
	}
}
