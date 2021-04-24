/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_path_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:35:00 by sgath             #+#    #+#             */
/*   Updated: 2021/02/17 13:15:13 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void		new_resol(t_pars_obj *obj, t_win *map, int screen)
{
	int	sizex;
	int	sizey;

	sizex = 15360;
	sizey = 8640;
	if (screen == 0)
		mlx_get_screen_size(map->mlx_ptr, &sizex, &sizey);
	if (obj->rslt[0] > sizex)
		obj->rslt[0] = sizex;
	if (obj->rslt[1] > sizey)
		obj->rslt[1] = sizey;
}

int				check_rslt(t_all *all_struct, t_pars_obj *obj, char **str_arg)
{
	int	count;
	int	i;

	count = 1;
	i = -1;
	if (obj->rslt[0] != -1 || obj->rslt[1] != -1 || !(str_arg[1])
		|| !(str_arg[2]) || str_arg[3])
		error_incorrect("resolution");
	while (str_arg[1][++i] && count == 1)
		count = ft_isdigit(str_arg[1][i]);
	i = -1;
	while (str_arg[2][++i] && count == 1)
		count = ft_isdigit(str_arg[2][i]);
	if (count == 1)
	{
		obj->rslt[0] = ft_atoi(str_arg[1]);
		obj->rslt[1] = ft_atoi(str_arg[2]);
		new_resol(&all_struct->obj, &all_struct->win_map, all_struct->screen);
		if (all_struct->obj.rslt[0] * 1.0 / all_struct->obj.rslt[1] * 1.0 < 0.7)
			error_incorrect("resolution map");
	}
	if (count == 0 || obj->rslt[0] < 50 || obj->rslt[1] < 50)
		error_incorrect("resolution");
	add_map(&all_struct->win_map, &all_struct->obj, all_struct->screen);
	return (1);
}

int				check_color(int *color, char **str_arg)
{
	int		count;
	int		i;
	int		j;
	char	**arg;

	count = 1;
	j = -1;
	if (!(str_arg[1]) || (str_arg[2]))
		error_incorrect("color");
	arg = ft_split(str_arg[1], ',');
	if (!arg[0] || !arg[1] || !arg[2] || arg[3])
		return (-2);
	while (arg[++j] && (i = -1))
		while (arg[j][++i] && count == 1)
			count = ft_isdigit(arg[j][i]);
	if (count == 0 || ft_atoi(arg[0]) > 255 || ft_atoi(arg[1]) > 255 ||
		ft_atoi(arg[2]) > 255 || ft_atoi(arg[0]) < 0 || ft_atoi(arg[1]) < 0 ||
		ft_atoi(arg[2]) < 0)
		error_incorrect("color");
	if (count == 1)
		*color = ((ft_atoi(arg[0]) << 16) + (ft_atoi(arg[1]) << 8) +
			(ft_atoi(arg[2])));
	free_arr(arg);
	return (1);
}

int				check_tex(t_all *all_struct, t_tex *some_tex, char **str_arg)
{
	if (some_tex->path != NULL || !(str_arg[1]) || str_arg[2])
		error_incorrect("texture");
	some_tex->path = ft_strdup(str_arg[1]);
	some_tex->img_tex.img = mlx_xpm_file_to_image(all_struct->win_map.mlx_ptr,
		some_tex->path, &(some_tex->width), &(some_tex->height));
	if (!some_tex->img_tex.img)
		error_incorrect("texture");
	some_tex->img_tex.addr = mlx_get_data_addr(some_tex->img_tex.img,
	&(some_tex->img_tex.bits_per_pixel), &(some_tex->img_tex.line_length),
		&(some_tex->img_tex.endian));
	return (1);
}

int				look_at_arg(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i] && count == 0)
	{
		if (str[i] != '1' && str[i] != ' ')
			count = 1;
	}
	return (count);
}
