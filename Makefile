NAME = fractol

FILES = init.c fractol.c math.c render.c utils.c render_utils.c events.c

OBJ = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re