##
## Makefile for zappy in /home/anthony/Documents/repository/psu/PSU_2016_zappy/zappy_server
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Mon Jun 19 19:45:21 2017 Anthony LECLERC
## Last update Sun Jul  2 23:25:24 2017 Anthony LECLERC
##

CC		=	gcc

include		sources.mk

OBJ		=	$(SRC:.c=.o)
CFLAGS		=	-W -Wall -Wextra --std=gnu90
INC		=	-Iinclude/ -I../common

ifeq ($(DEBUG), 1)
CFLAGS		+=	-g -ggdb3 -DDEBUG
endif

TARGET		=	zappy_server

NAME		=	../$(TARGET)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(INC) $(LIBS) -lm
clean:
			rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:			clean fclean re

%.o :			%.c
			$(CC) -c $< -o $@ $(CFLAGS) $(INC)
