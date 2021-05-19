# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgath <sgath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 21:07:57 by sgath             #+#    #+#              #
#    Updated: 2021/05/05 21:22:33 by sgath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo_one

SRC =		main.c\
			ft_atoi.c \

OBJ =		$(SRCS:.s=.o)

INCLUDE =	philo.h \
			struct_philo.h \

FLAGS =		-g -Wall -Wextra 
#-Werror

.PHONY: 	all clean fclean re bonus

$(NAME):	$(OBJ)
			gcc $(SRC) $(FLAGS) $? -o $@
			
all: 		$(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
