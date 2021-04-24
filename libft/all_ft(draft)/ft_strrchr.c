/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 01:42:01 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 14:53:11 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int count;
	char *str;
	
	count = 0;
	str = (char *)s;
	i = -1;
	while(str[++i] != '\0')
	{
		if (str[i] == c)
			count = i;
	}
	if (count != 0)
		return (str + count);
	return (NULL);
}

int	main()
{
	char str[] = "1212121234";
	printf("%s \n", strrchr(str, '\0'));
	printf("%s \n", ft_strrchr(str, '\0'));

	return (0);
}
