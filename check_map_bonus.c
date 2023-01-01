#include "so_long.h"


int handle_collectble_behind_exit(char **map)
{
    int x = check_position(map, 'E')[1];
    int y = check_position(map, 'E')[0];
    if(map[y][x + 1] == 'C')
    {
        x = x + 1;
        if(map[y][x + 1]  == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
            return(0);
    }
    else if(map[y][x - 1] == 'C')
    {
        x = x - 1;
        if(map[y][x - 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
            return(0); 
    }
    else if(map[y - 1][x] == 'C')
    {
        y = y - 1;
        if(map[y - 1][x] == '1' && map[y][x - 1] == '1' && map[y][x + 1] == '1')
            return(0);
    }
    else if(map[y + 1][x] == 'C')
    {
        y = y + 1;
        if(map[y + 1][x] == '1' && map[y][x - 1] == '1' && map[y][x + 1] == '1')
            return(0);
    }
    return(1);
}

int handle_c_between_walls(char **map)
{
    int x = check_position(map, 'C')[1];
    int y = check_position(map, 'C')[0];

    if(map[y][x - 1] == '1' && map[y][x + 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1')
        exit(0);
    map[x][y] = '0';
    handle_c_between_walls(map);
    return(1);
}

int check_exist(char **map, char c)
{
    int i;
    int j;
    int n;

    i = 0;
    n = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'B' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
                ft_perror();
            if(map[i][j] == c)
                n++;
            j++;
        }
        i++;
    }
    if(n >= 1 && c == 'C')
        return(1);
    if(n == 1)
        return(1);
    else
        return(0);
}

int *check_position(char **map, char c)
{
    int i;
    int j;
    int *tab;

    tab = malloc(2 * sizeof(int));
    i = 0;
    j = 0;

    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == c)
            {
                tab[0] = i;
                tab[1] = j;
                return(tab);
            }
            j++;
        }
        i++;
    }
    return(0);
}

void error(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] != '1' && map[i][j] != '0')
                ft_perror();
            j++;
        }
        i++;
    }
}

void    floud(char **map, int i, int j)
{
    if (i <= 0 || i >= count_line_map(map) - 1 || j <= 0 || j >= ft_strlen(map[0]) - 1 || map[i][j] == '1')
        return ;
    else
        map[i][j] = '1';
    floud(map, i + 1, j);
    floud(map, i - 1, j);
    floud(map, i, j + 1);
    floud(map, i, j - 1);
}

int check_map(char **map)
{
    int i;
    int j;
    i = -1;
    while( ++i < count_line_map(map))
    {
        if(map[i][ft_strlen(map[i]) - 1] != '\n')
            break;
        map[i][ft_strlen(map[i]) - 1] = '\0';
    }
  if(!check_columns(map) || !check_rows(map) || !check_exist(map, 'E') || !check_exist(map, 'P') || !check_exist(map, 'C'))
        ft_perror();
    if(!handle_collectble_behind_exit(map))
        ft_perror();
    i = check_position(map, 'P')[0];
    j = check_position(map, 'P')[1];
    floud(map , i, j);
    error(map);
    return(1);
}
