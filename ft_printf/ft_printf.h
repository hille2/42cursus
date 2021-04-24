/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:46:45 by sgath             #+#    #+#             */
/*   Updated: 2020/12/17 21:03:12 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_struct
{
	int			flag;
	int			length;
	int			dot;
	int			pr;
	char		type;
}				t_struct;

t_struct		*ft_parsing_argum(const char **argum, va_list ap);

char			*ft_16stm(unsigned long long n, int stm);

void			ft_be_zero(t_struct *struct_arg);
void			ft_out_cycle(int loop, char smbl);
void			ft_ll(size_t nb);
void			ft_out_condition(t_struct *s_a, int len, int negt);

int				ft_printf(const char *argum, ...);
int				ft_check_arg(const char **argum, va_list ap);
int				ft_choise_type(t_struct *s_a, va_list ap);
int				ft_arg_pr(t_struct *s_a);
int				ft_arg_x(t_struct *s_a, va_list ap);
int				ft_arg_d(t_struct *s_a, va_list ap);
int				ft_arg_u(t_struct *s_a, va_list ap);
int				ft_arg_p(t_struct *s_a, va_list ap);
int				ft_arg_s(t_struct *s_a, va_list ap);
int				ft_arg_c(t_struct *s_a, va_list ap);
int				ft_numlen(long n, int stm);

#endif
