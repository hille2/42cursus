/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/07/14 15:28:27 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life_cycle(t_all all)
{
	
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac != 5 && ac != 6)
		error_exit(OPTIONS, "Number of arguments must be 4 or 5");
	init_all(av, &all);
	life_cycle(all);
	return (EXIT_SUCCESS);
}

//printf("%su\t %d\t %s", time, num of philo, )