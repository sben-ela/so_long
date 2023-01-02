/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:04:37 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/02 14:14:48 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"mlx.h"

typedef struct win
{
	void	*wall;
	void	*ground;
	void	*player;
	void	*coin;
	void	*door;
	void	*mlx;
	void	*win;
	char	*av;
	char	**map;
	int		width;
	int		height;
	int		d;
}t_game;

int		count_line_map(char **map);
int		check_rows(char **map);
int		check_columns(char **map);
void	ft_free(char **map);
void	handle_up(t_game *game);
void	handle_left(t_game *game);
void	handle_right(t_game *game);
void	handle_down(t_game *game);
int		check_exist(char **map, char c);
void	ft_putchar(char c, int fd);
void	full_window(t_game *win);
int		hook(int key_number, t_game *win);
void	put_images_to_window(t_game *game, void *img_data, char c);
char	*get_next_line(int fd);
char	**get_map(int fd, int count);
int		count_line(char *av);
void	ft_perror(void);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
int		*check_position(char **map, char c);
int		check_map(char **map);
#endif
