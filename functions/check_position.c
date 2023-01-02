/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:30:29 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/02 17:18:09 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../so_long_bonus.h"

int	*check_position(char **map, char c)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(2 * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				tab[0] = i;
				tab[1] = j;
				return (tab);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (0);
}
