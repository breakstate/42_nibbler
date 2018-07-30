CLANG = clang++

NAME = SFML.so

DIR_SFML = SFML

GL =	-rpath $(HOME)/.brew/lib -L$(HOME)/.brew/lib 
GL +=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

CFLAGS = -Wall -Werror -Wextra

SFML_FLAGS = -Iincludes/ -I$(HOME)/.brew/Cellar/sfml/2.4.2_1/include/

HEADER = includes/SFML.hpp

SRC =	sources/SFML.cpp

OBJ = $(SRC:.cpp=.cpp.o)

%.cpp.o: %.cpp
	@$(CLANG) $(CFLAGS) $(SFML_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLANG) -shared -fPIC $(GL) $(CFLAGS) $(SFML_FLAGS) -o $(NAME) $(OBJ)

extract:
	#Ignore Thisl
	#@git clone https://github.com/SFML/SFML.git

clean:
	@rm -rf $(OBJ)
	@rm -rf sfml

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
