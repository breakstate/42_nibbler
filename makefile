# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 11:41:20 by qmanamel          #+#    #+#              #
#    Updated: 2018/07/11 08:32:14 by qmanamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

CC = clang++

FLAGS =	#Add Flags Last			

HEADERS = -I hdr/

SRC_DIR = srcs/

OBJ_DIR_NAME =	obj
OBJ_DIR = ./$(OBJ_DIR_NAME)/

FILENAMES = main Game Snake ObjectManager

COMPILED_PATHS :=	$(addsuffix .o,$(FILENAMES))
COMPILED_PATHS :=	$(addprefix $(OBJ_DIR),$(COMPILED_PATHS))

all: $(NAME)

$(NAME): $(COMPILED_PATHS)
	$(CC) -o $(NAME) $(FLAGS) $(HEADERS) $(COMPILED_PATHS)

$(COMPILED_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	rm -f $(COMPILED_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	rm -f $(NAME)

re: fclean all