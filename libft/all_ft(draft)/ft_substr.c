/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:33:14 by sgath             #+#    #+#             */
/*   Updated: 2020/11/03 02:17:48 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i == start && i < len)
			while (i >= start && i < len)
				str[j++] = s[i++];
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	main()
{
	char str[] = "qwertyuio";
	printf("my : %s", ft_substr(str, 3, 5));
	return (0);
}
