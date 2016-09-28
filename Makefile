.PHONY: fclean re
.SUFFIXES:
NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRCS = $(foreach S, $(SRC), srcs/$(S))
OBJ = $(SRCS:.c=.o)
TERMCAPS = -lm -lncurses
MLX = -lX11 -lXext -lmlx -lm
HEAD = -I libft/includes -I includes
OS = $(shell uname -s)
MC = $(foreach L, $(LIB), make -C $(L) ;)
MCA = $(foreach L, $(LIB), make -C $(L) $@;)
LIB = libft
SRC = main.c \
	free.c parse.c win_fill.c utils.c img_work.c config.c

ifeq ($(OS), Linux)
	FLAGS += -D LINUX
	LIB += minilibx
	MLX += -L minilibx -L /usr/lib/x86_64-linux-gnu -l X11 -l Xext
	HEAD += -I minilibx
else
	LIB += minilibx_macos
	MLX += -L minilibx_macosx
	HEAD += -I minilibx_macos
endif

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(HEAD) $^ -L libft -l ft -o $@ $(MLX)

%.o: %.c libft/libft.a
	gcc $(FLAGS) $(HEAD) -c $< -o $@ $(MLX)

lib:
	$(MC)

clean:
	rm -f $(OBJ)
	$(MCA)

fclean: clean
	rm -f $(NAME)
	$(MCA)

re: fclean all

re: fclean lib $(DNAME)
