/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_be_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:41:51 by sgath             #+#    #+#             */
/*   Updated: 2021/01/21 17:31:03 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	free_arr(char **someone_arr)
{
	int i;

	i = -1;
	if (someone_arr)
	{
		while (someone_arr[++i])
			free(someone_arr[i]);
		free(someone_arr);
	}
}

void	free_str(char *someone_str)
{
	if (someone_str)
		free(someone_str);
}
