/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:17:35 by sgath             #+#    #+#             */
/*   Updated: 2020/10/31 14:06:06 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>  

void	*ft_memcpy(void *b, const void *a, size_t n)
{
	unsigned char *a_c;
	unsigned char *b_c;
	size_t i;

	i = -1;
	a_c = ((unsigned char *)a);
	b_c = ((unsigned char *)b);
	if (a_c != b_c && n != 0)
	{
		while (++i < n)
			b_c[i] = a_c[i];
	}
	return (b);
}

int	main ()
{
	unsigned char src[10] = "";
	unsigned char rc[10] = "";
	unsigned char dst[10] = "";
	printf("%s \n", ft_memcpy(dst,rc, 6));
	printf("%s \n", memcpy(dst, src, 6));
	return (0);
}
