#include "fdf.h"
#include "libft.h"

int ft_open(char *argv)
{
    int fd;
    char *mapfile;

    mapfile = ft_strjoin("./maps/", argv);
    fd = open(mapfile, O_RDONLY);
    free(mapfile);
    if (fd == -1)
        ft_error("OPEN ERROR\n");
    return (fd);
}

void ft_init(t_datamap **datamap)
{
    *datamap = malloc(sizeof(t_datamap));
    if (!*datamap)
        ft_error("Memory allocation failed\n");
    (*datamap)->height = 0;
    (*datamap)->width = NULL;
    (*datamap)->coors = NULL;
    (*datamap)->color = NULL;
}

void ft_print_map(t_datamap *datamap)
{
    int i = 0;
    while (i < datamap->height)
    {
        int j = 0;
        while (j < datamap->width[i])
        {
            printf("%d,%x  ", datamap->coors[i][j], datamap->color[i][j]);
            j++;
        }
        printf("\ntamaño linea%i:%i\n", i, datamap->width[i]);
        i++;
    }
     printf("\nnumero de lineas:%i\n", datamap->height);
}