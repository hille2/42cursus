/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/07/18 12:43:33 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_it_time_die(t_one_philo *one, size_t *glutton)
{
	if (one->count_eating >= one->all->count_eat)
		(*glutton)++;
	if (what_time(one->all->t_start) > one->time_die)
	{
		pthread_mutex_lock(one->print);
		printf("%zu\t %zu is dies\n", what_time(one->all->t_start), one->num);
		return (ITS_TRUE);
	}
	return (ITS_FALSE);
}

void	watcher(void *basic)
{
	t_all	*all;
	size_t	i;
	size_t	glutton;

	all = (t_all *)basic;
	while (42)
	{
		i = -1;
		glutton = 0;
		while (++i < all->p_count)
		{
			pthread_mutex_lock(&all->one[i].eat);
			if (is_it_time_die(&all->one[i], &glutton) == ITS_TRUE)
				return ;
			pthread_mutex_unlock(&all->one[i].eat);
		}
		if (glutton == all->p_count - 1)
		{
			pthread_mutex_lock(&all->print);
			return ;
		}
	}
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 5 && ac != 6)
		error_exit(OPTIONS, "Number of arguments must be 4 or 5", NULL);
	init_all(av, &all);
	life_cycle(&all);
	watcher(&all);
	clear_all(&all);
	return (EXIT_SUCCESS);
}
