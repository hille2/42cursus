/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:50:21 by sgath             #+#    #+#             */
/*   Updated: 2021/02/17 15:28:28 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "struct_parser.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx_mms/mlx.h"
# include "../libft/libft.h"

# define ACC 0.00000001
# define SPEED 0.5
# define FOV (40 * M_PI / 180)

int			check_rslt(t_all *all_struct, t_pars_obj *obj,
			char **str_arg);
int			check_tex(t_all *all_struct, t_tex *some_tex, char **str_arg);
int			check_color(int *color, char **str_arg);
void		check_full_struct_obj(t_pars_obj *obj);
int			look_at_arg(char *str);
void		pars_map(t_all *all_struct, t_pars_obj *obj);

void		make_3d(t_all *all_struct);
void		player_loc(t_plr *player);
void		make_map(t_all *all_struct, int size);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		events_hook(t_win *map, t_all *all_struct);
void		add_map(t_win *map, t_pars_obj *obj, int screen);

double		find_len_y(t_ray *ray, char **map, double x_pos, double y_pos);
double		find_len_x(t_ray *ray, char **map, double x_pos, double y_pos);
double		one_ray(t_plr *player, char **map, t_ray *ray, int len_map);
void		motion_y(t_plr *player, int fourth);
void		motion_x(t_plr *player, int fourth);
void		roll_sideway(t_plr *player, int direction);
void		check_ang(double *ang);
void		draw_coll(t_all *all_struct, int count);
void		fill_all_spr(t_list *lst, t_pars_obj *obj);
void		make_screen_bmp(t_all *all_str);
int			close_win(int scr);

void		error_incorrect(char *str);
void		free_arr(char **someone_arr);
void		free_str(char *someone_str);

#endif
