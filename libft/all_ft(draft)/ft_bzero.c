/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:43:13 by sgath             #+#    #+#             */
/*   Updated: 2020/10/29 12:14:48 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
		((char *)s)[i] = 0;
}

int	main()
{
	unsigned char src[15] = "1234567890";
	size_t len = 10;

	ft_bzero(src, len);
	printf("%s \n", src);
	printf("%s \n", bzero(src, len));
	return (0);
}
