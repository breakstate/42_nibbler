CLANG = clang++

NAME = GLFW.so

DIR_SFML = SFML

GL =	-rpath $(HOME)/.brew/lib -L$(HOME)/.brew/Cellar/glfw/3.2.1/lib/
GL +=	-lglfw -framework OpenGL -framework CoreVideo

CFLAGS = #-Wall -Werror -Wextra

SFML_FLAGS = -I$(HOME)/.brew/Cellar/glfw/3.2.1/include/

HEADER = includes/GLFW.hpp

SRC =	sources/GLFW.cpp

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
