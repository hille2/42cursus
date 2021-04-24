/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:00:06 by sgath             #+#    #+#             */
/*   Updated: 2020/11/08 18:18:36 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*str;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start > len_s || len_s == 0)
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (NULL);
	}
	else if (start + len > len_s)
	{
		if (!(str = ft_calloc((len_s - start + 1), sizeof(char))))
			return (NULL);
		ft_strlcpy(str, s + start, len_s - start + 1);
	}
	if (start + len <= len_s)
	{
		if (!(str = ft_calloc(len + 1, sizeof(char))))
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}
