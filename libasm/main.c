/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:26:57 by sgath             #+#    #+#             */
/*   Updated: 2021/04/24 14:48:00 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

int	main(int argv, char **argc)
{
	char str[110];
	char *str1;
	char *str2 = "hello world!";
	char *str3 = "hello world!";
	memset(str, '\0', 100);

	if (argv != 1 && strncmp(argc[1], "all", 4))
	{
		for (int i = 1; i < argv; i++)
		{
			if (!strncmp(argc[i], "strcmp", 7))
			{
				printf("----------\n");
				printf("FT_STRCMP\n");
				printf("original	function: %d\n", strcmp("\xff", "\xff"));
				printf("my		function: %d\n", ft_strcmp("\xff", "\xff"));
				printf("original	function: %d\n", strcmp("\xff\xff", "\xff"));
				printf("my		function: %d\n", ft_strcmp("\xff\xff", "\xff"));
				printf("original	function: %d\n", strcmp("hello", "world"));
				printf("my		function: %d\n", ft_strcmp("hello", "world"));
				printf("original	function: %d\n", strcmp("world", "hello"));
				printf("my		function: %d\n", ft_strcmp("world", "hello"));
				printf("original	function: %d\n", strcmp("", "123456"));
				printf("my		function: %d\n", ft_strcmp("", "123456"));
				printf("original	function: %d\n", strcmp("123456", ""));
				printf("my		function: %d\n", ft_strcmp("123456", ""));
			}
			else if (!strncmp(argc[i], "strcpy", 7))
			{
				printf("----------\n");
				printf("FT_STRCPY\n");
				printf("original	function: %s\n", strcpy(str, "hello world!"));
				printf("my		function: %s\n", ft_strcpy(str, "hello world!"));
				printf("original	function: %s\n", strcpy(str, "world!\0crap"));
				printf("my		function: %s\n", ft_strcpy(str, "world!\0crap"));
				printf("original	function: %s\n", strcpy(str, "The stpcpy() and strcpy() functions copy the string src to dst (including the terminating '0' character.)"));
				printf("my		function: %s\n", ft_strcpy(str, "The stpcpy() and strcpy() functions copy the string src to dst (including the terminating '0' character.)"));
			}
			else if (!strncmp(argc[i], "strdup", 7))
			{
				printf("----------\n");
				printf("FT_strdup\n");
				printf("original	function: %s\n",str1 = strdup("The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3)."));
				printf("my		function: %s\n",str1 = ft_strdup("The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3)."));
				printf("original	function: %s\n",str2 = strdup("assebler"));
				printf("my		function: %s\n",str2 = ft_strdup("assebler"));
				printf("original	function: %s\n",str3 = strdup(""));
				printf("my		function: %s\n",str3 = ft_strdup(""));
				
			}
			else if (!strncmp(argc[i], "strlen", 7))
			{
				printf("----------\n");
				printf("FT_STRLEN\n");
				printf("original	function: %zu\n", strlen("The strlen() function returns the number of characters that precede the terminating NUL character.  The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller."));
				printf("my		function: %zu\n", ft_strlen("The strlen() function returns the number of characters that precede the terminating NUL character.  The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller."));
				printf("original	function: %zu\n", strlen("strlen"));
				printf("my		function: %zu\n", ft_strlen("strlen"));
				printf("original	function: %zu\n", strlen(""));
				printf("my		function: %zu\n", ft_strlen(""));
				printf("----------\n");
			}
			else if (!strncmp(argc[i], "write", 6))
			{
				write(1, "----------\n", 12);
				write(1, "FT_WRITE\n", 10);
				write(1, "original	function: work!\n", 25);
				ft_write(1, "my		function: work!\n", 20);
				ft_write(1, "----------\n", 12);
			}
			else if (!strncmp(argc[i], "read", 5))
			{
				char c;
				size_t ret;
				write(1, "----------\n", 12);
				write(1, "FT_READ\n", 8);
				write(1, "if you need to stop testing: ctrl + C\n", 38);
				while (1)
				{
					if ((ret = ft_read(0, &c, 1)) < 0)
            			exit(-1);
					else
						write(1, &c, 1);
				}
			}
			else
			{
				printf("----------\n");
				printf("unknown function, please try again\n");
			}
		}
	}
	else
	{
		write(1, "----------\n", 12);
		write(1, "FT_WRITE\n", 10);
		write(1, "original	function: work!\n", 25);
		ft_write(1, "my		function: work!\n", 20);
		ft_write(1, "----------\n", 12);
		printf("FT_STRLEN\n");
		printf("original	function: %zu\n", strlen("The strlen() function returns the number of characters that precede the terminating NUL character.  The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller."));
		printf("my		function: %zu\n", ft_strlen("The strlen() function returns the number of characters that precede the terminating NUL character.  The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller."));
		printf("original	function: %zu\n", strlen("strlen"));
		printf("my		function: %zu\n", ft_strlen("strlen"));
		printf("original	function: %zu\n", strlen(""));
		printf("my		function: %zu\n", ft_strlen(""));
		printf("----------\n");
		printf("FT_STRCPY\n");
		printf("original	function: %s\n", strcpy(str, "hello world!"));
		printf("my		function: %s\n", ft_strcpy(str, "hello world!"));
		printf("original	function: %s\n", strcpy(str, "world!\0crap"));
		printf("my		function: %s\n", ft_strcpy(str, "world!\0crap"));
		printf("original	function: %s\n", strcpy(str, "The stpcpy() and strcpy() functions copy the string src to dst (including the terminating '0' character.)"));
		printf("my		function: %s\n", ft_strcpy(str, "The stpcpy() and strcpy() functions copy the string src to dst (including the terminating '0' character.)"));
		printf("----------\n");
		printf("FT_STRCMP\n");
		printf("original	function: %d\n", strcmp("123456", "123456"));
		printf("my		function: %d\n", ft_strcmp("123456", "123456"));
		printf("original	function: %d\n", strcmp("12345", "123456"));
		printf("my		function: %d\n", ft_strcmp("12345", "123456"));
		printf("original	function: %d\n", strcmp("123456", "12345"));
		printf("my		function: %d\n", ft_strcmp("123456", "12345"));
		printf("original	function: %d\n", strcmp("", "123456"));
		printf("my		function: %d\n", ft_strcmp("", "123456"));
		printf("original	function: %d\n", strcmp("123456", ""));
		printf("my		function: %d\n", ft_strcmp("123456", ""));
		printf("----------\n");
		printf("FT_strdup\n");
		printf("original	function: %s\n",str1 = strdup("The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3)."));
		printf("my		function: %s\n",str1 = ft_strdup("The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3)."));
		printf("original	function: %s\n",str2 = strdup("assebler"));
		printf("my		function: %s\n",str2 = ft_strdup("assebler"));
		printf("original	function: %s\n",str3 = strdup(""));
		printf("my		function: %s\n",str3 = ft_strdup(""));
		printf("----------\n");
	}
	return (0);
}
