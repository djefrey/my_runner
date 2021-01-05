##
## EPITECH PROJECT, 2020
## my_runner
## File description:
## Makefile
##

SRC		=	src/main.c					\
			src/menu/menu.c				\
			src/menu/menu_events.c		\
			src/menu/skins.c		\
			src/game/my_runner.c		\
			src/game/game_update.c		\
			src/game/game_draw.c		\
			src/game/events.c			\
			src/game/setup.c			\
			src/game/level.c			\
			src/game/physics.c			\
			src/game/score.c			\
			src/game/objects/objects.c	\
			src/game/objects/player.c	\
			src/game/objects/blocks.c	\
			src/graphics/backgrounds.c	\
			src/graphics/framebuffer.c	\
			src/graphics/fade.c			\
			src/graphics/texts.c		\
			src/graphics/textures.c
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