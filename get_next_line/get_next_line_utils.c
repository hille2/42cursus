/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:32:11 by sgath             #+#    #+#             */
/*   Updated: 2020/11/22 15:53:35 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (*str)
	{
		str++;
		n++;
	}
	return (n);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*src2;

	len = ft_strlen((char *)src);
	i = -1;
	if (!(src2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		src2[i] = src[i];
	src2[len] = '\0';
	return (src2);
}

char	*ft_substr(char *s, int start, int len)
{
	char		*s2;
	int			i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		free(s);
		if (!(s2 = malloc(sizeof(char))))
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
	{
		free(s);
		return (NULL);
	}
	i = -1;
	while (++i < len && s[start + i] != '\0')
		s2[i] = s[start + i];
	s2[i] = '\0';
	free(s);
	return (s2);
}
