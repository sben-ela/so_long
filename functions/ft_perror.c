#include "../so_long.h"

void ft_perror(void)
{
    write(2, "ERROR\n", 6);
    exit(1);
}