/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:46:48 by sgath             #+#    #+#             */
/*   Updated: 2020/11/03 01:04:18 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*src2;

	len = 0;
	i = -1;
	while (src[len] != '\0')
		len++;
	src2 = (char *)malloc(sizeof(*src2) * (len + 1));
	
	while (++i < len)
		src2[i] = src[i];
	src2[len] = '\0';
	return (src2);
}

int	 main()
{
	char str[] = "123456sfsf";
	printf("ft : %s", strdup(str));
	printf("my : %s", ft_strdup(str));
	return (0);
}
