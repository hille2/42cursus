/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:23:56 by sgath             #+#    #+#             */
/*   Updated: 2020/11/22 15:48:18 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_n(char *str)
{
	int n;

	n = -1;
	while (str[++n])
		if (str[n] == '\n')
			return (n);
	return (-1);
}

static int	ft_rez_line(char **line, char **rem_str, int ret)
{
	int	i;
	int	n_str;

	n_str = ft_find_n(*rem_str);
	if ((n_str < ft_strlen(*rem_str) && n_str >= 0) && ret >= 0)
	{
		if (!(*line = malloc(sizeof(char) * (n_str + 1))))
			return (-1);
		i = -1;
		while (++i < n_str)
			(*line)[i] = (*rem_str)[i];
		(*line)[n_str] = '\0';
		if (!(*rem_str = ft_substr(*rem_str, n_str + 1, ft_strlen(*rem_str))))
			return (-1);
		return (1);
	}
	*line = ft_strdup(*rem_str);
	free((*rem_str));
	*rem_str = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	int			count;
	char		buf[BUFFER_SIZE + 1];
	static char	*rem_str;

	count = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (count == 0 && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		(!rem_str) ? rem_str = ft_strdup(buf) :
			(rem_str = ft_strjoin(rem_str, buf));
		if (ft_strchr(buf, '\n'))
			count = 1;
	}
	if (ret == 0 && !rem_str)
	{
		*line = ft_strdup("");
		return (ret);
	}
	count = ft_rez_line(line, &rem_str, ret);
	return ((ret == 0 && count <= 0) ? count : 1);
}
