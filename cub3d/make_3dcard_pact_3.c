/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3dcard_pact_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:01:34 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 14:37:15 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void			get_data_h(t_alt *height, t_pars_obj *obj, double len)
{
	if (len == 0)
		len = 1;
	height->h_wall = obj->rslt[1] / len * 1.5;
	height->h_wall_st = (obj->rslt[1] - height->h_wall) / 2;
}

static unsigned int	get_color(int heigth_wall, t_tex some_tex, int y, double x)
{
	char	*dst;
	int		tex_x;
	int		tex_y;

	tex_y = y * some_tex.height * 1.0 / heigth_wall;
	tex_x = x * some_tex.width;
	dst = some_tex.img_tex.addr + (tex_y * some_tex.img_tex.line_length + tex_x
	* (some_tex.img_tex.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static void			choice_color_for_hrz(t_all *all_struct, int i, int count)
{
	unsigned int	color;
	double			x_c;

	if (all_struct->obj.player.start < M_PI)
	{
		x_c = all_struct->ray.y - (int)all_struct->ray.y;
		color = get_color(all_struct->height.h_wall,
		all_struct->obj.so_tex, i - all_struct->height.h_wall_st, x_c);
		my_mlx_pixel_put(&all_struct->win_map.img, count, i, color);
	}
	else
	{
		x_c = (int)all_struct->ray.y + 1 - all_struct->ray.y;
		color = get_color(all_struct->height.h_wall,
		all_struct->obj.no_tex, i - all_struct->height.h_wall_st, x_c);
		my_mlx_pixel_put(&all_struct->win_map.img, count, i, color);
	}
}

static	void		choice_color_for_vrt(t_all *all_struct, int i, int count)
{
	unsigned int	color;
	double			x_c;

	if (all_struct->obj.player.start >= M_PI_2 &&
		all_struct->obj.player.start < 3 * M_PI_2)
	{
		x_c = (int)all_struct->ray.x + 1 - all_struct->ray.x;
		color = get_color(all_struct->height.h_wall,
		all_struct->obj.we_tex, i - all_struct->height.h_wall_st, x_c);
		my_mlx_pixel_put(&all_struct->win_map.img, count, i, color);
	}
	else
	{
		x_c = all_struct->ray.x - (int)all_struct->ray.x;
		color = get_color(all_struct->height.h_wall,
		all_struct->obj.ea_tex, i - all_struct->height.h_wall_st, x_c);
		my_mlx_pixel_put(&all_struct->win_map.img, count, i, color);
	}
}

void				draw_coll(t_all *all_struct, int count)
{
	int i;

	i = -1;
	get_data_h(&all_struct->height, &all_struct->obj, all_struct->ray.len);
	while (++i < all_struct->obj.rslt[1] / 2)
		my_mlx_pixel_put(&all_struct->win_map.img, count, i, all_struct->obj.
		ceil_col);
	i = all_struct->obj.rslt[1] / 2 - 1;
	while (++i < all_struct->obj.rslt[1])
		my_mlx_pixel_put(&all_struct->win_map.img, count, i, all_struct->obj.
		floor_col);
	i = all_struct->height.h_wall_st - 1;
	while (++i < (all_struct->height.h_wall + all_struct->height.h_wall_st))
	{
		if (i >= 0 && i < all_struct->obj.rslt[1])
		{
			if (all_struct->obj.player.side == 'h')
				choice_color_for_hrz(all_struct, i, count);
			else
				choice_color_for_vrt(all_struct, i, count);
		}
	}
}
