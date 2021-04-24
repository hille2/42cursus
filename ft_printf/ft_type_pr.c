/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_pr(t_struct *s_a)
{
	int len;

	len = 1;
	if (s_a->length != 0 && s_a->length > 0)
	{
		if (s_a->flag == -1)
		{
			ft_putchar_fd('%', 1);
			ft_out_cycle((len = s_a->length), ' ');
		}
		else if (s_a->flag == 1)
		{
			ft_out_cycle((len = s_a->length), '0');
			ft_putchar_fd('%', 1);
		}
		else
		{
			ft_out_cycle((len = s_a->length), ' ');
			ft_putchar_fd('%', 1);
		}
	}
	else
		ft_putchar_fd('%', 1);
	return (len);
}
