/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:51:16 by sgath             #+#    #+#             */
/*   Updated: 2020/11/06 16:58:07 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int main ()
{
	char s[] = "1234567890";
//  char c = ' ';
	char *str;
//  arr_sp = ft_split(s, c);
//  while (*arr_sp)
//	printf("%s \n", *arr_sp++);
//  printf("%d\n", ft_count_words(s, c));
	
	printf("%s \n",ft_substr(s, 11, 2)); 
	printf("%s \n",ft_substr(s, 5, 4)); 
	printf("%s \n",ft_substr(s, 9, 4)); 
	printf("%s \n",ft_substr(s, 9, 0)); 
	printf("%s \n",ft_substr("", 9, 3));
  return (0);
}
