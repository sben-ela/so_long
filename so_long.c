#include "so_long.h"

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
            j++;
        }
        i++;
    }
}

int hook(int key_number, win *game)
{
    if(key_number == 53)
        exit(0);
    if(key_number == 13 || key_number == 126)
    {
        handle_up(game);
        game->d = 3; 
    }
    else if(key_number == 0 || key_number == 123)
    {
        handle_left(game);
        game->d = 0;
    }
    else if(key_number == 1 || key_number == 125)
    {
        handle_down(game);
        game->d = 1;
    }
    else if(key_number == 2 || key_number == 124)
    {
        handle_right(game);
        game->d = 2;
    }
    full_window(game);
    return(0);
}

void full_window(win *game)
{
    static char *player[4] = {"images/player1.xpm", "images/player2.xpm",\
            "images/player3.xpm", "images/player4.xpm"};
    game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &game->width, &game->height);
    game->ground = mlx_xpm_file_to_image(game->mlx, "images/ground.xpm", &game->width, &game->height);
    game->player = mlx_xpm_file_to_image(game->mlx, player[game->d], &game->width, &game->height);
    game->coin = mlx_xpm_file_to_image(game->mlx, "images/coin.xpm", &game->width, &game->height);
    game->door = mlx_xpm_file_to_image(game->mlx, "images/door.xpm", &game->width, &game->height);
    put_images_to_window(game, game->wall, '1');
    put_images_to_window(game, game->ground, '0');
    put_images_to_window(game, game->player, 'P');
    put_images_to_window(game, game->coin, 'C');
    put_images_to_window(game, game->door, 'E');
    mlx_hook(game->win, 2, 0, hook, (void *)game);
    mlx_loop(game->mlx); 
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
    game.win = mlx_new_window(game.mlx, game.width, game.height,  "SO LONG");
    game.move = 0;
    full_window(&game);
    return 0;
}