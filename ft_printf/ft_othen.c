/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otfen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/17 21:02:38 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_out_cycle(int loop, char smbl)
{
	while (--loop > 0)
	{
		ft_putchar_fd(smbl, 1);
	}
}

void	ft_be_zero(t_struct *struct_arg)
{
	struct_arg->flag = 0;
	struct_arg->length = 0;
	struct_arg->dot = 0;
	struct_arg->pr = 0;
}

int		ft_choise_type(t_struct *s_a, va_list ap)
{
	if (s_a->type == 'c')
		return (ft_arg_c(s_a, ap));
	else if (s_a->type == 's')
		return (ft_arg_s(s_a, ap));
	else if (s_a->type == 'p')
		return (ft_arg_p(s_a, ap));
	else if (s_a->type == 'u')
		return (ft_arg_u(s_a, ap));
	else if (s_a->type == 'i' || s_a->type == 'd')
		return (ft_arg_d(s_a, ap));
	else if (s_a->type == 'x' || s_a->type == 'X')
		return (ft_arg_x(s_a, ap));
	else
		return (ft_arg_pr(s_a));
}

int		ft_numlen(long n, int stm)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > (stm - 1))
	{
		n = n / stm;
		len++;
	}
	len++;
	return (len);
}

char	*ft_16stm(unsigned long long n, int stm)
{
	int		len;
	char	*str;
	char	*stm16;

	len = ft_numlen(n, stm);
	stm16 = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (n > 15 && len > 0)
	{
		str[len--] = stm16[n % 16];
		n = n / 16;
	}
	str[0] = stm16[n % 16];
	return (str);
}
