/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:51:03 by sgath             #+#    #+#             */
/*   Updated: 2021/07/14 15:29:06 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	super_atoi(const char *str)
{
	size_t	number;
	size_t	checknum;

	number = 0;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		return (ERROR);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		checknum = number;
		number = number * 10 + (*str - '0');
		str++;
		if (checknum > number)
			return (ERROR);
	}
	return (number);
}

size_t	what_time_is_it(size_t start)
{
	struct timeval	tp_start;
	size_t			now;

	gettimeofday(&tp_start, NULL);
	now = tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000;
	return (now - start);
}

void	clear_all(t_all *all)
{
	
}

void	error_exit(int error, char *des_error, t_all *all)
{
	if (error == OPTIONS)
		printf("Error!\nWrong of options!\n%s\n", des_error);
	else if (error == MEMORY)
	{
		printf("Error!\nMemory allocation error!\n");
	}
	clear_all(all);
	exit (EXIT_FAILURE);
}