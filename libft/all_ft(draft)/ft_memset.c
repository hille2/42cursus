/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:35:23 by sgath             #+#    #+#             */
/*   Updated: 2020/10/29 11:27:15 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;
	char *str;

	str = b;
	i = -1;
	while (++i < len)
		str[i] = c;
	return (str);
}

int	main ()
{
	unsigned char src[15] = "1234567890";
	int c = 48;
	size_t len = 10;
	printf("%s\n", memset(src, c, len));
	printf("%s\n", ft_memset(src, c, len));

   return 0;
}
