/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_pact_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:17:49 by sgath             #+#    #+#             */
/*   Updated: 2021/02/17 15:28:52 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int		close_win(int scr)
{
	(scr == 1) ? ft_putstr_fd("the screenshot is ready!\n", 1) :
		ft_putstr_fd("bye! See u later!\n", 1);
	ft_putstr_fd("^ↀᴥↀ^\n\n", 1);
	exit(0);
}

int		key_hook(int keycode, t_all *all_struct)
{
	if (keycode == 53)
		close_win(0);
	else if (keycode == 13)
		motion_y(&all_struct->obj.player, 1);
	else if (keycode == 0)
		motion_x(&all_struct->obj.player, -1);
	else if (keycode == 1)
		motion_y(&all_struct->obj.player, -1);
	else if (keycode == 2)
		motion_x(&all_struct->obj.player, 1);
	else if (keycode == 123)
		roll_sideway(&all_struct->obj.player, 1);
	else if (keycode == 124)
		roll_sideway(&all_struct->obj.player, -1);
	else
		return (1);
	make_3d(all_struct);
	return (0);
}

void	events_hook(t_win *map, t_all *all_struct)
{
	mlx_hook(map->mlx_win, 17, 0, close_win, map);
	mlx_key_hook(map->mlx_win, key_hook, all_struct);
}
