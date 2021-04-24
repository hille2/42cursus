/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_path_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:47:55 by sgath             #+#    #+#             */
/*   Updated: 2021/02/17 15:55:29 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	add_arr(int size, t_all *all_struct)
{
	t_list		*tmp;
	int			i;

	i = -1;
	all_struct->map = ft_calloc(size + 1, sizeof(char *));
	tmp = all_struct->head;
	while (tmp)
	{
		all_struct->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&tmp, &free);
}

static void	empty_obj(t_pars_obj *obj)
{
	int i;

	i = -1;
	obj->rslt[0] = -1;
	obj->rslt[1] = -1;
	obj->no_tex.path = NULL;
	obj->so_tex.path = NULL;
	obj->we_tex.path = NULL;
	obj->ea_tex.path = NULL;
	obj->sprite_tex.path = NULL;
	obj->floor_col = -1;
	obj->ceil_col = -1;
	obj->player.view = 0;
	obj->start_map_y = -1;
	obj->end_map_y = -1;
}

static int	choise_elem_struct(t_all *all_struct, char **str_arg, int j,
	t_pars_obj *obj)
{
	int	i;

	i = 0;
	if (j == 0)
		i = check_rslt(all_struct, obj, str_arg);
	else if (j == 1)
		i = check_tex(all_struct, &(obj->no_tex), str_arg);
	else if (j == 2)
		i = check_tex(all_struct, &(obj->so_tex), str_arg);
	else if (j == 3)
		i = check_tex(all_struct, &(obj->we_tex), str_arg);
	else if (j == 4)
		i = check_tex(all_struct, &(obj->ea_tex), str_arg);
	else if (j == 5)
		i = check_tex(all_struct, &(obj->sprite_tex), str_arg);
	else if (j == 6)
		i = check_color(&obj->floor_col, str_arg);
	else if (j == 7)
		i = check_color(&obj->ceil_col, str_arg);
	return (i);
}

static int	choise_obj(char **texture, t_all *all_struct, char *map_str)
{
	int		j;
	int		i;
	char	**str_arg;

	str_arg = NULL;
	j = -1;
	i = 0;
	str_arg = ft_split(map_str, ' ');
	if (!str_arg[0])
	{
		free_arr(str_arg);
		return (1);
	}
	while (texture[++j] && i == 0)
	{
		if (ft_strncmp(str_arg[0], texture[j], ft_strlen(texture[j]) + 1) == 0)
			i = choise_elem_struct(all_struct, str_arg, j, &all_struct->obj);
	}
	if (i == 0 && str_arg)
		(look_at_arg(map_str) == 1) ? error_incorrect("extra argument")
		: (i = -1);
	free_arr(str_arg);
	return (i);
}

void		make_map(t_all *all_struct, int size)
{
	int			i;
	int			count;
	int			rem;
	char		**texture;

	count = 1;
	rem = -1;
	i = -1;
	empty_obj(&all_struct->obj);
	add_arr(size, all_struct);
	texture = ft_split("R NO SO WE EA S F C", ' ');
	while (all_struct->map[++i])
	{
		if (ft_strlen(all_struct->map[i]) != 0 && count == 1)
			count = choise_obj(texture, all_struct, all_struct->map[i]);
		if (count == 1)
			all_struct->obj.start_map_y = i + 1;
	}
	free_arr(texture);
	check_full_struct_obj(&all_struct->obj);
	(all_struct->obj.start_map_y != -1) ? pars_map(all_struct, &all_struct->obj)
		: error_incorrect("map not found or");
}
