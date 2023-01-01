#include "so_long.h"

int count_line_map(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
            j++;
        i++;
    }
    return(i);
}

int count_line(char *av)
{
    int i;
    int fd;

    i = 0;
    fd = open(av, O_RDWR);
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
    i = count_line_map(map) - 1;
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
    if(size <= count_line_map(map))
        return(0);
    while(map[i])
    {
        if(map[i][0] != '1' || map[i][size - 1] != '1')
           return(0);
        i++;
    }
    return(1);
}