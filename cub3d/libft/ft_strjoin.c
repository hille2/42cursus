/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:38:20 by sgath             #+#    #+#             */
/*   Updated: 2020/11/07 12:34:22 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = ft_calloc((len_s1 + len_s2 + 1), sizeof(char))))
		return (NULL);
	i = 0;
	while (i++ < len_s1)
		str[i - 1] = s1[i - 1];
	j = 0;
	while (j++ < len_s2)
		str[i + j - 2] = s2[j - 1];
	str[i + j - 2] = '\0';
	return (str);
}
