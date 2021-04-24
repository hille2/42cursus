/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:07:37 by sgath             #+#    #+#             */
/*   Updated: 2020/12/17 21:03:01 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_to_dot(const char **argum, va_list ap, t_struct *s_a)
{
	if (**argum == '*')
	{
		s_a->length = va_arg(ap, int);
		if (s_a->length < 0)
		{
			s_a->flag = -1;
			s_a->length *= (-1);
		}
		(*argum)++;
	}
	else
	{
		s_a->length = ft_atoi(*argum);
		while (**argum >= '0' && **argum <= '9')
			(*argum)++;
	}
}

static void		ft_after_dot(const char **argum, va_list ap, t_struct *s_a)
{
	s_a->dot = 1;
	(*argum)++;
	if (**argum == '*' || (**argum >= '0' && **argum <= '9'))
	{
		if (**argum == '*')
		{
			s_a->pr = va_arg(ap, int);
			(*argum)++;
		}
		else
		{
			s_a->pr = ft_atoi(*argum);
			while (**argum >= '0' && **argum <= '9')
				(*argum)++;
		}
	}
}

t_struct		*ft_parsing_argum(const char **argum, va_list ap)
{
	t_struct	*struct_arg;

	if (!(struct_arg = malloc(sizeof(t_struct))))
		return (NULL);
	ft_be_zero(struct_arg);
	while (**argum == '-' || **argum == '0')
	{
		if (**argum == '-')
			struct_arg->flag = -1;
		else if (struct_arg->flag != -1)
			struct_arg->flag = 1;
		(*argum)++;
	}
	if (**argum == '*' || (**argum >= '1' && **argum <= '9'))
		ft_to_dot(argum, ap, struct_arg);
	if (*(*argum) == '.')
		ft_after_dot(argum, ap, struct_arg);
	return (struct_arg);
}

int				ft_check_arg(const char **argum, va_list ap)
{
	int			i;
	int			len;
	char		*specifier;
	t_struct	*s_a;

	i = -1;
	len = 0;
	s_a = ft_parsing_argum(argum, ap);
	specifier = "cspdiuxX%";
	while (specifier[++i] && s_a)
	{
		if (**argum == specifier[i])
		{
			s_a->type = **argum;
			len = ft_choise_type(s_a, ap);
			free(s_a);
			return (len);
		}
	}
	if (s_a)
		free(s_a);
	return (-1);
}

int				ft_printf(const char *argum, ...)
{
	va_list	ap;
	int		len;
	int		l;

	va_start(ap, argum);
	len = 0;
	while (*argum)
	{
		if (*argum == '%')
		{
			argum++;
			if ((l = ft_check_arg(&argum, ap)) < 0)
				return (-1);
			else
				len += l;
		}
		else if (++len && write(1, &(*argum), 1) < 0)
			return (-1);
		argum++;
	}
	va_end(ap);
	return (len);
}
