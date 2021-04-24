/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:31:45 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 22:30:41 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
