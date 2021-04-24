/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_path_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 02:52:42 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 14:12:34 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	check_valid_map(char **map, int y, int x, t_all *all_struct)
{
	t_spr	*sprite;

	if (!map[y - 1][x - 1] || !map[y - 1][x] || !map[y - 1][x + 1] ||
		map[y - 1][x - 1] == ' ' || map[y - 1][x] == ' ' || map[y - 1][x + 1]
		== ' ' || !map[y][x - 1] || !map[y][x + 1] || map[y][x - 1] == ' ' ||
		map[y][x + 1] == ' ' || !map[y + 1][x - 1] || !map[y + 1][x] ||
		!map[y + 1][x + 1] || map[y + 1][x - 1] == ' ' || map[y + 1][x] == ' '
		|| map[y + 1][x + 1] == ' ')
		error_incorrect("string contains void, this is map");
	else
	{
		if (map[y][x] == '2')
		{
			sprite = malloc(sizeof(t_spr));
			sprite->spr_x = x + 0.5;
			sprite->spr_y = y - all_struct->obj.start_map_y + 0.5;
			ft_lstadd_front(&all_struct->spr_s, ft_lstnew(sprite));
		}
		all_struct->obj.end_map_y = y + 1;
	}
}

static void	check_chr(t_pars_obj *obj, int i, int j, t_all *all_struct)
{
	if (all_struct->map[i][j] != '0' && all_struct->map[i][j] != '1' &&
		all_struct->map[i][j] != '2' && all_struct->map[i][j] != ' ')
	{
		if (all_struct->map[i][j] == 'N' || all_struct->map[i][j] == 'S' ||
			all_struct->map[i][j] == 'W' || all_struct->map[i][j] == 'E')
		{
			if (obj->player.view != 0)
				error_incorrect("number of players");
			else
			{
				obj->player.view = all_struct->map[i][j];
				obj->player.x_pos = j + 0.5;
				obj->player.y_pos = i + 0.5;
			}
		}
		else
			error_incorrect("map");
	}
	if (all_struct->map[i][j] == '0' || all_struct->map[i][j] == '2'
		|| all_struct->map[i][j] == obj->player.view)
		check_valid_map(all_struct->map, i, j, all_struct);
}

static char	**add_new_map(t_all *all_struct)
{
	int		i;
	int		start;
	int		end;
	char	**tmp;

	end = all_struct->obj.end_map_y;
	start = all_struct->obj.start_map_y;
	i = 0;
	tmp = ft_calloc(end - start + 2, sizeof(char *));
	while ((start + i) <= end)
	{
		tmp[i] = ft_strdup(all_struct->map[start + i]);
		i++;
	}
	free_arr(all_struct->map);
	all_struct->obj.player.y_pos -= start;
	return (tmp);
}

void		pars_map(t_all *all_struct, t_pars_obj *obj)
{
	int		j;
	int		i;

	all_struct->spr_s = NULL;
	i = obj->start_map_y;
	while (all_struct->map[i])
	{
		j = -1;
		if (ft_strncmp(all_struct->map[i], "", 2) == 0 &&
		all_struct->map[i + 1] != '\0')
			error_incorrect("map");
		while (all_struct->map[i][++j])
			check_chr(obj, i, j, all_struct);
		i++;
	}
	if (!obj->player.view)
		error_incorrect("player not found or");
	all_struct->map = add_new_map(all_struct);
}
