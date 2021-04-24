/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_u_flag_negt(t_struct *s_a, size_t n, int len)
{
	if (s_a->pr <= s_a->length && s_a->dot == 1)
	{
		ft_out_cycle(s_a->pr - len + 1, '0');
		if (s_a->pr == 0 && s_a->dot == 1 && n == 0)
			ft_out_cycle(s_a->length + 1, ' ');
		else
		{
			ft_ll(n);
			(len < s_a->pr) ? ft_out_cycle(s_a->length - s_a->pr +
				1, ' ') : ft_out_cycle(s_a->length - len + 1, ' ');
		}
	}
	else
	{
		ft_ll(n);
		ft_out_cycle(s_a->length - len + 1, ' ');
	}
}

static void	arg_u_flag_zero(t_struct *s_a, size_t n, int len)
{
	if (s_a->pr < s_a->length && s_a->dot == 1)
	{
		if (s_a->pr == 0 && s_a->dot == 1 && n == 0)
			ft_out_cycle(s_a->length + 1, ' ');
		else
		{
			if (len < s_a->pr)
				ft_out_cycle(s_a->length - s_a->pr + 1, ' ');
			if (s_a->pr < 0)
				ft_out_cycle(s_a->length - len + 1, '0');
			else
				ft_out_cycle(s_a->length - len + 1, '0');
			ft_out_cycle(s_a->pr - len + 1, '0');
		}
	}
	else
		ft_out_cycle(s_a->length - len + 1, '0');
	(s_a->dot == 1 && s_a->pr == 0 && n == 0) ? (ft_putstr_fd("", 1)) :
		(ft_ll(n));
}

static void	arg_u_flag_else(t_struct *s_a, size_t n, int len)
{
	if (s_a->pr <= s_a->length && s_a->dot)
	{
		(len < s_a->pr) ? ft_out_cycle(s_a->length - s_a->pr + 1,
			' ') : ft_out_cycle(s_a->length - len + 1, ' ');
		ft_out_cycle(s_a->pr - len + 1, '0');
		(s_a->pr == 0 && n == 0) ? ft_putstr_fd("", 1) : ft_ll(n);
	}
	else
	{
		ft_out_cycle(s_a->length - len + 1, ' ');
		ft_ll(n);
	}
}

static void	additional_condition(t_struct *s_a, unsigned int n, int len)
{
	if (s_a->flag == -1)
		arg_u_flag_negt(s_a, n, len);
	else if (s_a->flag == 1)
		arg_u_flag_zero(s_a, n, len);
	else
		arg_u_flag_else(s_a, n, len);
}

int			ft_arg_u(t_struct *s_a, va_list ap)
{
	int				len;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	(s_a->dot == 1 && s_a->pr == 0 && n == 0) ? (len = 0) :
		(len = ft_numlen(n, 10));
	if (len < s_a->length && s_a->flag == 1 && s_a->pr < s_a->length &&
		s_a->dot && s_a->pr >= 0)
		s_a->flag = 0;
	if (s_a->pr > s_a->length)
	{
		s_a->flag = 1;
		s_a->length = s_a->pr;
	}
	if (s_a->length != 0 && s_a->length > len)
	{
		additional_condition(s_a, n, len);
		len = s_a->length;
	}
	else
		(s_a->dot == 1 && s_a->pr == 0 && n == 0) ? ft_putstr_fd("", 1)
			: ft_ll(n);
	return (len);
}
