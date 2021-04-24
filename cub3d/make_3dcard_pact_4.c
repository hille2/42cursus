/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3dcard_pact_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:23:28 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 13:34:53 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static t_spr	*init_item(t_spr *item, t_pars_obj *obj)
{
	item->dir_spr = atan2(obj->player.y_pos - item->spr_y,
		item->spr_x - obj->player.x_pos);
	if (item->dir_spr < 0)
		item->dir_spr += 2 * M_PI;
	if (obj->player.dir - item->dir_spr > M_PI)
		item->dir_spr += 2 * M_PI;
	if (obj->player.dir - item->dir_spr < -M_PI)
		item->dir_spr -= 2 * M_PI;
	item->spr_dist = (sqrt(pow(item->spr_y - obj->player.y_pos, 2)
		+ pow(item->spr_x - obj->player.x_pos, 2))) * cos(obj->player.dir -
		item->dir_spr);
	if (item->spr_dist < 0.5)
		item->spr_dist = 0;
	item->size_sprite = ((obj->rslt[1] / item->spr_dist)) * 1.5;
	item->h_offset = (obj->player.dir - item->dir_spr) * 1.0 *
		obj->rslt[0] / FOV + obj->rslt[0] / 2 - item->size_sprite / 2;
	item->v_offset = obj->rslt[1] / 2 - item->size_sprite / 2;
	return (item);
}

void			fill_all_spr(t_list *lst, t_pars_obj *obj)
{
	while (lst)
	{
		lst->content = init_item(lst->content, obj);
		lst = lst->next;
	}
}
