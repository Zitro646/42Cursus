# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# RESOURCES #
SRCS = ft_sa.c ft_sb.c ft_ss.c ft_pa.c ft_pb.c  ft_ra.c ft_rb.c ft_rr.c ft_rra.c ft_rrb.c ft_rrr.c


# FLAGS #
OBJS = ${SRCS:.c=.o}

NAME = operations.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs


# Instructions #
all:${NAME}

${NAME}: ${OBJS}
	$(BLUE) Ensambling OPERATIONS Library $(RESET)	
	${AR} ${NAME} ${OBJS}
	$(BLUE) OPERATIONS Library Ensambled $(RESET)
	
%.o:	%.c 
	$(CYAN) Compiling OPERATIONS Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning OPERATIONS Objects $(RESET)
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re






