CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
BONUS = so_long_bonus
PROG = so_long
SOURCES = so_long.c functions/get_next_line.c check_map.c functions/ft_perror.c  so_long_utils.c moves.c functions/ft_itoa.c \
			functions/ft_free.c functions/check_position.c functions/ft_strlen.c ft_putnbr_fd.c functions/game_over.c functions/compare.c
BSOURCES =  so_long_bonus.c functions/get_next_line.c check_map_bonus.c  functions/ft_perror.c so_long_utils_bonus.c  moves_bonus.c \
			functions/ft_itoa.c functions/ft_free.c functions/check_position.c functions/ft_strlen.c functions/game_over.c functions/compare.c hook.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	cc	$(CFLAGS)  $(OBJECTS) -lmlx -framework OpenGL -framework AppKit  -o $(PROG)

bonus: ${BONUS}

${BONUS}:
	cc	$(CFLAGS) $(BSOURCES) -lmlx -framework OpenGL -framework AppKit  -o ${BONUS}

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(PROG)

re: fclean all