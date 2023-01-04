#include "so_long.h"
#include "so_long_bonus.h"

int	hook(int key_number, t_bgame *game)
{
	if (key_number == 53)
		game_over();
	if (key_number == 13 || key_number == 126)
	{
		ft_handle_up(game);
		game->d = 3;
	}
	else if (key_number == 0 || key_number == 123)
	{
		ft_handle_left(game);
		game->d = 0;
	}
	else if (key_number == 1 || key_number == 125)
	{
		ft_handle_down(game);
		game->d = 1;
	}
	else if (key_number == 2 || key_number == 124)
	{
		ft_handle_right(game);
		game->d = 2;
	}
	ft_full_window(game);
	return (0);
}