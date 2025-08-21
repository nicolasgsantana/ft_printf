NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_itohex.c ft_ptrtohex.c ft_uitoa.c ft_printf_utils.c
LIBFT = ./libft

HEADER = ft_printf.h
CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	$(MAKE) all -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME) *.o $(LIBFT)/*.o

clean:
	rm -f *.o
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all
