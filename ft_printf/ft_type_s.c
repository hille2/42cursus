/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_s_lenght(t_struct *s_a, int len, char *str)
{
	int i;

	i = -1;
	if (s_a->flag == -1)
	{
		while (++i < len)
			ft_putchar_fd(str[i], 1);
		ft_out_cycle(s_a->length - len + 1, ' ');
	}
	else if (s_a->flag == 1)
	{
		ft_out_cycle(s_a->length - len + 1, '0');
		while (++i < len)
			ft_putchar_fd(str[i], 1);
	}
	else
	{
		ft_out_cycle(s_a->length - len + 1, ' ');
		while (++i < len)
			ft_putchar_fd(str[i], 1);
	}
}

int			ft_arg_s(t_struct *s_a, va_list ap)
{
	int		len;
	int		i;
	char	*str;

	i = -1;
	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (s_a->dot == 1 && s_a->pr >= 0 && s_a->pr < len)
		len = s_a->pr;
	if (s_a->length != 0 && s_a->length > 0 && s_a->length > len)
	{
		arg_s_lenght(s_a, len, str);
		len = s_a->length;
	}
	else
	{
		while (++i < len)
			ft_putchar_fd(str[i], 1);
	}
	return (len);
}
