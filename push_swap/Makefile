# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# VARIABLES #
NAME = push_swap
LIBFT_NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT_PATH)

# PATHs #
LIBFT_PATH  = srcs/libft
TOOL_PATH  = srcs/tools
OPERATION_PATH  = srcs/operations
INC_PATH    = includes
SRC_PATH    = srcs
OBJ_PATH    = objects



# SOURCES #
SRC =   main.c

SRC_TOOL = ft_starter_array.c ft_error_checker.c ft_look_arrays.c  \
ft_map_array.c ft_arrange_less_than_3.c ft_arrange_less_than_5.c ft_arrange_more_than_5.c

SRC_OPERATIONS = ft_sa.c ft_sb.c ft_ss.c ft_pa.c ft_pb.c  ft_ra.c ft_rb.c ft_rr.c ft_rra.c ft_rrb.c ft_rrr.c

# RULES #
all: $(NAME)

OBJ_NAME = $(SRC:%.c=%.o)
OBJ_TOOLS = $(SRC_TOOL:%.c=%.o)
OBJ_OPERATION = $(SRC_OPERATIONS:%.c=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRC))
SRCS_OPERATIONS = $(addprefix $(OPERATION_PATH)/, $(SRC))
SRCS_TOOL = $(addprefix $(TOOL_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJS_TOOLS =  $(addprefix $(OBJ_PATH)/, $(OBJ_TOOLS))
OBJS_OPERATION =  $(addprefix $(OBJ_PATH)/, $(OBJ_OPERATION))

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(OPERATION_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(TOOL_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
            
$(NAME): $(OBJS) $(OBJS_OPERATION) $(OBJS_TOOLS) | $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_OPERATION) $(OBJS_TOOLS) -o $(NAME) $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

$(LIBFT_NAME):
	$(MAKE) -sC $(LIBFT_PATH)

##RULES
$(MAKE): make

norminette:
	norminette $(SRCS)
	norminette $(LIBFT_PATH)
	norminette $(TOOL_PATH)
	norminette $(OPERATION_PATH)

clean:
	$(PURPLE) CLEANING OBJECTS $(RESET)
	rm -rf $(OBJS)
	rm -rf $(OBJS_TOOLS)
	rm -rf $(OBJS_OPERATION)
	
fclean: clean
	$(PURPLE) CLEANING DIRECTORY AND EXEC $(RESET)
	rm -rf $(NAME)
	rm -rf $(OBJ_PATH)
	make fclean -sC $(LIBFT_PATH)

re: fclean all

PHONY.: all clean fclean re norminette