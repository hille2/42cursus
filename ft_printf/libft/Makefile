# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgath <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 13:31:49 by sgath             #+#    #+#              #
#    Updated: 2020/11/08 15:25:00 by sgath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SFL = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
FLO = $(SFL:.c=.o)

SFL_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
FLO_B = $(SFL_B:.c=.o)
FLAGS = -Wall -Wextra -Werror
CLN = /bin/rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(FLO)
	@gcc -c $(FLAGS) $(SFL) -I libft.h
	@ar rc $(NAME) $(FLO)

clean: 
	$(CLN) $(FLO)

fclean:
	$(CLN) $(FLO) $(NAME)

re: fclean all

bonus:
	gcc -c $(FLAGS) $(SFL_B) $(SFL) -I libft.h
	ar rc $(NAME) $(FLO_B) $(FLO)


