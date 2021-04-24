/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3dcard_pact_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:49:26 by sgath             #+#    #+#             */
/*   Updated: 2021/02/17 13:11:26 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static t_ray	ray_ray(double dir, double start, int x, int y)
{
	t_ray	ray;

	ray.dir = dir;
	ray.start = start;
	ray.step_x = x;
	ray.step_y = y;
	return (ray);
}

static t_ray	init_ray(t_plr player)
{
	t_ray	ray;

	if (player.start < M_PI_2)
		ray = ray_ray(player.dir, player.start, 1, -1);
	else if (player.start >= M_PI_2 && player.start < M_PI)
		ray = ray_ray(M_PI - player.dir, M_PI - player.start, -1, -1);
	else if (player.start >= M_PI && player.start < 3 * M_PI_2)
		ray = ray_ray(player.dir - M_PI, player.start - M_PI, -1, 1);
	else
		ray = ray_ray(2 * M_PI - player.dir, 2 * M_PI - player.start, 1, 1);
	return (ray);
}

double			find_len_y(t_ray *ray, char **map, double x_pos, double y_pos)
{
	double	len_y;
	double	rem_step;

	len_y = 0;
	ray->y_for_y = (ray->step_y == 1) ? ((int)y_pos + 1) : ((int)y_pos - ACC);
	ray->x_for_y = fabs(y_pos - ray->y_for_y) * ray->step_x /
		tan(ray->start) + x_pos;
	rem_step = ray->step_x / tan(ray->start);
	while (ray->x_for_y > 0 && ray->y_for_y > 0 && ray->y_for_y <
		ray->len_map && ray->x_for_y < ft_strlen(map[(int)ray->y_for_y]) &&
		map[(int)ray->y_for_y][(int)ray->x_for_y] != '1')
	{
		ray->x_for_y = ray->x_for_y + rem_step;
		ray->y_for_y = ray->y_for_y + ray->step_y;
	}
	if (ray->x_for_y >= 0 && ray->y_for_y >= 0 && (ray->y_for_y <
		ray->len_map) && ray->x_for_y < ft_strlen(map[(int)ray->y_for_y]))
		len_y = fabs(x_pos - ray->x_for_y) * cos(ray->dir) + fabs(y_pos -
			ray->y_for_y) * sin(ray->dir);
	return (fabs(len_y));
}

double			find_len_x(t_ray *ray, char **map, double x_pos, double y_pos)
{
	double	len_x;
	double	rem_step;

	len_x = 0;
	ray->x_for_x = (ray->step_x == 1) ? ((int)x_pos + 1) : (((int)x_pos) - ACC);
	ray->y_for_x = fabs(ray->x_for_x - x_pos) * tan(ray->start) *
		ray->step_y + y_pos;
	rem_step = tan(ray->start) * ray->step_y;
	while (ray->x_for_x > 0 && ray->y_for_x > 0 && ray->y_for_x <
		ray->len_map && ray->x_for_x < ft_strlen(map[(int)ray->y_for_x]) &&
		map[(int)ray->y_for_x][(int)ray->x_for_x] != '1')
	{
		ray->x_for_x = ray->x_for_x + ray->step_x;
		ray->y_for_x = ray->y_for_x + rem_step;
	}
	if (ray->x_for_x >= 0 && ray->y_for_x >= 0 && (ray->y_for_x <
		ray->len_map) && ray->x_for_x < ft_strlen(map[(int)ray->y_for_x]))
		len_x = fabs(x_pos - ray->x_for_x) * cos(ray->dir) +
			fabs(y_pos - ray->y_for_x) * sin(ray->dir);
	return (fabs(len_x));
}

double			one_ray(t_plr *player, char **map, t_ray *ray, int len_map)
{
	double	len_y;
	double	len_x;

	*ray = init_ray(*player);
	ray->len_map = len_map + 1;
	len_x = find_len_x(ray, map, player->x_pos, player->y_pos);
	len_y = find_len_y(ray, map, player->x_pos, player->y_pos);
	player->side = (len_x >= len_y) ? 'v' : 'h';
	if (len_x == 0)
	{
		ray->y = ray->x_for_y;
		ray->x = ray->y_for_y;
		return (len_y);
	}
	if (len_y == 0)
	{
		ray->y = ray->x_for_x;
		ray->x = ray->y_for_x;
		return (len_x);
	}
	player->side = (len_x >= len_y) ? 'h' : 'v';
	ray->y = (len_x >= len_y) ? ray->x_for_y : ray->x_for_x;
	ray->x = (len_x >= len_y) ? ray->y_for_y : ray->y_for_x;
	return ((len_x >= len_y) ? len_y : len_x);
}
