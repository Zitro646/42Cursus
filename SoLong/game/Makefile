# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# RESOURCES #
SRCS = game_mechanics.c

# FLAGS #
OBJS = ${SRCS:.c=.o}

NAME = game.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs


# Instructions #
all: ${NAME}

${NAME}: ${OBJS}
	cp ../map/map.a $(NAME)
	${AR} ${NAME} ${OBJS}
	$(BLUE) MAP Library Ensambled $(RESET)	
	
%.o:	%.c 
	$(CYAN) Compiling MAP Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning MAP Objects $(RESET)
	@rm -rf ${OBJS}
fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re