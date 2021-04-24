/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/17 21:03:25 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_c_length(t_struct *s_a, char c)
{
	if (s_a->flag == -1 || s_a->length < 0)
	{
		ft_putchar_fd(c, 1);
		ft_out_cycle(s_a->length, ' ');
	}
	else if (s_a->flag == 1 && s_a->length > 0)
	{
		ft_out_cycle(s_a->length, '0');
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_out_cycle(s_a->length, ' ');
		ft_putchar_fd(c, 1);
	}
}

int			ft_arg_c(t_struct *s_a, va_list ap)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	len = 1;
	if (s_a->length != 0)
	{
		arg_c_length(s_a, c);
		len = len + (s_a->length - 1);
	}
	else
		ft_putchar_fd(c, 1);
	return (len);
}
