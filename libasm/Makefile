SRCS =		ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \

SRCS_BONUS =

OBJF =		$(SRCS:.s=.o)

OBJF_BONUS =	

INCLUDE =	libasm.h

NAME =		libasm.a

.PHONY: 	all clean fclean re bonus

all: 		$(NAME)

%.o:%.s
			nasm -f macho64 $< -o $@

$(NAME):	$(OBJF)
			ar rc $(NAME) $?
clean:
			rm -rf *.o

fclean:		clean
			rm -rf libasm.a

re:			fclean all

bonus:		$(OBJF) $(OBJF_BONUS)
			ar rc $(NAME) $(OBJF_BONUS)
			nams -f elf $< -o $@

main:		all
			gcc main.c $(NAME) -o libasm