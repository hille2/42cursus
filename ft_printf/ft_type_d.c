/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/17 21:04:18 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_d_flag_negt(t_struct *s_a, int len, int n, int negt)
{
	if (s_a->dot == 1 && s_a->pr != 0)
	{
		if (negt == -1)
		{
			ft_putchar_fd('-', 1);
			ft_out_cycle(s_a->pr - len + 1, '0');
			ft_ll(n);
		}
		else
		{
			ft_out_cycle(s_a->pr - len + 1, '0');
			(s_a->dot == 1 && s_a->pr == 0 && n == 0) ?
				(ft_putstr_fd("", 1)) : (ft_ll(n));
		}
		ft_out_condition(s_a, len, negt);
	}
	else
	{
		(negt == -1) ? ft_putchar_fd('-', 1) : ft_putstr_fd("", 1);
		(s_a->dot == 1 && s_a->pr == 0 && n == 0) ?
			(ft_putstr_fd("", 1)) : (ft_ll(n));
		(negt == -1) ? (ft_out_cycle(s_a->length - len, ' ')) :
			(ft_out_cycle(s_a->length - len + 1, ' '));
	}
	return (s_a->length);
}

static int	arg_d_flag_zero(t_struct *s_a, int len, int n, int negt)
{
	if (s_a->dot == 1)
	{
		if (negt == -1)
		{
			if (s_a->pr >= 0)
				ft_out_condition(s_a, len, negt);
			ft_putchar_fd('-', 1);
			(s_a->pr < 0) ? ft_out_cycle(s_a->length - len, '0') :
				ft_out_cycle(s_a->pr - len + 1, '0');
		}
		else
		{
			ft_out_condition(s_a, len, negt);
			ft_out_cycle(s_a->pr - len + 1, '0');
		}
	}
	else
	{
		(negt == -1) ? ft_putchar_fd('-', 1) : ft_putstr_fd("", 1);
		(negt == -1) ? (ft_out_cycle(s_a->length - len, '0')) :
			(ft_out_cycle(s_a->length - len + 1, '0'));
	}
	(s_a->dot == 1 && s_a->pr == 0 && n == 0) ? (ft_putstr_fd("", 1)) :
		(ft_ll(n));
	return (s_a->length);
}

static int	arg_d_else(t_struct *s_a, int len, int n, int negt)
{
	if (s_a->pr <= s_a->length && s_a->dot == 1)
	{
		if (negt == -1)
		{
			ft_out_condition(s_a, len, negt);
			ft_putchar_fd('-', 1);
			ft_out_cycle(s_a->pr - len + 1, '0');
		}
		else
		{
			ft_out_condition(s_a, len, negt);
			ft_out_cycle(s_a->pr - len + 1, '0');
		}
	}
	else
	{
		(negt == -1) ? (ft_out_cycle(s_a->length - len, ' ')) :
			(ft_out_cycle(s_a->length - len + 1, ' '));
		(negt == -1) ? ft_putchar_fd('-', 1) : ft_putstr_fd("", 1);
	}
	(s_a->dot == 1 && s_a->pr == 0 && n == 0) ? (ft_putstr_fd("", 1))
		: (ft_ll(n));
	return (s_a->length);
}

static void	additional_condition(int *len, t_struct *s_a, long n, int negt)
{
	if (s_a->flag == -1 && s_a->length != 0 && s_a->length > *len)
		*len = arg_d_flag_negt(s_a, *len, n, negt);
	else if (s_a->flag == 1 && s_a->length != 0 && s_a->length > *len)
		*len = arg_d_flag_zero(s_a, *len, n, negt);
	else if (s_a->flag == 0 && s_a->length != 0 && s_a->length > *len)
		*len = arg_d_else(s_a, *len, n, negt);
	else
	{
		(negt == -1 && (*len)++) ? ft_putchar_fd('-', 1) : ft_putstr_fd("", 1);
		(s_a->dot == 1 && s_a->pr == 0 && n == 0) ? (ft_putstr_fd("", 1))
			: (ft_ll(n));
	}
}

int			ft_arg_d(t_struct *s_a, va_list ap)
{
	int		len;
	int		negt;
	long	n;
	int		l;

	negt = 1;
	l = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		negt = -1;
		n = n * (-1);
	}
	len = ft_numlen(n, 10);
	if (s_a->dot == 1 && s_a->pr == 0 && n == 0)
		len = 0;
	if (s_a->pr > len && s_a->pr >= s_a->length)
	{
		l = 1;
		(s_a->flag == 0) ? s_a->flag = -1 : s_a->flag;
		s_a->length = s_a->pr;
	}
	additional_condition(&len, s_a, n, negt);
	(l == 1 && negt == -1) ? len++ : len;
	return (len);
}
