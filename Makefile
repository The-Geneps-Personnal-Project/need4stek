SRC	=	src/main.c	\
		src/commands.c	\
		src/loop.c	\
		src/info.c	\
		src/simulation.c

NAME	=	ai

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g

IFLAGS	=	-I./include

LIB 	=	-L./lib/my -lmy

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(IFLAGS) $(LIB)

clean:
	make clean -C lib/my
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re