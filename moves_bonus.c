/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:16:40 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/02 15:28:56 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_exist_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_handle_up(t_bgame *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	if (game->map[y - 1][x] == '1' )
		return ;
	if (game->map[y - 1][x] == 'E' || game->map[y - 1][x] == 'B')
	{
		if (check_exist_c(game->map) && game->map[y - 1][x] == 'E')
			return ;
		write(1, "GAME OVER", 9);
		exit(0);
	}
	game->move++;
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
}

void	ft_handle_left(t_bgame *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x - 1] == 'E' || game->map[y][x - 1] == 'B')
	{
		if (check_exist_c(game->map) && game->map[y][x - 1] == 'E')
			return ;
		write(1, "GAME OVER", 9);
		exit(0);
	}
	game->move++;
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
}

void	ft_handle_right(t_bgame *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x + 1] == 'E' || game->map[y][x + 1] == 'B')
	{
		if (check_exist_c(game->map) && game->map[y][x + 1] == 'E')
			return ;
		write(1, "GAME OVER", 9);
		exit(0);
	}
	game->move++;
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
}

void	ft_handle_down(t_bgame *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	if (game->map[y + 1][x] == '1')
		return ;
	if (game->map[y + 1][x] == 'E' || game->map[y + 1][x] == 'B')
	{
		if (check_exist_c(game->map) && game->map[y + 1][x] == 'E')
			return ;
		write(1, "GAME OVER", 9);
		exit(0);
	}
	game->move++;
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
}
