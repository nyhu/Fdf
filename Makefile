.PHONY: fclean re
.SUFFIXES:
NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRCS = $(foreach S, $(SRC), srcs/$(S))
OBJ = $(SRCS:.c=.o)
TERMCAPS = -lm -lncurses
MLX = -lmlx -lm
HEAD = -I libft/includes -I includes
OS = $(shell uname -s)
LIB = libft
LMLX =
SRC = main.c \
	free.c parse.c win_fill.c utils.c img_work.c config.c pers.c color.c

ifeq ($(OS), Linux)
	FLAGS += -D LINUX
	MLX += -L minilibx -L /usr/lib/x86_64-linux-gnu -l X11 -l Xext
	MLX += -lX11 -lXext -lm
	LMLX += minilibx
	HEAD += -I minilibx
else
	MLX += -L minilibx_macos
	LMLX += minilibx_macos
	HEAD += -I minilibx_macos
	MLX += -framework Opengl -framework Appkit
endif

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(HEAD) $^ -L libft -l ft -o $@ $(MLX)

%.o: %.c libft/libft.a
	gcc $(FLAGS) $(HEAD) -c $< -o $@

lib:
	make -C $(LIB)
	make -C $(LMLX)

clean:
	rm -f $(OBJ)
	make clean -C $(LIB)
	make clean -C $(LMLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB)

re: fclean all

re: fclean lib $(DNAME)
