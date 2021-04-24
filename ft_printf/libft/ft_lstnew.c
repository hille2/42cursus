/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:29:15 by sgath             #+#    #+#             */
/*   Updated: 2020/11/07 21:23:34 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *data;

	if (!(data = malloc(sizeof(t_list))))
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (data);
}
