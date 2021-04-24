/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:26:34 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 22:48:27 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!src)
		return (-1);
	if (n == 0)
		return (ft_strlen((char*)src));
	while (src[i] != '\0')
		i++;
	while (dst && src[j] != '\0' && j < (n - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
