NAME = SDL2.so

CC = clang++

FLAGS = -L lib -l SDL2

HEADERS = -I includes/

SRC_DIR = sources/

OBJ_DIR_NAME =	objects
OBJ_DIR = ./$(OBJ_DIR_NAME)/

FILENAMES = SDL2

COMPILED_PATHS :=	$(addsuffix .o,$(FILENAMES))
COMPILED_PATHS :=	$(addprefix $(OBJ_DIR),$(COMPILED_PATHS))

all: $(NAME)

$(NAME): $(COMPILED_PATHS)
	$(CC) -shared -o $(NAME) $(HEADERS) $(FLAGS) $(COMPILED_PATHS)

$(COMPILED_PATHS): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@/bin/mkdir -p $(OBJ_DIR)
	$(CC) -c $(HEADERS) $< -o $@

clean:
	rm -f $(COMPILED_PATHS)
	/usr/bin/find . -name "$(OBJ_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	rm -f $(NAME)

re: fclean all