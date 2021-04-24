/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:41:30 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 14:24:42 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char *str;

	str = (char *)s;
	i = -1;
	while(str[++i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}

int	main()
{
	char str[11] = "0123456789";
	char s[11] = "0123456789";

	printf("str: %s \n", str);
	printf("ft: %s \n", strchr(str, '\0'));
	printf("my: %s \n", ft_strchr(s, '\0'));
	return (0);
}
