#include "so_long_bonus.h"

int check_exist_c(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'C')
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

void handle_up(win *game)
{
    int x;
    int y;

    y = check_position(game->map, 'P')[0];
    x = check_position(game->map, 'P')[1];
    if(game->map[y - 1][x] == '1' )
        return ;
    if(game->map[y - 1][x] == 'E' || game->map[y - 1][x] == 'B')
    {
        if(check_exist_c(game->map) && game->map[y - 1][x] == 'E')
            return ;
        write(1, "GAME OVER", 9);
        exit(0);
    }
    game->move++;
    game->map[y][x] = '0';
    game->map[y - 1][x] = 'P';
}

void handle_left(win *game)
{
    int x;
    int y;

    y = check_position(game->map, 'P')[0];
    x = check_position(game->map, 'P')[1];
    if(game->map[y][x - 1] == '1')
        return ;
    if(game->map[y][x - 1] == 'E' || game->map[y][x - 1] == 'B')
    {
        if(check_exist_c(game->map) && game->map[y][x - 1] == 'E')
            return ;
        write(1, "GAME OVER", 9);
        exit(0);
    }
    game->move++;
    game->map[y][x] = '0';
    game->map[y][x - 1] = 'P';
}

void handle_right(win *game)
{
    int x;
    int y;

    y = check_position(game->map, 'P')[0];
    x = check_position(game->map, 'P')[1];
    if(game->map[y][x + 1] == '1')
        return ;
    if(game->map[y][x + 1] == 'E' || game->map[y][x + 1] == 'B')
    {
        if(check_exist_c(game->map) && game->map[y][x + 1] == 'E')
            return ;
        write(1, "GAME OVER", 9);
        exit(0);
    }
    game->move++;
    game->map[y][x] = '0';
    game->map[y][x + 1] = 'P';
}

void handle_down(win *game)
{
    int x;
    int y;

    y = check_position(game->map, 'P')[0];
    x = check_position(game->map, 'P')[1];
    if(game->map[y + 1][x] == '1')
        return ;
    if(game->map[y + 1][x] == 'E' || game->map[y + 1][x] == 'B')
    {
        if(check_exist_c(game->map) && game->map[y + 1][x] == 'E')
            return ;
        write(1, "GAME OVER", 9);
        exit(0);
    }
    game->move++;;
    game->map[y][x] = '0';
    game->map[y + 1][x] = 'P';
}