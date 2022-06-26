NAME = push_swap

CC = gcc
CC_FLAGS =	-g \
			-fsanitize=address
LDFLAGS =	-fsanitize=address
override CC_FLAGS +=	-c \
						-Wall \
						-Wextra \
						-Werror \
						-I${INCLUDE_DIR}

SRC_DIR =./srcs

SRCS =	${SRC_DIR}/main.c \
		${SRC_DIR}/get_stack.c \
		${SRC_DIR}/ft_atoi.c \
		${SRC_DIR}/print_stack.c \
		${SRC_DIR}/free_stack.c \
		${SRC_DIR}/ft_calloc.c \
		${SRC_DIR}/ft_bzero.c \
		${SRC_DIR}/ft_memset.c \
		${SRC_DIR}/quick_sort.c \
		${SRC_DIR}/normalize_input.c \
		${SRC_DIR}/ft_strlen.c

OBJ_DIR = ./objects

OBJ = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, $(SRCS))

INCLUDE_DIR = ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME)