/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_3d_pact_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:46:38 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 14:12:15 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	check_ang(double *ang)
{
	if (*ang < 0)
		*ang = *ang + M_PI * 2;
	if (*ang > M_PI * 2)
		*ang = *ang - M_PI * 2;
}

void	add_map(t_win *map, t_pars_obj *obj, int screen)
{
	map->coord[0] = 0;
	map->coord[1] = 0;
	map->mlx_ptr = mlx_init();
	if (screen == 0)
		map->mlx_win = mlx_new_window(map->mlx_ptr, obj->rslt[0],
		obj->rslt[1], "Cub3d");
	if ((map->img.img = mlx_new_image(map->mlx_ptr, obj->rslt[0],
		obj->rslt[1])) <= 0)
		error_incorrect("img");
	map->img.addr = mlx_get_data_addr(map->img.img, &(map->img.bits_per_pixel),
		&(map->img.line_length), &(map->img.endian));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	player_loc(t_plr *player)
{
	if (player->view == 'E')
		player->dir = 0;
	else if (player->view == 'N')
		player->dir = M_PI_2;
	else if (player->view == 'W')
		player->dir = M_PI;
	else
		player->dir = 3 * M_PI_2;
	player->start = player->dir + FOV / 2;
	check_ang(&player->start);
}
