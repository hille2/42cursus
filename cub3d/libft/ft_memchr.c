/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:16:11 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 13:43:29 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_c;

	i = 0;
	s_c = (unsigned char *)s;
	while (i < n)
	{
		if (s_c[i] == (unsigned char)c)
			return (s_c + i);
		i++;
	}
	return (NULL);
}
