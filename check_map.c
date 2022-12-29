#include "so_long.h"

void print_map(char **map)
{
    int i = 0;
    int j = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            printf("%c ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
int count_line(void)
{
    int i;
    int fd;

    i = 0;
    fd = open("map.ber", O_RDWR);
    while(get_next_line(fd))
        i++;
    close(fd);
    return(i);
}

char **get_map(int fd, int count)
{
    char **map = malloc(sizeof(char *) * count + 1);
    int i;

    i = 0;
    while(i < count)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    i --;
    if(!ft_strchr(map[i], '\n'))
         map[i][ft_strlen(map[i])] = '\n';
    map[i + 1] = NULL;
    return(map);
}

int check_rows(char **map)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(map[i][j])
    {
        if(map[i][j] != '1')
            return(0);
        j++;
    }
    j = 0;
    i = count_line() - 1;
    while(map[i][j])
    {
        if(map[i][j] != '1')
            return(0);
        j++;
    }
    return(1);
}

int check_columns(char **map)
{
    int i;
    int size;

    i = 0;
    size = ft_strlen(map[i]);
    if(size <= count_line())
        return(0);
    while(map[i])
    {
        if(map[i][0] != '1' || map[i][size - 1] != '1')
           return(0);
        i++;
    }
    return(1);
}

int check_cpe(char **map, char c)
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
            if(map[i][j] != '1')
                ft_perror();
            j++;
        }
        i++;
    }
}

void    floud(char **map, int i, int j)
{
    if (i <= 0 || i >= count_line() - 1 || j <= 0 || j >= ft_strlen(map[0]) - 1 || map[i][j] == '1')
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
    while( ++i < count_line())
        map[i][ft_strlen(map[i]) - 1] = '\0';
    if(!check_columns(map) || !check_rows(map) || !check_cpe(map, 'E') || !check_cpe(map, 'P') || !check_cpe(map, 'C'))
        ft_perror();
    i = check_position(map, 'P')[0];
    j = check_position(map, 'P')[1];
    // floud(map , i, j);
    // error(map);
    return(1);
}
