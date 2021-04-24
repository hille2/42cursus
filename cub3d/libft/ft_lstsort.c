/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:06:03 by sgath             #+#    #+#             */
/*   Updated: 2021/02/14 16:00:17 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **some_lst, int (*cmp)())
{
	t_list	*one;
	t_list	*two;
	void	*temp_data;

	one = *some_lst;
	while (one)
	{
		two = one->next;
		while (two)
		{
			if ((*cmp)(one->content, two->content) > 0)
			{
				temp_data = one->content;
				one->content = two->content;
				two->content = temp_data;
			}
			two = two->next;
		}
		one = one->next;
	}
}
