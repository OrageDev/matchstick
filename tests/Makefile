##
## EPITECH PROJECT, 2018
## unit
## File description:
## unit
##

SRC=		../src/utilities.c		\
		../src/get_ai.c		\
		../src/get_next_line.c		\
		../src/get_player.c

SRC_UT=		./tests.c	\
			./my_main.c


OBJ= 		$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS= 	-I ../include -Wall -Wextra --coverage

LDFLAGS= 	-lcriterion -lgcov \
		-L../lib/my/ -lmy

NAME=	 	unit

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
