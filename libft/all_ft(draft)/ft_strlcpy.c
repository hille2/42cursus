/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:34:36 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 22:42:29 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t i;
	size_t l;

	i = 0;
	l = 0;
	if (n == 0)
		return (ft_strlen(src));
	while(src[i] != '\0')
		i++;
	while (src && l < (n - 1))
	{
		dst[l] = src[l];
		++l;
	}
	dst[l] = '\0';
	return (i);
}

int	main()
{
	char s1[12] = "123456";
	char s2[12] = "9876543210";
	printf("ft : %lu \n", strlcpy(s2, s1, 0));
	printf("my : %zu \n", ft_strlcpy(s2, s1, 0));

}
