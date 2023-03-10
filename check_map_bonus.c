/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:05:16 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/02 13:14:58 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_exist(char **map, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'B'
					&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				ft_perror();
			if (map[i][j] == c)
				n++;
			j++;
		}
		i++;
	}
	if (n >= 1 && c == 'C')
		return (1);
	if (n == 1)
		return (1);
	return (0);
}

void	error(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
					&& map[i][j] != 'E' && map[i][j] != 'B')
				ft_perror();
			j++;
		}
		i++;
	}
}

void	floud(char **map, int i, int j)
{
	if (i <= 0 || i >= count_line_map(map) - 1 || j <= 0
		|| j >= ft_strlen(map[0]) - 1 || map[i][j] == '1' || map[i][j] == 'E'
		|| map[i][j] == 'B')
		return ;
	else
		map[i][j] = '1';
	floud(map, i + 1, j);
	floud(map, i - 1, j);
	floud(map, i, j + 1);
	floud(map, i, j - 1);
}

int	check_map(char **map)
{
	int	i;
	int	*tab;

	i = -1;
	while (++i < count_line_map(map))
	{
		if (map[i][ft_strlen(map[i]) - 1] != '\n')
			break ;
		map[i][ft_strlen(map[i]) - 1] = '\0';
	}
	if (!check_columns(map) || !check_rows(map) || !check_exist(map, 'E')
		|| !check_exist(map, 'P') || !check_exist(map, 'C'))
		ft_perror();
	tab = check_position(map, 'P');
	floud(map, tab[0], tab[1]);
	error(map);
	free(tab);
	return (1);
}
