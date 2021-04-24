/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:42:36 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 14:36:27 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"
#include <stdio.h>
#include <errno.h>

static void	check_argv_argc(int ac, char **av, t_all *all_struct)
{
	int		i;
	char	*str;

	i = 0;
	all_struct->screen = 0;
	if (ac == 1)
		error_incorrect("first argument ლ(ಠ_ಠ ლ)");
	if (ac > 3)
		error_incorrect("number of arguments ヽ(´ー` )┌");
	str = ft_strnstr(av[1], ".cub", ft_strlen(av[1]));
	(str == NULL) ? error_incorrect("first argument ლ(ಠ_ಠ ლ)")
		: (i = ft_strncmp(str, ".cub", 4));
	if (i != 0)
		error_incorrect("first argument ლ(ಠ_ಠ ლ)");
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) != 0)
			error_incorrect("second argument ヽ(ˇヘˇ)ノ");
		else
			all_struct->screen = 1;
	}
}

int			main(int ac, char **av)
{
	int			fd;
	int			i;
	char		*line;
	t_all		all_struct;

	check_argv_argc(ac, av, &all_struct);
	line = NULL;
	all_struct.head = NULL;
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror("I dont know, what the happing 	(｡•́︿•̀｡)\nbut i think");
	}
	while ((i = get_next_line(fd, &line)) > 0)
		ft_lstadd_back(&all_struct.head, ft_lstnew(line));
	(i == -1) ? error_incorrect("file") :
		ft_lstadd_back(&all_struct.head, ft_lstnew(line));
	make_map(&all_struct, ft_lstsize(all_struct.head));
	player_loc(&all_struct.obj.player);
	make_3d(&all_struct);
	events_hook(&all_struct.win_map, &all_struct);
	mlx_loop(all_struct.win_map.mlx_ptr);
	return (0);
}
