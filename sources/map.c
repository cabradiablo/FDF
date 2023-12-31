#include "fdf.h"
#include "libft.h"

void ft_colorandcoors_getter(char ***parsecoors, t_datamap **datamap)
{
    int     **aux_coors;
    int     **aux_color;
    char    **aux;
    int     i;
    int     j;

    aux_coors = (int **)malloc((*datamap)->height * sizeof(int*));
    aux_color = (int **)malloc((*datamap)->height * sizeof(int*));
    i = 0;
    while (i < (*datamap)->height)
    {
        j = 0;
        aux_coors[i] = (int *)malloc((*datamap)->width[i] * sizeof(int));
        aux_color[i] = (int *)malloc((*datamap)->width[i] * sizeof(int));
        while ( j < (*datamap)->width[i])
        {
            aux = ft_split(parsecoors[i][j], ',');
            aux_coors[i][j] = ft_atoi(aux[0]);
            aux_color[i][j++] = ft_atoi_base(aux[1], "0123456789ABCDEF");
            ft_free_2Dmatrix(aux, 2);
        }
        i++;
    }
    (*datamap)->coors = aux_coors;
    (*datamap)->color = aux_color;
}

char    ***ft_parse_coors(char *argv, int height)
{
    int     fd;
    char    *line;
    char    ***parsecoors;

    fd = ft_open(argv);
    parsecoors = (char ***)malloc((height + 1) * (sizeof(char **)));
    if (!parsecoors)
        ft_error("MALLOC\n");
    height = 0;
    if (fd == -1)
        return (NULL);
    line = get_next_line(fd);
    while (line)
    {
        parsecoors[height++] = ft_split(line, ' ');
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    parsecoors[height] = NULL;
    return (parsecoors);
}
int *ft_width_getter(char *argv, int height)
{
    int     *width;
    int     fd;
    char    *line;
    int     i;

    fd = ft_open(argv);
    width = (int *)malloc(height * sizeof(int));
    if (!width)
        ft_error("MALLOC\n");
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        width[i++] = ft_segcount(line, ' ');
        free(line);
        line = get_next_line(fd);
    }
    close (fd);
    return (width);
}
int ft_height_getter(char *argv)
{
    int fd;
    char *line;
    int height;
    
    fd = ft_open(argv);
    height = 0;
    line = get_next_line(fd);
    if (!line)
        ft_error("EMPTY MAP\n");
    while (line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}
void    ft_map_getter(char *argv, t_datamap **datamap)
{
    char    ***parsecoors;

    (*datamap)->height = ft_height_getter(argv);
    (*datamap)->width = ft_width_getter(argv, (*datamap)->height);
    parsecoors = ft_parse_coors(argv, (*datamap)->height);
    ft_colorandcoors_getter(parsecoors, datamap);
    ft_free_3Dmatrix(parsecoors, (*datamap)->height, (*datamap)->width);
}