#include "fdf.h"
#include "libft.h"

int ft_open(char *argv)
{
    int fd;
    char *mapfile;

    mapfile = ft_strjoin("../maps/", argv);
    fd = open(mapfile, O_RDONLY);
    if (fd == -1)
    {
        free(mapfile);
        ft_error("OPEN ERROR");
    }
    return (fd);
}