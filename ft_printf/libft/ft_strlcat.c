/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:24:19 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 23:13:55 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t size_d;
	size_t size_s;
	size_t i;

	i = 0;
	size_d = ft_strlen(dst);
	size_s = ft_strlen((char*)src);
	if (n <= size_d)
		return (n + size_s);
	while ((i < n - size_d - 1) && src[i] != '\0')
	{
		dst[size_d + i] = src[i];
		i++;
	}
	dst[i + size_d] = '\0';
	return (size_d + size_s);
}
