/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:17:01 by sgath             #+#    #+#             */
/*   Updated: 2020/10/30 22:12:18 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_c;
	unsigned char *s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while(n--)
	{
		if(*s1_c != *s2_c)
			return (*s1_c - *s2_c);
		s1_c++;
		s2_c++;
	}
	return (0);
}

int	main()
{
	unsigned char src[15] = "9134567890";
	unsigned char dst[15] = "1234567890";
	printf("ft:  %d \n", memcmp(dst, src, 5)); 
	printf("my:  %d \n", ft_memcmp(dst, src, 5)); 
	return (0);
}
