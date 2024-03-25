SRC	=	get_input.c	\
		my_free_tab.c	\
		my_str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

LIB	=	-L. -lmy

CFLAGS	=	-I./include -Wextra -Wall -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(TOBJ)

fclean:	clean
	rm -f libmy.a
	rm -f *.o

re:	fclean all