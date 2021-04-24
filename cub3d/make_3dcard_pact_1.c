/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3dcard_pact_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:26:37 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 14:36:27 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static unsigned int	get_color(int heigth_wall, t_tex some_tex, int y, int x)
{
	char	*dst;
	int		tex_x;
	int		tex_y;

	tex_y = y * some_tex.height * 1.0 / heigth_wall;
	tex_x = x * some_tex.width * 1.0 / heigth_wall;
	dst = some_tex.img_tex.addr + (tex_y * some_tex.img_tex.line_length + tex_x
	* (some_tex.img_tex.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int					cmp_tex(void *one, void *two)
{
	t_spr *one_tex;
	t_spr *two_tex;

	one_tex = one;
	two_tex = two;
	return ((one_tex->spr_dist < two_tex->spr_dist) ? 1 : 0);
}

static void			draw_sprite(t_list *spr_s, t_all *big_str,
					double *all_len_ray)
{
	t_spr			*item;
	int				i;
	int				j;
	unsigned int	clr;

	fill_all_spr(spr_s, &big_str->obj);
	ft_lstsort(&spr_s, cmp_tex);
	while (spr_s)
	{
		i = -1;
		item = spr_s->content;
		while (++i < item->size_sprite)
		{
			j = -1;
			if (item->h_offset + i >= 0 && item->h_offset + i < big_str->
			obj.rslt[0] && all_len_ray[i + item->h_offset] >= item->spr_dist)
				while (++j < item->size_sprite)
					if (item->v_offset + j >= 0 && item->v_offset + j <
					big_str->obj.rslt[1] && (clr = get_color(item->size_sprite,
					big_str->obj.sprite_tex, j, i)) != 0)
						my_mlx_pixel_put(&big_str->win_map.img, item->h_offset
						+ i, item->v_offset + j, clr);
		}
		spr_s = spr_s->next;
	}
}

void				make_3d(t_all *all_struct)
{
	double	move;
	double	all_len_ray[all_struct->obj.rslt[0]];
	int		count;

	count = -1;
	move = FOV / all_struct->obj.rslt[0];
	all_struct->obj.player.start = all_struct->obj.player.dir + FOV / 2;
	while (++count < all_struct->obj.rslt[0])
	{
		all_struct->ray.len = one_ray(&all_struct->obj.player, all_struct->map,
			&all_struct->ray, all_struct->obj.end_map_y -
			all_struct->obj.start_map_y);
		all_struct->obj.player.start = all_struct->obj.player.start - move;
		check_ang(&all_struct->obj.player.dir);
		check_ang(&all_struct->obj.player.start);
		draw_coll(all_struct, count);
		all_len_ray[count] = all_struct->ray.len;
	}
	draw_sprite(all_struct->spr_s, all_struct, all_len_ray);
	(all_struct->screen == 0) ? mlx_put_image_to_window(
		all_struct->win_map.mlx_ptr, all_struct->win_map.mlx_win,
		all_struct->win_map.img.img, 0, 0) : make_screen_bmp(all_struct);
}
