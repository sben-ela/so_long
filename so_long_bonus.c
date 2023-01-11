/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:32:20 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/05 20:53:44 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_images_to_window(t_bgame *game, void *img_data, char c)
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
				mlx_put_image_to_window(game->mlx, \
					game->win, img_data, 60 * j, i * 60);
			if (c == '0' && game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, \
					game->win, img_data, 60 * j, i * 60);
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

int	pacman(t_bgame *game)
{
	static int	i;

	if (i < 40)
	{
		game->pacman = mlx_xpm_file_to_image(game->mlx, "textures/pacman1.xpm", \
			&game->width, &game->height);
		i = i + 1;
	}
	if (i >= 40)
	{
		game->pacman = mlx_xpm_file_to_image(game->mlx, "textures/pacman2.xpm", \
				&game->width, &game->height);
		i = i + 1;
	}
	if (i >= 80)
		i = 0;
	put_images_to_window(game, game->pacman, 'B');
	return (0);
}

void	full_window2(t_bgame *game)
{
	put_images_to_window(game, game->wall, '1');
	put_images_to_window(game, game->ground, '0');
	put_images_to_window(game, game->player, 'P');
	put_images_to_window(game, game->coin, 'C');
	put_images_to_window(game, game->door, 'E');
	mlx_string_put(game->mlx, game->win, 0, 10, 0xFFB100, "moves : ");
	game->str = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->win, 70, 10, 0xFFB100, game->str);
	free(game->str);
	mlx_loop_hook(game->mlx, pacman, game);
	mlx_hook(game->win, 2, 0, hook, game);
	mlx_hook(game->win, 17, 0, game_over, game);
	mlx_loop(game->mlx);
}

void	ft_full_window(t_bgame *game)
{
	static char	*player[4] = {"textures/player1.xpm", "textures/player2.xpm", \
		"textures/player3.xpm", "textures/player4.xpm"};

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", \
			&game->width, &game->height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm", \
			&game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx, player[game->d], \
			&game->width, &game->height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", \
			&game->width, &game->height);
	if (check_exist_c(game->map))
		game->door = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm", \
				&game->width, &game->height);
	else
		game->door = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", \
				&game->width, &game->height);
	if (!game->wall || !game->ground || !game->player
		|| !game->coin || !game->door)
		ft_perror();
	full_window2(game);
}

int	main(int ac, char **av)
{
	t_bgame	game;
	int		fd;

	game.av = av[1];
	game.count = count_line(game.av);
	if (ac != 2 || !compare(av[1]))
		ft_perror();
	fd = open(av[1], O_RDWR);
	if (fd < 3)
		ft_perror();
	game.map = get_map(fd, game.count);
	check_map(game.map);
	ft_free(game.map);
	close(fd);
	fd = open(av[1], O_RDWR);
	game.map = get_map(fd, game.count);
	handle_new_line(game.map);
	game.width = ft_strlen(game.map[0]) * 60;
	game.height = game.count * 60;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width, game.height, "SO LONG");
	game.move = 0;
	ft_full_window(&game);
	return (0);
}
