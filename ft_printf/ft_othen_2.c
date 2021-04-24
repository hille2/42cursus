/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_othen2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/03 17:07:51 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ll(long long nb)
{
	if (nb < 0)
	{
		nb *= (-1);
		ft_putchar_fd('-', 1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, 1);
	ft_putchar_fd(nb % 10 + 48, 1);
}

void	ft_cycle_d(int loop, char smbl)
{
	while (loop-- > 0)
	{
		ft_putchar_fd(smbl, 1);
	}
}