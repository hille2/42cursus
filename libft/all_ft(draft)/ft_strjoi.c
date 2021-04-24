/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:18:08 by sgath             #+#    #+#             */
/*   Updated: 2020/11/03 02:37:23 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t len_s1;
	size_t len_s2;
	size_t i;
	size_t j;

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	str = (char *)malloc(sizeof(*str) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i++ < len_s1)
		str[i - 1] = s1[i - 1];
	j = 0;
	while (j++ <= len_s2)
		str[(i - 1) + j - 1] = s2[j - 1]; 
	return (str);
}I

int	main()
{
	char *s1 = "123456";
	char *s2 = "7890";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}
