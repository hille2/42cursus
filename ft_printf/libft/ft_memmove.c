/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:01:15 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 13:38:29 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s2, const void *s1, size_t len)
{
	unsigned char	*s2_c;
	unsigned char	*s1_c;
	size_t			i;

	s2_c = ((unsigned char *)s2);
	s1_c = ((unsigned char *)s1);
	if (s1 < s2)
	{
		i = len + 1;
		while (--i > 0)
			s2_c[i - 1] = s1_c[i - 1];
	}
	else if (s1 > s2)
	{
		i = -1;
		while (++i < len)
			s2_c[i] = s1_c[i];
	}
	return (s2);
}
