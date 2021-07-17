/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/07/17 14:50:46 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	life_cycle(t_all *all)
{
	size_t		i;

	i = -1;
	while (++i < all->num_of_philo)
	{
		pthread_create(&all->thred[i], NULL, thread_one,
			&all->one[i]);
		pthread_detach(all->thred[i]);
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac != 5 && ac != 6)
		error_exit(OPTIONS, "Number of arguments must be 4 or 5", NULL);
	init_all(av, &all);
	life_cycle(&all);
	return (EXIT_SUCCESS);
}
