# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgath <sgath@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 21:07:57 by sgath             #+#    #+#              #
#    Updated: 2021/07/18 17:58:00 by sgath            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			philo_one

SRC =			main.c\
				init.c \
				utils.c \
				threads.c \

INCLUDE =		philo.h \

FLAGS =			-Wall -Wextra -Werror

FLAGS_LINUX =	-pthread -o term 

.PHONY: 		all clean fclean re bonus

$(NAME):		$(SRC) $(INCLUDE)
				gcc $(SRC) $(FLAGS) $(FLAGS_LINUX) -o $@
			
all: 			$(NAME)

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
