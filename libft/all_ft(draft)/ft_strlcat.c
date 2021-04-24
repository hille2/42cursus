/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:09:58 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 23:25:16 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t size;
	size_t i;

	size = 0;
	i = 0;
	while (dst[size] != '\0')
		size++;
	while (i++ < n && src[i - 1] != '\0')
	{
		dst[size + (i - 1)] = src[i - 1];
	}
	dst[size + i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i + size);
}

int	main()
{
	char s1[12] = "12345";
	char s2[12] = "9876543210";
	printf("ft : %lu \n", strlcat(s2, s1, 2));
	char s11[12] = "12345";
	printf("my : %zu \n", ft_strlcat(s2, s11, 2));
	return (0);
}
