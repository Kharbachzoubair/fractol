CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
NAME = fractol
SRC = fractol.c init.c render.c hooks.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all