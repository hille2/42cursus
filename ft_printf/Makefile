NAME = libftprintf.a

FLC = ft_othen.c ft_othen2.c ft_printf.c ft_type_c.c ft_type_d.c ft_type_p.c ft_type_pr.c ft_type_s.c ft_type_u.c ft_type_x.c
FLO = $(FLC:.c=.o)
FLH = ft_printf.h

FLG = -c -Wall -Wextra -Werror
CLN = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(FLO)
	$(MAKE) -C libft
	cp libft/libft.a $@
	ar rcs $@ $(FLO)

clean: 
	$(CLN) $(FLO)
	$(MAKE) clean -C libft

fclean:
	$(CLN) $(FLO) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
