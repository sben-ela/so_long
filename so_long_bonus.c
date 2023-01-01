#include "so_long_bonus.h"


void    put_images_to_window(win *game, void *img_data, char c)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == c)
                mlx_put_image_to_window(game->mlx, game->win, img_data, 60 * j, i * 60);
            if(c == '0' && game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, img_data, 60 * j, i * 60);
            else if(c == '0' && game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, img_data, 60 * j, i * 60);
            else if(c == '0' && game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, img_data, 60 * j, i * 60);
            else if(c == '0' && game->map[i][j] == 'B')
                mlx_put_image_to_window(game->mlx, game->win, img_data, 60 * j, i * 60);
            j++;
        }
        i++;
    }
}

int imo(win *game)
{
    static int i;

    if (i < 40)
    {
        
       game->pacman =  mlx_xpm_file_to_image(game->mlx, "images/pacman1.xpm", &game->width, &game->height);   
        i = i + 1;
    }
    if (i  >= 40)
    {
       game->pacman =  mlx_xpm_file_to_image(game->mlx, "images/pacman2.xpm", &game->width, &game->height);
        i = i + 1;
    }
    if(i == 80)
        i = 0;
    put_images_to_window(game, game->pacman,  'B');
    return 0;
}

int hook(int key_number, win *win)
{
    if(key_number == 53)
        exit(0);
    if(key_number == 13 || key_number == 126)
    {
        handle_up(win);
        win->d = 3;
    }
    else if(key_number == 0 || key_number == 123)
    {
        handle_left(win);
        win->d = 0;
    }
    else if(key_number == 1 || key_number == 125)
    {
        handle_down(win);
        win->d = 1;
    }
    else if(key_number == 2 || key_number == 124)
    {
        handle_right(win);
        win->d = 2;
    }
    full_window(win);
    return(0);
}

void full_window(win *win)
{
    char *player[4] = {"images/player1.xpm", "images/player2.xpm", "images/player3.xpm", "images/player4.xpm"};
    win->wall = mlx_xpm_file_to_image(win->mlx, "images/wall.xpm", &win->width, &win->height);
    win->ground = mlx_xpm_file_to_image(win->mlx, "images/ground.xpm", &win->width, &win->height);
    win->player = mlx_xpm_file_to_image(win->mlx, player[win->d], &win->width, &win->height);
    win->coin = mlx_xpm_file_to_image(win->mlx, "images/coin.xpm", &win->width, &win->height);
    win->door = mlx_xpm_file_to_image(win->mlx, "images/door.xpm", &win->width, &win->height);
    put_images_to_window(win, win->wall, '1');
    put_images_to_window(win, win->ground, '0');
    put_images_to_window(win, win->player, 'P');
    put_images_to_window(win, win->coin, 'C');
    put_images_to_window(win, win->door, 'E');
    mlx_string_put(win->mlx, win->win, 0, 10, 0xFFB100, "moves : ");
    mlx_string_put(win->mlx, win->win, 70, 10, 0xFFB100, ft_itoa(win->move));
    mlx_loop_hook(win->mlx, imo, win);   
    mlx_hook(win->win, 2, 0, hook, (void *)win);
    mlx_loop(win->mlx); 
}

int main(int ac, char **av)
{
    int count;
    win game;
    int fd;

    game.av = av[1];
    count = count_line(game.av);
    if(ac != 2)
        ft_perror();
    fd = open(av[1], O_RDWR);
    if(fd < 3)
        ft_perror();
    check_map(get_map(fd, count));
    close(fd);
    fd = open(av[1], O_RDWR);
    game.map = get_map(fd, count);
    game.width = ft_strlen(game.map[0]) * 60;
    game.height = count * 60;
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.width, game.height,  "My MLX Window");
    game.move = 0;
    full_window(&game);
    return 0;
}