/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:31:45 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 22:31:39 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*str1 != *str2 && (*str1 != '\0' || *str2 != '\0'))
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1 == '\0' && *str2 == '\0')
			return (0);
		str1++;
		str2++;
	}
	return (0);
}

int	main()
{
	char str1[16] = "atoms\0\0\0\0";
	char str2[16] = "atoms\0abc";
	printf("ft : %d \nmy : %d", strncmp(str1, str2, 0), ft_strncmp(str1, str2, 0)); 

	return (0);
}
