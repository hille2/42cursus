/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:51:32 by sgath             #+#    #+#             */
/*   Updated: 2021/07/07 11:29:15 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(int error, char *des_error)
{
	if (error == OPTIONS)
		printf("Error!\nWrong of options!\n%s\n", des_error);
	else if (error == MEMORY)
	{
		printf("Error!\nMemory allocation error!\n");
		//clear mutex?
	}
	exit (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac != 5 && ac != 6)
		error_exit(OPTIONS, "Number of arguments must be 4 or 5");
	init_all(av, &all);
	return (EXIT_SUCCESS);
}

//printf("%su\t %d\t %s", time, num of philo, )