#include "fdf.h"
#include "libft.h"

void    argv_chekcer(int argc, char **argv)
{
    char    *line;
    char    *ptr;
    int     fd;

    if (argc != 2)
		ft_error("INVALID ARGUMENTS\n");
    fd = ft_open(argv[1]);
    line = get_next_line(fd);
    while (line)
    {
        ptr = line;
        if (*ptr == '+' || *ptr == '-')
            ptr++;
        while (ft_isdigit(*ptr) == 1)
            ptr++;
        if (ft_strncmp(ptr, ",0x", 3) == 0)
            ptr += 3;
        while (ft_strchr("0123456789ABCDEF", *ptr) != NULL)
            ptr++;
        if (*ptr != ' ' && *ptr != '\0')
            ft_error("INVALID MAP SYNTAX\n");
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

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
        ft_error("MALLOC FAILED\n");
    (*datamap)->height = 0;
    (*datamap)->width = NULL;
    (*datamap)->coors = NULL;
    (*datamap)->color = NULL;
}
void ft_init_mlx(t_mlx **datamlx)
{
    *datamlx= malloc(sizeof(t_mlx));
    if (!*datamlx)
        ft_error("MALLOC FAILED\n");
    (*datamlx)->win = NULL;
    (*datamlx)->img = NULL;
    (*datamlx)->addr = NULL;
    (*datamlx)->mlx = NULL;
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