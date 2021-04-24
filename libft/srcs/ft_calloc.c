/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:03:03 by sgath             #+#    #+#             */
/*   Updated: 2020/11/03 00:45:09 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nbyte;
	void	*mal;

	nbyte = count * size;
	mal = malloc(nbyte);
	if (!mal)
		return (NULL);
	else
	{
		ft_bzero(mal, nbyte);
		return (mal);
	}
}
