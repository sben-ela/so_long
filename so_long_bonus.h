#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"


typedef struct position
{
    int ex;
    int ey;
    int px;
    int py;
}position;

typedef struct win
{
    int move;
    void *wall;
    void *ground;
    void *player;
    void *coin;
    void *door;
    void *door2;
    void *mlx;
    void *win;
    char *av;
    char **map;
    int width;
    int height;
    void* pacman;
    int d;
}win;

///utils
int count_line_map(char **map);
int count_line(char *av);
char **get_map(int fd, int count);
int check_rows(char **map);
int check_columns(char **map);
///moves
void handle_up(win *game);
void handle_left(win *game);
void handle_right(win *game);
void handle_down(win *game);
int check_exist(char **map, char c);
void	ft_putchar(char c, int fd);
void full_window(win *win);
int hook(int key_number, win *win);
void    put_images_to_window(win *game, void *img_data, char c);
char	*get_next_line(int fd);
int count_line(char *av);
void ft_perror(void);
int	ft_strncmp(char *s1, char *s2, int n);
char	*ft_strchr(const char *s, int c);
int	ft_strlen(const char *s);
int *check_position(char **map, char c);
int check_map(char **map);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_itoa(int n);
#endif
