NAME = cub3D

FLC =	main.c \
		parsing_map_path_1.c \
		parsing_map_path_2.c \
		parsing_map_path_3.c \
		other_3d_pact_1.c \
		check_error.c  \
		how_be_free.c  \
		actions_pact_1.c \
		actions_pact_2.c \
		make_3dcard_pact_1.c \
		make_3dcard_pact_2.c \
		make_3dcard_pact_3.c \
		make_3dcard_pact_4.c \
		screen.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 

FLH =	includes/cub3d.h \
		includes/struct_parser.h \
		get_next_line/get_next_line.h 

FLG = -Wall -Wextra -Werror -framework OpenGL -framework AppKit 

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(FLC) $(FLH)
	$(MAKE) bonus -C libft
	$(MAKE) -C minilibx_mms
	gcc $(FLG) -g -L. libmlx.dylib -L ./libft/ -lft $(FLC) -o $(NAME)

clean: 
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx_mms 

fclean:
	$(RM) $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) clean -C minilibx_mms

re: fclean all

bonus: