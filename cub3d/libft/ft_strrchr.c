/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:44:23 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 14:56:36 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		count;
	char	*str;

	count = -1;
	str = (char *)s;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			count = i;
	}
	if (c == '\0')
		return (str + i);
	if (count >= 0)
		return (str + count);
	return (NULL);
}
