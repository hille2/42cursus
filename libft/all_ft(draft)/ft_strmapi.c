/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:49:14 by sgath             #+#    #+#             */
/*   Updated: 2020/11/03 04:21:31 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	str;
	int		i;

	i = -1;
	str = (char *)malloc(sizeof(*str) * (strlen(s) + 1));
	if (!s || !f || !str)
		return (NULL);
	while (s[++i] != '\0')
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}

char	ft_alf(unsigned int n, char a)
{
	n = 1;
	if (a >= 'a' && a <= 'z')
	   a = a - 32;	
	return (a);
}

int	main()
{
	char *s = "abcd";
	printf("%s", ft_strmapi(s, ft_alf));
   return (0);	   
}
