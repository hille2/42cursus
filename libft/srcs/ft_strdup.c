/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:46:57 by sgath             #+#    #+#             */
/*   Updated: 2020/11/03 13:39:39 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*src2;

	len = ft_strlen((char *)src);
	i = -1;
	if (!(src2 = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	while (++i < len)
		src2[i] = src[i];
	src2[len] = '\0';
	return (src2);
}
