CFLAGS = -Wall -Wextra -Werror
PROG = so_long
BPROG = so_long_bonus
SOURCES = so_long.c functions/get_next_line.c check_map.c functions/ft_perror.c  so_long_utils.c moves.c functions/ft_itoa.c functions/ft_strncmp.c
BSOURCES =  so_long_bonus.c functions/get_next_line.c check_map_bonus.c  functions/ft_perror.c so_long_utils_bonus.c  moves_bonus.c functions/ft_itoa.c functions/ft_strncmp.c 
OBJECTS = $(SOURCES:.c=.o)
BOBJECT = $(BSOURCES:.c=.o)
all: $(PROG)

$(PROG)	: $(OBJECTS)
	cc	$(CFLAGS) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit  -o $(PROG)
bonus : $(BOBJECT)
	cc	$(CFLAGS) $(BOBJECT)  -lmlx -framework OpenGL -framework AppKit  -o $(BPROG)
clean: 
	rm -f $(OBJECTS) $(BOBJECT)

fclean: clean
	rm -f $(PROG) $(OBJECTS) $(BOBJECTS) $(BPROG)

re: fclean all