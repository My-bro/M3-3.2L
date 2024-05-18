##
## EPITECH PROJECT, 2024
## M3-3.2L [WSL: Ubuntu]
## File description:
## Makefile
##

SRC = 	Ball/Ball.cpp\
		Display/Display.cpp\
		Display/Sprite.cpp\
		M3/M3.cpp\
		main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = M3_3.2L

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++20

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

CPPFLAGS = -I./include -I./M3 -I./Display -I./Ball

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ) $(SFMLFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
