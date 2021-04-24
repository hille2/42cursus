/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:22:37 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 14:56:21 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}
