# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 11:41:20 by qmanamel          #+#    #+#              #
#    Updated: 2018/07/25 13:53:20 by qmanamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

CC = clang++

FLAGS =	
 
LDFLAGS = -rpath libraries/SFML/SFML/lib

HEADERS = -I includes/

SRC_DIR = sources/

OBJ_DIR_NAME =	objects
OBJ_DIR = ./$(OBJ_DIR_NAME)/

FILENAMES = main Game Snake ObjectManager

COMPILED_PATHS :=	$(addsuffix .o,$(FILENAMES))
COMPILED_PATHS :=	$(addprefix $(OBJ_DIR),$(COMPILED_PATHS))

SDL_MAKE = make -C libraries/SDL2

all: $(NAME)

$(NAME): $(COMPILED_PATHS)
	$(CC) $(LDFLAGS) -o $(NAME) $(FLAGS) $(HEADERS) $(COMPILED_PATHS)

$(COMPILED_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	rm -f $(COMPILED_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	rm -f $(NAME)

re: fclean all