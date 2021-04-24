/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:25:14 by sgath             #+#    #+#             */
/*   Updated: 2020/11/22 15:56:39 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, int start, int len);

#endif
