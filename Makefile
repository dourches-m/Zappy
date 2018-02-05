##
## Makefile for zappy in /home/anthony/Documents/repository/psu/PSU_2016_zappy/zappy_server
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Mon Jun 19 19:45:21 2017 Anthony LECLERC
## Last update Sun Jul  2 23:42:01 2017 Anthony LECLERC
##

CC		=	gcc

ZAPPY_AI	=	zappy_ai

OBJ		=	$(SRC:.c=.o)
CFLAGS		=	-W -Wall -Wextra
INC		=	-Iinclude/

ifeq ($(DEBUG), 1)
CFLAGS		+=	-g -ggdb3
endif

RM		=	rm -f

LINK		=	ln -s

all:			zappy_server zappy_ai zappy_graphics

zappy_server:
			$(MAKE) -C server

zappy_graphics:
			$(MAKE) -C graphics

zappy_ai:
			$(LINK) ia_src/zappy_ai .

clean:
			$(MAKE) clean -C server

fclean:
			$(MAKE) fclean -C server
			$(MAKE) fclean -C graphics
			$(RM) $(ZAPPY_AI)

re:			fclean all

.PHONY:			all clean fclean re zappy_server zappy_graphics

%.o :			%.c
			$(CC) -c $< -o $@ $(CFLAGS) $(INC)
