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
    void *wall;
    void *ground;
    void *player;
    void *collectible;
    void *door;
    void *door2;
    void *mlx;
    void *win;
    char *av;
    char **map;
    int width;
    int height;
}win;
void full_window(win *win);
int hook(int key_number, win *win);
void    put_images_to_window(char **map, void *mlx, void *win, void *img_data, char c);
void print_map(char **map);
char	*get_next_line(int fd);
char **get_map(int fd, int count);
int count_line(void);
void ft_perror(void);
char	*ft_strchr(const char *s, int c);
int	ft_strlen(const char *s);
int *check_position(char **map, char c);
int check_map(char **map);
#endif
