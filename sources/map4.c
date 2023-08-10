#include "fdf.h"


int ft_height_getter(char *argv)
{
    int fd;
    char *line;
    int height;
    
    fd = ft_open(argv);
    height = 0;
    line = get_next_line(fd);
    while (line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    
    return (height);
}

void    ft_dim_getter(char *argv, t_datamap **datamap)
{
    int auxheight;
    int *auxwidth;
    char *line;
    int fd;

    auxheight = ft_height_getter(argv);
    auxwidth = (int *)malloc(auxheight * sizeof(int));
    if (!auxwidth)
        ft_error("MALLOC");
    fd = ft_open(argv);
    line = get_next_line(fd);
    auxheight = 0;
    while (line)
    {
        auxwidth[auxheight++] = ft_segcount(line, ' ');
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    (*datamap)->height = auxheight;
    (*datamap)->width = auxwidth;
}

void ft_map_getter(char *argv, t_datamap **datamap)
{
    ft_dim_getter(argv, datamap);
}