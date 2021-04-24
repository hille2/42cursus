/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:00:33 by sgath             #+#    #+#             */
/*   Updated: 2020/11/01 15:36:29 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	long long int i;
	long long int n;

	i = 1;
	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\t' ||
			*str == 'v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - 48);
		str++;
		if (n > 2147483647 || n < -2147483648)
			return (0);
		printf("%lld \n", n);
	}
	return (n * i);
}


int	main ()
{
	char n[40];
	//scanf("%c", &n);
	fgets(n, 100, stdin);
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("atoi: %d | my ft: %d", i1, i2);
	return (0);
}
