/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_x_flag_negt(t_struct *s_a, int len, char *x_arg)
{
	int n;

	n = -1;
	if (s_a->type == 'X')
		while (x_arg[++n])
			x_arg[n] = ft_toupper(x_arg[n]);
	if (s_a->dot == 1)
	{
		ft_out_cycle(s_a->pr - len + 1, '0');
		(s_a->pr == 0 && ft_strncmp("0", x_arg, 1) == 0) ? ft_putstr_fd(" ", 1)
			: ft_putstr_fd(x_arg, 1);
		if (len < s_a->pr)
			ft_out_cycle(s_a->length - s_a->pr + 1, ' ');
		else
			ft_out_cycle(s_a->length - len + 1, ' ');
	}
	else
	{
		ft_putstr_fd(x_arg, 1);
		ft_out_cycle(s_a->length - len + 1, ' ');
	}
}

static void	arg_x_flag_zero(t_struct *s_a, int len, char *x_arg)
{
	int n;

	n = -1;
	if (s_a->type == 'X')
		while (x_arg[++n])
			x_arg[n] = ft_toupper(x_arg[n]);
	if (s_a->dot == 1)
	{
		if (len < s_a->pr)
			ft_out_cycle(s_a->length - s_a->pr + 1, ' ');
		else
			(s_a->pr < 0) ? (ft_out_cycle(s_a->length - len + 1, '0')) :
				(ft_out_cycle(s_a->length - len + 1, ' '));
		ft_out_cycle(s_a->pr - len + 1, '0');
	}
	else
		ft_out_cycle(s_a->length - len + 1, '0');
	(s_a->dot == 1 && s_a->pr == 0 && ft_strncmp(x_arg, "0", 1) == 0) ?
		ft_putstr_fd(" ", 1) : ft_putstr_fd(x_arg, 1);
}

static void	arg_x_flag_else(t_struct *s_a, int len, char *x_arg)
{
	int n;

	n = -1;
	if (s_a->type == 'X')
		while (x_arg[++n])
			x_arg[n] = ft_toupper(x_arg[n]);
	if (s_a->dot == 1 && s_a->pr != 0)
	{
		(len < s_a->pr) ? ft_out_cycle(s_a->length - s_a->pr + 1, ' ') :
			ft_out_cycle(s_a->length - len + 1, ' ');
		ft_out_cycle(s_a->pr - len + 1, '0');
	}
	else
		ft_out_cycle(s_a->length - len + 1, ' ');
	(s_a->dot == 1 && s_a->pr == 0 && ft_strncmp(x_arg, "0", 1) == 0) ?
		ft_putstr_fd(" ", 1) :
		ft_putstr_fd(x_arg, 1);
}

static void	additional_condition(int *len, t_struct *s_a, char *x_arg)
{
	int n;

	n = -1;
	if (s_a->length != 0 && s_a->length >= *len)
	{
		if (s_a->flag == -1)
			arg_x_flag_negt(s_a, *len, x_arg);
		else if (s_a->flag == 1)
			arg_x_flag_zero(s_a, *len, x_arg);
		else
			arg_x_flag_else(s_a, *len, x_arg);
		*len = *len + s_a->length - *len;
	}
	else
	{
		if (s_a->type == 'X')
			while (x_arg[++n])
				x_arg[n] = ft_toupper(x_arg[n]);
		(s_a->dot == 1 && s_a->pr == 0 && ft_strncmp(x_arg, "0", 1) == 0) ?
			ft_putstr_fd("", 1) : ft_putstr_fd(x_arg, 1);
	}
}

int			ft_arg_x(t_struct *s_a, va_list ap)
{
	unsigned int	n;
	int				len;
	char			*x_arg;

	n = va_arg(ap, unsigned int);
	x_arg = ft_16stm(n, 16);
	len = (s_a->dot == 1 && s_a->pr == 0 && ft_strncmp(x_arg, "0", 1) == 0
		&& s_a->length == 0) ? 0 : ft_strlen(x_arg);
	if (s_a->pr > len && s_a->pr > s_a->length)
	{
		s_a->flag = 1;
		s_a->length = s_a->pr;
	}
	additional_condition(&len, s_a, x_arg);
	free(x_arg);
	return (len);
}
