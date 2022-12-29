#include "so_long.h"

void ft_perror(void)
{
    write(2, "ERROR", 5);
    exit(1);
}