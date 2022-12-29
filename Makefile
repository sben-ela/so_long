CFLAGS = -Wall -Wextra -Werror
PROG = so_long
SOURCES = main.c get_next_line.c check_map.c ft_perror.c
OBJECTS = $(SOURCES:.c=.o)

all: $(PROG)

$(PROG)	: $(OBJECTS)

	cc	$(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit  -o $(PROG)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROG)

re: fclean all