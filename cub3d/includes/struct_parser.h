/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:00:36 by sgath             #+#    #+#             */
/*   Updated: 2021/02/16 14:12:15 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSER_H
# define STRUCT_PARSER_H
# include "../libft/libft.h"
# include "cub3d.h"

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_plr
{
	char		view;
	char		side;
	double		x_pos;
	double		y_pos;
	double		dir;
	double		start;
}				t_plr;

typedef struct	s_tex
{
	t_data		img_tex;
	char		*path;
	int			height;
	int			width;
}				t_tex;

typedef struct	s_spr
{
	double		spr_x;
	double		spr_y;
	double		dir_spr;
	double		spr_dist;
	int			size_sprite;
	int			h_offset;
	int			v_offset;
}				t_spr;

typedef struct	s_pars_obj
{
	t_plr		player;
	t_tex		no_tex;
	t_tex		so_tex;
	t_tex		we_tex;
	t_tex		ea_tex;
	t_tex		sprite_tex;
	int			rslt[2];
	int			floor_col;
	int			ceil_col;
	int			start_map_y;
	int			end_map_y;
}				t_pars_obj;

typedef	struct	s_win
{
	int			coord[2];
	void		*mlx_ptr;
	void		*mlx_win;
	t_data		img;
}				t_win;

typedef struct	s_alt
{
	int			h_wall_st;
	int			h_wall;
}				t_alt;

typedef struct	s_ray
{
	double		start;
	double		dir;
	double		x;
	double		y;
	double		x_for_x;
	double		y_for_x;
	double		x_for_y;
	double		y_for_y;
	double		step_x;
	double		step_y;
	int			len_map;
	double		len;
	double		len_perp;
}				t_ray;

typedef struct	s_all
{
	t_ray		ray;
	t_win		win_map;
	t_pars_obj	obj;
	t_list		*head;
	t_list		*spr_s;
	t_alt		height;
	char		**map;
	char		**card;
	int			screen;
}				t_all;

#endif
