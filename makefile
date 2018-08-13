# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 11:41:20 by qmanamel          #+#    #+#              #
#    Updated: 2018/08/10 14:48:24 by qmanamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

CC = clang++

FLAGS =	-Wall -Werror -Wextra
 
LDFLAGS = -rpath libraries/SFML/SFML/lib

HEADERS = -I includes/

SRC_DIR = sources/

OBJ_DIR_NAME =	objects
OBJ_DIR = ./$(OBJ_DIR_NAME)/

FILENAMES = main Game Snake ObjectManager

COMPILED_PATHS :=	$(addsuffix .o,$(FILENAMES))
COMPILED_PATHS :=	$(addprefix $(OBJ_DIR),$(COMPILED_PATHS))

RED='\033[0;31m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'
NC='\033[0m'

all: $(NAME)

$(NAME): $(COMPILED_PATHS)
	@echo "$(GREEN)Making SDL2$(NC)"
	@$(MAKE) -C libraries/SDL2/
	@echo "$(GREEN)Making SFML$(NC)"
	@$(MAKE) -C libraries/SFML/
	@echo "$(GREEN)Making NCURSES$(NC)"
	@$(MAKE) -C libraries/NCURSES/
	@echo "$(GREEN)Making Main prog$(NC)"
	@$(CC) $(LDFLAGS) -o $(NAME) $(FLAGS) $(HEADERS) $(COMPILED_PATHS)

$(COMPILED_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	@rm -f $(COMPILED_PATHS)
	@/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Fcleaning SDL2$(NC)"
	@$(MAKE) fclean -C libraries/SDL2/
	@echo "$(RED)Fcleaning SFML$(NC)"
	@$(MAKE) fclean -C libraries/SFML/
	@echo "$(RED)Fcleaning NCURSES$(NC)"
	@$(MAKE) fclean -C libraries/NCURSES/
	@echo "$(RED)Fcleaning Main prog$(NC)"

re: fclean all
	@echo "$(PURPLE)Remaking SDL2$(NC)"
	@$(MAKE) re -C libraries/SDL2/
	@echo "$(PURPLE)Remaking SFML$(NC)"
	@$(MAKE) re -C libraries/SFML/
	@echo "$(PURPLE)Remaking NCURSES$(NC)"
	@$(MAKE) re -C libraries/NCURSES/
	@echo "$(PURPLE)Remaking Main prog$(NC)"