/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:01:15 by sgath             #+#    #+#             */
/*   Updated: 2020/11/02 13:47:04 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *s2, const void *s1, size_t len)
{
	unsigned char	*s2_c;
	unsigned char	*s1_c;
	size_t			i;

	s2_c = ((unsigned char *)s2);
	s1_c = ((unsigned char *)s1);
	if((unsigned long *)s1 < (unsigned long *)(s2))
	{
		i = len + 1;
		while(--i > 0)
			s2_c[i-1] = s1_c[i-1];
	}
	else
	{
		i = -1;
		while(++i < len)
			s2_c[i] = s1_c[i];
	}
	return(s2);
}
int	main()
{
	char src[11] = "1234567890";
	printf("src old: %s \n", src);
	memmove(&src[3], &src[3], 0);
	printf("src new: %s \n", src);
	char rc[11] = "1234567890";
	ft_memmove(&rc[3], &rc[3], 0);
	printf("src my:  %s \n",rc);
	return (0);
}
