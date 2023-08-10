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
        ft_error("OPEN ERROR");
    return (fd);
}

void ft_init(t_datamap **datamap)
{
    *datamap = malloc(sizeof(t_datamap));
    if (!*datamap)
        ft_error("Memory allocation failed");

    (*datamap)->height = 0;
    (*datamap)->width = NULL;
    (*datamap)->coors = NULL;
    (*datamap)->color = NULL;
}

void ft_free(t_datamap *datamap)
{
    free(datamap->width);

    int i = 0;
    while (i < datamap->height)
    {
        free(datamap->coors[i]);
        i++;
    }
    free(datamap->coors);

    i = 0;
    while (i < datamap->height)
    {
        free(datamap->color[i]);
        i++;
    }
    free(datamap->color);

    free(datamap);
}
