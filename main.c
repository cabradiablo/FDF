#include "fdf.h"

//main para implementacion de parseo de mapa
int	main(int argc, char **argv)
{
    t_fdf       fdf;
    t_datamap   datamap;

    ft_bzero(&fdf, sizeof(t_fdf));
    ft_bzero(&datamap, sizeof(datamap));
    ft_map_getter(argv[1], &datamap);
}