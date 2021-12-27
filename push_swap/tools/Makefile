# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# RESOURCES #
SRCS = ft_starter_array.c ft_error_checker.c ft_look_arrays.c  \
ft_map_array.c ft_arrange_less_than_3.c ft_arrange_less_than_5.c ft_arrange_more_than_5.c


# FLAGS #
OBJS = ${SRCS:.c=.o}

NAME = tools.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs


# Instructions #
all:${NAME}

${NAME}: ${OBJS}
	cp ../operations/operations.a $(NAME)	
	${AR} ${NAME} ${OBJS}
	$(BLUE) TOOLS Library Ensambled $(RESET)
	
%.o:	%.c 
	$(CYAN) Compiling TOOLS Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning TOOLS Objects $(RESET)
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re






