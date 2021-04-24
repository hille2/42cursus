# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgath <sgath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 13:31:49 by sgath             #+#    #+#              #
#    Updated: 2021/02/13 20:54:03 by sgath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLH = libft.h

SFL =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

SFL_B = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstsort.c

FLO = $(SFL:.c=.o)
FLO_B = $(SFL_B:.c=.o)

FLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(FLO) $(FLH)
	@gcc $(FLAGS) $(SFL) -I $(FLH)
	@ar rc $(NAME) $(FLO)

clean: 
	$(RM) $(FLO) $(FLO_B)

fclean:
	$(RM) $(FLO) $(FLO_B) $(NAME)

re: fclean all

bonus:
	gcc $(FLAGS) $(SFL_B) $(SFL) -I $(FLH)
	ar rc $(NAME) $(FLO) $(FLO_B)


