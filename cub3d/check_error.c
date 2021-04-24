/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:30:43 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 13:49:39 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	check_full_struct_obj(t_pars_obj *obj)
{
	if (obj->rslt[0] <= 0 || obj->rslt[1] <= 0)
		error_incorrect("resolutoin");
	if (!obj->no_tex.path)
		error_incorrect("path to the north texture");
	if (!obj->so_tex.path)
		error_incorrect("path to the south texture");
	if (!obj->we_tex.path)
		error_incorrect("path to the west texture");
	if (!obj->ea_tex.path)
		error_incorrect("path to the east texture");
	if (!obj->sprite_tex.path)
		error_incorrect("path to the sprite texture");
	if (obj->floor_col == -1)
		error_incorrect("floor color");
	if (obj->ceil_col == -1)
		error_incorrect("ceilling color");
}

void	error_incorrect(char *str)
{
	if (ft_strncmp(str, "", 2) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Oh, no! The ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd(" is incorrect, please try again!\n", 2);
	exit(1);
}
