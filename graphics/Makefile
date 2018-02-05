##
## Makefile for  in /home/anthony/documents/repository/cpp/cpp_arcade
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Last update Sun Jul  2 23:39:22 2017 Anthony LECLERC
## Last update Thu Apr  6 00:41:36 2017 Sylvain Chaugny
##

CXX		=	g++

DEBUG		?=	0

ifeq ($(DEBUG), 1)
CXXFLAGS	+=	-g -ggdb3
endif

TARGET		=	zappy_graphics

NAME		=	$(TARGET)

RM		=	rm -f

CXXFLAGS	+=	-W -Wall -Wextra -std=c++14
CXXFLAGS	+=	-I./include
LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


include			sources.mk

OBJ		=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.cpp.o:
			$(CXX) $(CXXFLAGS) -c $< -o $@
