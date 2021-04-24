/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:46:19 by sgath             #+#    #+#             */
/*   Updated: 2020/11/08 16:43:40 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *lstnxt;

	if (del != NULL)
	{
		while ((*lst) != NULL)
		{
			lstnxt = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = lstnxt;
		}
	}
}
