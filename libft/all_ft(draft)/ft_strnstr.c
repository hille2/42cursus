/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:18:32 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 23:45:57 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);

	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while ((haystack[i + j] == needle[j]) && (haystack[i + j + 1] 
					== needle[j + 1]))
			{
				j++;
			}
			if ((haystack[i + j] == needle[j]) && needle[j + 1] == '\0')
				return ((char *)haystack + (i));
		}
		i++;
	}
	return (0);
}

int	main()
{
	char s1[] = "MZIRIBMZIRIBMZE123";
	char s2[] = "MZIRIBMZE";
	printf("ft : %s \n", strnstr(s2, s1, 0));
	printf("my : %s \n", ft_strnstr(s2, s1, 0));
	return (0);
}
