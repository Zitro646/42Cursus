# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# PATHS #
MLB_PATH = minilibx_opengl
GNL_PATH = get_next_line
LIB_PATH = Libft
MAP_PATH = map
GAM_PATH = game

# FLAGS #
SRCS = main.c

OBJS = ${SRCS:.c=.o}

NAME = a.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
# INSTRUCTIONS #
all: pre ${NAME}

pre:
	@make -sC $(LIB_PATH)
	@make -sC $(MAP_PATH)
	@make -sC $(GAM_PATH)

${NAME}: ${OBJS}
	$(BLUE) Ensambling Libraries $(RESET)
	$(CC) $(CFLAGS) $(SRCS) $(GAM_PATH)/$(GAM_PATH).a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o:	%.c 
	$(CYAN) Compiling SoLong Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning ALL Objects $(RESET)
	@make fclean -sC $(MAP_PATH)
	@make fclean -sC $(LIB_PATH)
	@make fclean -sC $(GAM_PATH)
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re pre