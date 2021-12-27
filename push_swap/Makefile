# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# PATHS #
LIB_PATH = libft
OPT_PATH = operations
TOOL_PATH = tools

# FLAGS #
SRCS = main.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra 
# -g3
# -fsanitize=address
# INSTRUCTIONS #
all: pre ${NAME}

pre:
	@make -sC $(LIB_PATH)
	@make -sC $(OPT_PATH)
	@make -sC $(TOOL_PATH)

${NAME}: ${OBJS}
	$(BLUE) Ensambling Libraries $(RESET)
	$(CC) $(CFLAGS) $(SRCS) tools/tools.a -o $(NAME)
%.o:	%.c 
	$(CYAN) Compiling PUSH_SWAP Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning ALL Objects $(RESET)
	@make fclean -sC $(LIB_PATH)
	@make fclean -sC $(OPT_PATH)
	@make fclean -sC $(TOOL_PATH)
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re pre






