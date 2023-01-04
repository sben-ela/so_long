/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:17:21 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/03 15:11:43 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_to_window(t_game *game, void *img_data, char c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
				mlx_put_image_to_window(game->mlx, game->win, \
				img_data, 60 * j, i * 60);
			if (c == '0' && game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				img_data, 60 * j, i * 60);
			else if (c == '0' && game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
				img_data, 60 * j, i * 60);
			else if (c == '0' && game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
				img_data, 60 * j, i * 60);
			j++;
		}
		i++;
	}
}

int	hook(int key_number, t_game *game)
{
	if (key_number == 53)
		game_over();
	if (key_number == 13 || key_number == 126)
	{
		handle_up(game);
		game->d = 3;
	}
	else if (key_number == 0 || key_number == 123)
	{
		handle_left(game);
		game->d = 0;
	}
	else if (key_number == 1 || key_number == 125)
	{
		handle_down(game);
		game->d = 1;
	}
	else if (key_number == 2 || key_number == 124)
	{
		handle_right(game);
		game->d = 2;
	}
	full_window(game);
	return (0);
}

void	full_window(t_game *game)
{
	static char	*player[4] = {"images/player1.xpm", "images/player2.xpm", \
		"images/player3.xpm", "images/player4.xpm"};

	game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", \
			&game->width, &game->height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "images/ground.xpm", \
			&game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx, player[game->d], \
			&game->width, &game->height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "images/coin.xpm", \
			&game->width, &game->height);
	game->door = mlx_xpm_file_to_image(game->mlx, "images/door.xpm", \
			&game->width, &game->height);
	if(!game->door || !game->ground || !game->player || !game->coin || !game->wall)
		ft_perror();
	put_images_to_window(game, game->wall, '1');
	put_images_to_window(game, game->ground, '0');
	put_images_to_window(game, game->player, 'P');
	put_images_to_window(game, game->coin, 'C');
	put_images_to_window(game, game->door, 'E');
	mlx_hook(game->win, 2, 0, hook, game);
	mlx_hook(game->win, 17, 0, game_over, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	int		count;
	t_game	game;
	int		fd;

	game.move = 1;
	game.av = av[1];
	count = count_line(game.av);
	if (ac != 2 || !compare(av[1]))
		ft_perror();
	fd = open(av[1], O_RDWR);
	if (fd < 3)
		ft_perror();
	game.map = get_map(fd, count);
	check_map(game.map);
	ft_free(game.map);
	close(fd);
	fd = open(av[1], O_RDWR);
	game.map = get_map(fd, count);
	game.width = ft_strlen(game.map[0]) * 60;
	game.height = count * 60;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.win = mlx_new_window(game.mlx, game.width, game.height, "SO LONG");
	full_window(&game);
	return (0);
}
