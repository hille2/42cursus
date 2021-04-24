/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_p_length(t_struct *s_a, char *pointer, int len)
{
	if (s_a->flag == -1)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(pointer, 1);
		ft_out_cycle(s_a->length - len + 1, ' ');
	}
	else if (s_a->flag == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_out_cycle(s_a->length - len + 1, '0');
		ft_putstr_fd(pointer, 1);
	}
	else
	{
		ft_out_cycle(s_a->length - len + 1, ' ');
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(pointer, 1);
	}
}

int			ft_arg_p(t_struct *s_a, va_list ap)
{
	size_t	n;
	int		len;
	char	*pointer;

	n = va_arg(ap, size_t);
	pointer = ft_16stm(n, 16);
	len = ft_strlen(pointer) + 2;
	if (s_a->length != 0 && s_a->length > 0 && s_a->length > len)
	{
		arg_p_length(s_a, pointer, len);
		len = len + s_a->length - len;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(pointer, 1);
	}
	free(pointer);
	return (len);
}
