#include "../so_long.h"
#include "../so_long_bonus.h"

int game_over(void)
{
   write(1, "\033[0;31mGame Over\033[0m\n", 21);
   exit(0);
   return(0);
}