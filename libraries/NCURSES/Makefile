CLANG = clang++

NAME = NCURSES.so

DIR_SFML = SFML

GL =	-lncurses

CFLAGS = #-Wall -Werror -Wextra

SFML_FLAGS = -Iincludes/

SRC =	sources/NCURSES.cpp

OBJ = $(SRC:.cpp=.cpp.o)

%.cpp.o: %.cpp
	@$(CLANG) $(CFLAGS) $(SFML_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) -shared -fPIC $(GL) $(CFLAGS) $(SFML_FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
