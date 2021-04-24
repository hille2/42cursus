/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:48:26 by sgath             #+#    #+#             */
/*   Updated: 2020/11/08 13:00:45 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	word;
	int i;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i + 1] != c && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (word);
}

static int	ft_size_word(char const *str, char c)
{
	int	size;

	size = 0;
	while (*str && *str != c && (*(str - 1) == '\0' || str[0]))
	{
		size++;
		str++;
	}
	return (size);
}

static int	ft_first_c(char const *str, char c)
{
	int i;

	i = 0;
	while (*str && *str == c)
	{
		i++;
		str++;
	}
	return (i);
}

static void	ft_free(char **arr_sp)
{
	int i;

	i = -1;
	while (arr_sp[++i])
		free(arr_sp[i]);
	free(arr_sp);
}

char		**ft_split(char const *s, char c)
{
	char	**arr_sp;
	int		word;
	int		count;
	int		size;
	int		i;

	word = -1;
	i = 0;
	if (!s || !(arr_sp = ft_calloc(ft_count_words(s, c) + 1, sizeof(char*))))
		return (NULL);
	count = ft_count_words(s, c);
	while (*s && ++word < count)
	{
		i = ft_first_c(s, c);
		size = ft_size_word(s + i, c);
		arr_sp[word] = ft_substr(s, i, size);
		if (!arr_sp)
		{
			ft_free(arr_sp);
			return (NULL);
		}
		s = s + i + size;
	}
	return (arr_sp);
}
