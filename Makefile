CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= push_swap.c push_swap_utils.c validate.c ft_split.c \
		  lst_handling.c mem_handling.c operations.c a_operations.c \
		  b_operations.c sort.c operations_utils.c sort_utils.c
OBJ		= $(SRC:.c=.o)

NAME		= push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean