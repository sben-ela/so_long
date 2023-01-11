/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:27:41 by sben-ela          #+#    #+#             */
/*   Updated: 2023/01/05 19:47:30 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"mlx.h"

typedef struct game
{
	int		move;
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
	void	*pacman;
	int		d;
	char	*str;
	int		count;
}t_bgame;

void	handle_new_line(char **map);
int		check_exist_c(char **map);
int		hook(int key_number, t_bgame *game);
int		compare(char *map);
int		game_over(void);
void	ft_full_window(t_bgame *game);
void	ft_free(char **map);
int		count_line_map(char **map);
int		count_line(char *av);
char	**get_map(int fd, int count);
int		check_rows(char **map);
int		check_columns(char **map);
void	ft_handle_up(t_bgame *game);
void	ft_handle_left(t_bgame *game);
void	ft_handle_right(t_bgame *game);
void	ft_handle_down(t_bgame *game);
int		check_exist(char **map, char c);
void	ft_putchar(char c, int fd);
char	*get_next_line(int fd);
int		count_line(char *av);
void	ft_perror(void);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
int		*check_position(char **map, char c);
int		check_map(char **map);
char	*ft_itoa(int n);
#endif
