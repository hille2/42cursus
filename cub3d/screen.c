/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:32:02 by sgath             #+#    #+#             */
/*   Updated: 2021/02/17 15:28:13 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void			init_screen_bmp(char *bfh, char *bih, int width, int height)
{
	int i;

	i = -1;
	while (++i < 14)
		bfh[i] = (unsigned int)0;
	i = -1;
	while (++i < 40)
		bih[i] = (unsigned int)0;
	bfh[0x00] = 0x42;
	bfh[0x01] = 0x4D;
	bfh[0x02] = width * height * 4 + 14 + 40;
	bfh[0x0A] = 54;
	bih[0x00] = 40;
	i = -1;
	while (++i < 4)
		bih[0x04 + i] = width >> i * 8;
	while (--i >= 0)
		bih[0x08 + i] = height >> i * 8;
	bih[0x0c] = 1;
	bih[0x0e] = 32;
}

static unsigned int	*get_color(t_data some_tex, int tex_y, int tex_x)
{
	char	*dst;

	dst = some_tex.addr + (tex_y * some_tex.line_length + tex_x
	* (some_tex.bits_per_pixel / 8));
	return ((unsigned int*)dst);
}

void				make_screen_bmp(t_all *all_str)
{
	int					i;
	int					j;
	int					fd;
	char				bfh[14];
	char				bih[40];

	init_screen_bmp(bfh, bih, all_str->obj.rslt[0], all_str->obj.rslt[1]);
	i = all_str->obj.rslt[1];
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT, 0777
		| O_TRUNC | O_APPEND)) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror("I dont know, what the happing 	(｡•́︿•̀｡)\nbut i think");
		error_incorrect("");
	}
	write(fd, &bfh, 14);
	write(fd, &bih, 40);
	while (--i >= 0)
	{
		j = -1;
		while (++j < all_str->obj.rslt[0])
			write(fd, (get_color(all_str->win_map.img, i, j)), 4);
	}
	close(fd);
	close_win(all_str->screen);
}
