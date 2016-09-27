.PHONY: fclean re
.SUFFIXES:
NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRCS = $(foreach S, $(SRC), srcs/$(S))
OBJ = $(SRCS:.c=.o)
TERMCAPS = -lm -lncurses
MLX = -L /usr/X11/lib -lmlx -lXext -lX11
HEAD = -I libft/includes -I includes
OS = $(shell uname -s)
MC = $(foreach L, $(LIB), make -C $(L) ;)
MCA = $(foreach L, $(LIB), make -C $(L) $@;)
LIB = libft
SRC = {main, pixel_put}.c

ifeq ($(OS), Linux)
	FLAGS += -D LINUX
	LIB += minilibx
else
	LIB += minilibx_macos
endif

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(HEAD) $^ -L libft -l ft -o $@ $(MLX)

%.o: %.c libft/libft.a
	gcc $(FLAGS) $(HEAD) -c $< -o $@

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
