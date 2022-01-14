# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# RESOURCES #
SRCS = client.c server.c encryption.c

# PATHS #
LIB_PATH = Libft

# FLAGS #
OBJS = ${SRCS:.c=.o}

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

AR = ar rcs


# Instructions #
all: pre ${NAME}
	
pre:
	@make -sC $(LIB_PATH)

client:${NAME}
	$(CC) $(CFLAGS) client.c encryption.c ./Libft/libft.a minitalk.h -o $(NAME_CLIENT)

server:${NAME}
	$(CC) $(CFLAGS) server.c decryption.c ./Libft/libft.a minitalk.h -o $(NAME_SERVER)

${NAME}: ${OBJS}	

%.o:	%.c 
	$(CYAN) Compiling LIBFT Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning LIBFT Objects $(RESET)
	@make fclean -sC $(LIB_PATH)
	@rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re client server