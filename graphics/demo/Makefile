##
## Makefile for zappy in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Last update Sun Jul  2 21:04:15 2017 Sylvain Chaugny
## Last update Thu Apr  6 00:41:36 2017 Sylvain Chaugny
##

CC		=	gcc

DEBUG		?=	0

ifeq ($(DEBUG), 1)
CFLAGS		+=	-g -ggdb3
endif

NAME		=	demo_server

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-I../include -I./include

include			sources.mk

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $@
