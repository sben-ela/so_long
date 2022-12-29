#include "so_long.h"

void    put_images_to_window(char **map, void *mlx, void *win, void *img_data, char c)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == c)
                mlx_put_image_to_window(mlx, win, img_data, 60 * j, i * 60);
            if(c == '0' && map[i][j] == 'C')
                mlx_put_image_to_window(mlx, win, img_data, 60 * j, i * 60);
            if(c == '0' && map[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, img_data, 60 * j, i * 60);
                if(c == '0' && map[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, img_data, 60 * j, i * 60);
            if(c == '0' && map[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, img_data, 60 * j, i * 60);
            j++;
        }
        i++;
    }
}

int check_pe(char **map)
{
    int *p = check_position(map, 'P');
    int *e = check_position(map, 'E');
    if(p[0] == e[0] && p[1] == e[1])
        return(0);
    return(1);
}

void handle_up(char **map)
{
    int x;
    int y;

    y = check_position(map, 'P')[0];
    x = check_position(map, 'P')[1];
    if(map[y - 1][x] == '1' )
        return ;
    map[y][x] = '0';
    map[y - 1][x] = 'P';
}
void handle_left(char **map)
{
    int x;
    int y;

    y = check_position(map, 'P')[0];
    x = check_position(map, 'P')[1];
    if(map[y][x - 1] == '1')
        return ;
    map[y][x] = '0';
    map[y][x - 1] = 'P';
}

void handle_right(char **map)
{
    int x;
    int y;

    y = check_position(map, 'P')[0];
    x = check_position(map, 'P')[1];
    if(map[y][x + 1] == '1')
        return ;
    map[y][x] = '0';
    map[y][x + 1] = 'P';
}

void handle_down(char **map)
{
    int x;
    int y;

    y = check_position(map, 'P')[0];
    x = check_position(map, 'P')[1];
    if(map[y + 1][x] == '1')
        return ;
    map[y][x] = '0';
    map[y + 1][x] = 'P';
}

int hook(int key_number, win *win)
{
    if(key_number == 53)
        exit(0);
    if(key_number == 13 || key_number == 126)
        handle_up(win->map);
    else if(key_number == 0 || key_number == 123)
        handle_left(win->map);
    else if(key_number == 1 || key_number == 125)
        handle_down(win->map);
    else if(key_number == 2 || key_number == 124)
        handle_right(win->map);
    mlx_clear_window(win->mlx, win->win);
    full_window(win);
    return(0);
}

void full_window(win *win)
{
    if(!check_position(win->map, 'C'))
        win->map[check_position(win->map, 'E')[0]][check_position(win->map, 'E')[1]] = 'Z';
    if(!check_position(win->map, 'E') && !check_position(win->map, 'Z'))
        exit(0);
    print_map(win->map);
    win->wall = mlx_xpm_file_to_image(win->mlx, "./img1.xpm", &win->width, &win->height);
    win->ground = mlx_xpm_file_to_image(win->mlx, "./img2.xpm", &win->width, &win->height);
    win->player = mlx_xpm_file_to_image(win->mlx, "player2.xpm", &win->width, &win->height);
    win->collectible = mlx_xpm_file_to_image(win->mlx, "./c.xpm", &win->width, &win->height);
    win->door = mlx_xpm_file_to_image(win->mlx, "./door.xpm", &win->width, &win->height);
    put_images_to_window(win->map, win->mlx, win->win, win->wall, '1');
    put_images_to_window(win->map, win->mlx, win->win, win->ground, '0');
    put_images_to_window(win->map, win->mlx, win->win, win->player, 'P');
    put_images_to_window(win->map, win->mlx, win->win, win->collectible, 'C');
    put_images_to_window(win->map, win->mlx, win->win, win->door, 'E');
    mlx_hook(win->win, 2, 0, hook, (void *)win);
    mlx_loop(win->mlx);   
}

int main(int ac, char **av)
{
    (void)ac;
    char **map;
    win win;
    int count = count_line();
    int fd = open(av[1], O_RDWR);
    map = get_map(fd, count);
    close(fd);
    check_map(map);
    win.av = av[1];
    win.map = map;
    win.width = ft_strlen(win.map[0]) * 60;
    win.height = count_line() * 60;
    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, ft_strlen(win.map[0]) * 60, count_line() * 60,  "My MLX Window");
    full_window(&win);
    //printf("%d", check_position(map, 'P')[1]);
    return 0;
}