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

int		ft_arg_c(t_struct *s_arg, va_list ap) // complit
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	len = 1;
	if (s_arg->length != 0)
	{
		if (s_arg->flag == -1 || s_arg->length < 0)
		{
			ft_putchar_fd(c, 1);
			ft_output_cycle(s_arg->length, ' ');
		}
		else if (s_arg->flag == 1 && s_arg->length > 0)
		{
			ft_output_cycle(s_arg->length, '0');
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_output_cycle(s_arg->length, ' ');
			ft_putchar_fd(c, 1);
		}
		len = len + (s_arg->length - 1);
	}
	else
		ft_putchar_fd(c, 1);
	return (len);
}

int		ft_arg_s(t_struct *s_arg, va_list ap) // complit
{
	int		len;
	int		i;
	char	*str;

	i = -1;
	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (s_arg->dot == 1 && s_arg->precision >= 0 && s_arg->precision < len)
		len = s_arg->precision;
	if (s_arg->length != 0 && s_arg->length > 0 && s_arg->length > len)
	{
		if (s_arg->flag == -1)
		{
			while (++i < len)
				ft_putchar_fd(str[i], 1);
			ft_output_cycle(s_arg->length - len + 1, ' ');
		}
		else if (s_arg->flag == 1)
		{
			ft_output_cycle(s_arg->length - len + 1, '0');
			while (++i < len)
				ft_putchar_fd(str[i], 1);
		}
		else
		{
			ft_output_cycle(s_arg->length - len + 1, ' ');
			while (++i < len)
				ft_putchar_fd(str[i], 1);
		}
		len = s_arg->length;
	}
	else
	{
		while (++i < len)
			ft_putchar_fd(str[i], 1);
	}
	return (len);
}

int		ft_arg_p(t_struct *s_arg, va_list ap) // complit
{
	size_t	n;
	int		len;
	char	*pointer;

	n = va_arg(ap, size_t);
	pointer = ft_16stm(n, 16);
	len = ft_strlen(pointer) + 1;
	if (s_arg->length != 0 && s_arg->length > 0 && s_arg->length > len)
	{
		if (s_arg->flag == -1)
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(pointer, 1);
			ft_output_cycle(s_arg->length - len, ' ');
		}
		else if (s_arg->flag == 1)
		{
			ft_putstr_fd("0x", 1);
			ft_output_cycle(s_arg->length - len, '0');
			ft_putstr_fd(pointer, 1);
		}
		else
		{
			ft_output_cycle(s_arg->length - len, ' ');
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(pointer, 1);	
		}	
		len = len + s_arg->length - len;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(pointer, 1);
	}
	return (len);
}
