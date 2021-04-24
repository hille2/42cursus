/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:51:37 by sgath             #+#    #+#             */
/*   Updated: 2020/10/30 21:16:35 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	unsigned char	*s_c;

	i = -1;
	s_c = (unsigned char *)s;
	while (n--)
	{
		if(s_c[++i] == c)
			return (s_c + i);
	}
	return (NULL);
}

int	main()
{
	unsigned char src[15] = "1234567890";
	printf("src old: %s \n",src);

	char *sym;
	sym = memchr(src, '4', 10);
	if (sym != NULL)
		sym[0] = '!';
	printf("src new: %s \n", src);

	unsigned char rc[15] = "1234567890";
	sym = ft_memchr(rc, '4', 10);
	if (sym != NULL)
		sym[0] = '!';
	printf("src my:  %s \n", rc); 
	return (0);
}
