/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_pact_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:07:14 by sgath             #+#    #+#             */
/*   Updated: 2021/02/10 17:06:06 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	motion_y(t_plr *player, int fourth)
{
	player->x_pos = player->x_pos + fourth * (SPEED * cos(player->dir));
	player->y_pos = player->y_pos - fourth * (SPEED * sin(player->dir));
}

void	motion_x(t_plr *player, int fourth)
{
	player->x_pos = player->x_pos + (SPEED * cos(player->dir - 90 * fourth));
	player->y_pos = player->y_pos - (SPEED * sin(player->dir - 90 * fourth));
}

void	roll_sideway(t_plr *player, int direction)
{
	player->dir = player->dir + 0.1 * direction;
	if (player->dir < 0)
		player->dir = player->dir + 2 * M_PI;
	if (player->dir > 2 * M_PI)
		player->dir = player->dir - 2 * M_PI;
}
