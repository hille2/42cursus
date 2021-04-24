/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_2dcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:59:00 by sgath             #+#    #+#             */
/*   Updated: 2021/02/14 12:23:27 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	dick_pick(t_win map, int color, int j, int i)
{
	int a;
	int b;

	a = 0;
	while (a++ < SCALE_MAP)
	{
		b = 0;
		while (b++ < SCALE_MAP)
			my_mlx_pixel_put(&(map.img), a + i * SCALE_MAP, b + j *
			SCALE_MAP, color);
	}
}

static void	cast_one_ray(t_pars_obj *obj, char **map, t_data *img)
{
	double	x;
	double	y;
	double	len;

	x = obj->player.x_pos;
	y = obj->player.y_pos;
	while (map[(int)(y / SCALE_MAP)][(int)
		(x / SCALE_MAP)] != '1')
	{
		x += cos(obj->player.dir);
		y += sin(obj->player.dir);
		my_mlx_pixel_put(img, (int)(x), (int)(y), 0);
	}
}

static void	cast_more_rays(t_all *all_struct)
{
	double	len_ray;
	double	move;
	int		count;

	count = -1;
	all_struct->obj.player.dir = all_struct->obj.player.start;
	move = 60 * M_PI / all_struct->obj.rslt[0] / 180;
	while (++count < all_struct->obj.rslt[0])
	{
		cast_one_ray(&all_struct->obj, all_struct->map,
			&all_struct->win_map.img);
		all_struct->obj.player.dir = all_struct->obj.player.dir + move;
	}
}

void		make_2d_map(t_all *all_struct)
{
	int i;
	int j;

	j = -1;
	while (all_struct->map[++j])
	{
		i = -1;
		while (all_struct->map[j][++i])
		{
			if (all_struct->map[j][i] == '1')
				dick_pick(all_struct->win_map, 0x00ffffff, j, i);
			else if (all_struct->map[j][i] == '2')
				dick_pick(all_struct->win_map, 0x00FF69B4, j, i);
			else if (all_struct->map[j][i] == '0')
				dick_pick(all_struct->win_map, 0x0032CD32, j, i);
			else if (all_struct->map[j][i] == all_struct->obj.player.view)
				dick_pick(all_struct->win_map, 0x00FF69B4, j, i);
			all_struct->win_map.coord[0] += SCALE_MAP;
		}
	}
	cast_more_rays(all_struct);
}
