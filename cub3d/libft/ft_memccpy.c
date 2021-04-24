/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:48:59 by sgath             #+#    #+#             */
/*   Updated: 2020/11/08 17:43:13 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *b, const void *a, int c, size_t n)
{
	const unsigned char	*a_c;
	unsigned char		*b_c;
	size_t				i;

	i = -1;
	a_c = (unsigned char *)a;
	b_c = (unsigned char *)b;
	while (++i < n)
	{
		b_c[i] = a_c[i];
		if (a_c[i] == (unsigned char)c)
		{
			b_c[i] = c;
			return (b + i + 1);
		}
	}
	return (NULL);
}
