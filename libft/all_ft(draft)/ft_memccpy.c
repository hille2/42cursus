/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:48:59 by sgath             #+#    #+#             */
/*   Updated: 2020/10/29 18:36:43 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h> 

void	*ft_memccpy(void *restrict b, const void *restrict a, int c, size_t n)
{
	unsigned char *a_c;
	unsigned char *b_c;

	a_c = ((unsigned char *)a);
	b_c = ((unsigned char *)b);
	while (n--)
	{
		if (*a_c == c)
			return (++b_c);
		*b_c++ = *a_c++;
	}
	return (NULL);
}

int	main()
{
	unsigned char src[15] = "125467522890";
	unsigned char dst[15] = "000000";
	printf("%s \n", memccpy(dst, src,'5', 4));
	unsigned char st[15] = "000000";
	printf("%s \n",	ft_memccpy(st, src,'5', 4));
	return (0);
}

