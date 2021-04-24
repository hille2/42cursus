/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_othen2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/17 21:02:49 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_out_condition(t_struct *s_a, int len, int negt)
{
	if (negt == -1)
	{
		if ((len + 1) <= s_a->pr)
			ft_out_cycle(s_a->length - s_a->pr, ' ');
		else
			ft_out_cycle(s_a->length - len, ' ');
	}
	else
	{
		if (len <= s_a->pr)
			ft_out_cycle(s_a->length - s_a->pr + 1, ' ');
		else if (s_a->pr < 0 && s_a->flag == 1)
			ft_out_cycle(s_a->length - len + 1, '0');
		else
			ft_out_cycle(s_a->length - len + 1, ' ');
	}
}

void	ft_ll(size_t nb)
{
	if (nb > 9)
		ft_putnbr_fd(nb / 10, 1);
	ft_putchar_fd(nb % 10 + 48, 1);
}
