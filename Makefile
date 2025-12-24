CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= push_swap.c push_swap_utils.c validate.c ft_split.c \
		  lst_handling.c mem_handling.c operations.c a_operations.c \
		  b_operations.c sort.c operations_utils.c sort_utils.c shared_utils.c

SRC_BONUS = checker.c operations.c a_operations.c b_operations.c \
			push_swap_utils.c validate.c get_next_line.c \
			get_next_line_utils.c mem_handling.c lst_handling.c ft_split.c \
			shared_utils.c operations_utils.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ		= $(SRC:.c=.o)

NAME		= push_swap

NAME_BONUS = checker

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus