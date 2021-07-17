# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yu <yu@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 21:07:57 by sgath             #+#    #+#              #
#    Updated: 2021/07/17 20:49:25 by yu               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			philo

SRC =			main.c\
				init.c \
				utils.c \
				threads.c \

INCLUDE =		philo.h \

FLAGS =			-g -Wall -Wextra
#-Werror

FLAGS_LINUX =	-pthread -o term 

.PHONY: 		all clean fclean re bonus

$(NAME):		
				gcc $(SRC) $(FLAGS) $(FLAGS_LINUX) $? -o $@
			
all: 			$(NAME)

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
