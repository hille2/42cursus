/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:17:35 by sgath             #+#    #+#             */
/*   Updated: 2020/10/31 14:27:15 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *b, const void *a, size_t n)
{
	const unsigned char	*a_c;
	unsigned char		*b_c;
	size_t				i;

	i = 0;
	a_c = a;
	b_c = b;
	if (a != b && n != 0)
		while (i++ < n)
			b_c[i - 1] = a_c[i - 1];
	return (b);
}
