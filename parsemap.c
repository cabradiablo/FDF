#include "fdf.h"

void ft_colorandcoors_getter(char ***coors, t_datamap *datamap)
{
    int     **coors;
    int     **color;
    char    **aux;
    int     i;
    int     j;

    i = 0;
    j = 0;
    coors = (int **)malloc(datamap->height * sizeof(int));
    color = (int **)malloc(datamap->height * sizeof(int));
    while (i <= datamap->height)
    {
        aux = split(coors[i][j], ',');
        while ( j <= datamap-> width[i])
        {
            coors[i][j] = ft_atoi(aux[0]);
            if (aux[1])
                color[i][j] = ft_atoi_base(ft_strchar(aux[1], 'x'), "0123456789ABCDEF");
            else
                color[i][j] = 0;
            j++;
        }
        free(aux);
        i++;
    }
    datamap->coors = coors;
    datamap->color = color;
}

char    ***ft_parse_coors(char *argv, int height)
{
    int     fd;
    char    *line;
    int     **coors;

    coors = (char ***)malloc((height + 1) * (sizeof(char **)));
    height = 0;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        return (NULL);
    line = get_next_line(fd);
    while (line)
    {
        coors[height++] = ft_split(line, ' ');
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    coors[height + 1] = NULL;
    return (coors);
}
int *ft_width_getter(char *argv, int height)
{
    int     *width;
    int     fd;
    char    *line;
    int     i;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
        return (NULL);
    width = (int **)malloc(height * sizeof(int));
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        width[i++] = ft_segcount(line, ' ');
        free(line);
        line = get_next_line(fd);
    }
    close (fd);
    retuen (width);
}
int ft_height_getter(char *argv)
{
    int     fd;
    char    *line;
    int     height;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
        return (NULL);
    height = 0;
    line = get_next_line(fd);
    while (line)
    {
        line = get_next_line(fd);
        free(line);
        height++;
    }
    close(fd);
    return (height);
}
void    ft_map_getter(char *argv, t_datamap *datamap)
{
    char    ***coors;

    datamap->height = ft_height_getter(argv);
    datamap->width = ft_width_getter(argv, datamap->height);
    datamap->coors = ft_parse_map(argv, datamap->height);
    ft_colorandcoors_getter(coors, &datamap);
}