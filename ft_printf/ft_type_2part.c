/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_1part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_arg_u(t_struct *s_arg, va_list ap) // complit
{
	int len;
	size_t n;

	n = va_arg(ap, size_t);
	len = ft_numlen(n, 10);
	if (s_arg->dot == 1 && s_arg->precision == 0)
	 	len = 0;
	if (s_arg->precision > s_arg->length)
	{
		s_arg->flag = 1;
		s_arg->length = s_arg->precision;
	}
	if (s_arg->length != 0 && s_arg->length > len)
	{
		if (s_arg->flag == -1)
		{
			if (s_arg->precision < s_arg->length && s_arg->dot == 1)
			{
				ft_output_cycle(s_arg->precision - len + 1, '0');
				(s_arg->precision != 0) ? ft_putnbr_ll(n) : ft_putstr_fd(" ", 1);
				(len < s_arg->precision) ? ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ') : 
					ft_output_cycle(s_arg->length - s_arg->precision, ' ');
				//ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ');
			}
			else
			{
				ft_putnbr_ll(n);
				ft_output_cycle(s_arg->length - len + 1, ' ');
			}	
		}
		else if (s_arg->flag == 1)
		{
			if (s_arg->precision < s_arg->length && s_arg->dot == 1)
			{
				(len < s_arg->precision) ? ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ') : 
					ft_output_cycle(s_arg->length - s_arg->precision, ' ');
				ft_output_cycle(s_arg->precision - len + 1, '0');
				(s_arg->precision != 0) ? ft_putnbr_ll(n) : ft_putstr_fd(" ", 1);
			}
			else
			{
				ft_output_cycle(s_arg->length - len + 1, '0');
				ft_putnbr_ll(n);
			}
		}
		else
		{
			if (s_arg->precision < s_arg->length && s_arg->dot)
			{
				(len < s_arg->precision) ? ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ') : 
					ft_output_cycle(s_arg->length - s_arg->precision, ' ');
				ft_output_cycle(s_arg->precision - len + 1, '0');
				(s_arg->precision != 0) ? ft_putnbr_ll(n) : ft_putstr_fd(" ", 1);
			}
			else
			{
				ft_output_cycle(s_arg->length - len + 1, ' ');
				ft_putnbr_ll(n);
			}
		}
		len = s_arg->length;
	}
	else
		(s_arg->dot == 1 && s_arg->precision == 0) ? ft_putstr_fd("", 1) : ft_putnbr_ll(n);
	return (len);
}

int	ft_arg_x(t_struct *s_arg, va_list ap) //complit
{
	size_t	n;
	int		len;
	char	*x_arg;

	n = va_arg(ap, size_t);
	x_arg = ft_16stm(n, 16);
	len = ft_strlen(x_arg);
	if (s_arg->dot == 1 && s_arg->precision == 0)
	 	len = 0;
	if (s_arg->precision > len && s_arg->precision > s_arg->length)
	{
		s_arg->flag = 1;
	 	s_arg->length = s_arg->precision;
	}
	n = -1;
	if (s_arg->length != 0 && s_arg->length > len)
	{
		if (s_arg->flag == -1)
		{
			if (s_arg->type == 'X')
				while (x_arg[++n])
					x_arg[n] = ft_toupper(x_arg[n]);
			if (s_arg->dot == 1)
			{
				ft_output_cycle(s_arg->precision - len + 1, '0');
				(s_arg->dot == 1 && s_arg->precision == 0) ? ft_putstr_fd(" ", 1) : ft_putstr_fd(x_arg, 1);
				(len < s_arg->precision) ? ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ') : 
					ft_output_cycle(s_arg->length - s_arg->precision, ' ');
			}
			else
			{
				ft_putstr_fd(x_arg, 1);
				ft_output_cycle(s_arg->length - len + 1, ' ');
			}
		}
		else if (s_arg->flag == 1)
		{
			if (s_arg->type == 'X')
				while (x_arg[++n])
					x_arg[n] = ft_toupper(x_arg[n]);
			
			if (s_arg->dot == 1)
			{
				(len < s_arg->precision) ? ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ') : 
					ft_output_cycle(s_arg->length - s_arg->precision, ' ');
				ft_output_cycle(s_arg->precision - len + 1, '0');
			}
			else
				ft_output_cycle(s_arg->length - len + 1, '0');
			(s_arg->dot == 1 && s_arg->precision == 0) ? ft_putstr_fd(" ", 1) : ft_putstr_fd(x_arg, 1);
		}
		else
		{
			if (s_arg->type == 'X')
				while (x_arg[++n])
					x_arg[n] = ft_toupper(x_arg[n]);
			if (s_arg->dot == 1)
			{
				(len < s_arg->precision) ? ft_output_cycle(s_arg->length - s_arg->precision + 1, ' ') : 
					ft_output_cycle(s_arg->length - s_arg->precision, ' ');
				ft_output_cycle(s_arg->precision - len + 1, '0');
			}
			else
				ft_output_cycle(s_arg->length - len + 1, ' ');
			(s_arg->dot == 1 && s_arg->precision == 0) ? ft_putstr_fd(" ", 1) : ft_putstr_fd(x_arg, 1);	
		}	
		len = len + s_arg->length - len;
	}
	else
	{
		if (s_arg->type == 'X')
			while (x_arg[++n])
				x_arg[n] = ft_toupper(x_arg[n]);
		(s_arg->dot == 1 && s_arg->precision == 0) ? ft_putstr_fd("", 1) : ft_putstr_fd(x_arg, 1);
	}
	return (len);
}

int	ft_arg_pr(t_struct *s_arg, va_list ap) //complit
{
	int len;

	len = 1;
	if (s_arg->length != 0 && s_arg->length > 0)
	{
		if (s_arg->flag == -1)
		{
			ft_putchar_fd('%', 1);
			ft_output_cycle((len = s_arg->length), ' ');
		}
		else if (s_arg->flag == 1)
		{
			ft_output_cycle((len = s_arg->length), '0');
			ft_putchar_fd('%', 1);
		}
		else
		{
			ft_output_cycle((len = s_arg->length), ' ');
			ft_putchar_fd('%', 1);
		}	
	}
	else 
		ft_putchar_fd('%', 1);	
	return (len);
}