##
## EPITECH PROJECT, 2020
## my_runner
## File description:
## Makefile
##

SRC		=	main.c			\
			my_runner.c		\
			events.c		\
			setup.c			\
			backgrounds.c	\
			objects.c		\
			textures.c		\
			player.c		\
			blocks.c		\
			level.c			\
			physics.c
LIB_DIR	=	./mylib
INC_DIR	=	./include
CFLAGS	+=	-W -Wall -I$(INC_DIR)
OBJ		=	$(SRC:.c=.o)
NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lm -lmy

debug:	CFLAGS += -g
debug: 	$(OBJ)
	make -C $(LIB_DIR)
	gcc -g -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lm -lmy

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all