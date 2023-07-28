#include "fdf.h"

void    ft_init(t_fdf *fdf, t_datamap *datamap)
{
    ft_bzero(fdf, sizeof(t_fdf));
    ft_bzero(datamap, sizeof(datamap));
}