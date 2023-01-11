/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:16:40 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/05 17:42:49 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	handle_up(t_game *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	free(tab);
	if (game->map[y - 1][x] == '1')
		return ;
	if (game->map[y - 1][x] == 'E')
	{
		if (check_exist_c(game->map))
			return ;
		game_over();
	}
	ft_putnbr_fd(game->move++, 1);
	ft_putchar('\n', 1);
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
}

void	handle_left(t_game *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	free(tab);
	if (game->map[y][x - 1] == '1')
		return ;
	if (game->map[y][x - 1] == 'E')
	{
		if (check_exist_c(game->map))
			return ;
		game_over();
	}
	ft_putnbr_fd(game->move++, 1);
	ft_putchar('\n', 1);
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
}

void	handle_right(t_game *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	free(tab);
	if (game->map[y][x + 1] == '1')
		return ;
	if (game->map[y][x + 1] == 'E')
	{
		if (check_exist_c(game->map))
			return ;
		game_over();
	}
	ft_putnbr_fd(game->move++, 1);
	ft_putchar('\n', 1);
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
}

void	handle_down(t_game *game)
{
	int	x;
	int	y;
	int	*tab;

	tab = check_position(game->map, 'P');
	y = tab[0];
	x = tab[1];
	free(tab);
	if (game->map[y + 1][x] == '1')
		return ;
	if (game->map[y + 1][x] == 'E')
	{
		if (check_exist_c(game->map))
			return ;
		game_over();
	}
	ft_putnbr_fd(game->move++, 1);
	ft_putchar('\n', 1);
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
}
