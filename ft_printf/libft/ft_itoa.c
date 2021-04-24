/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:30:57 by sgath             #+#    #+#             */
/*   Updated: 2020/11/08 14:23:08 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	int				len_symbol;
	int				negativ;
	char			*str;

	negativ = 1;
	len_symbol = ft_len_num(n);
	if (!(str = ft_calloc(len_symbol, sizeof(char))))
		return (NULL);
	len_symbol--;
	str[len_symbol] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		negativ = -1;
	}
	nb = n * negativ;
	while (nb / 10 != 0)
	{
		str[--len_symbol] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[len_symbol - 1] = nb % 10 + 48;
	return (str);
}
