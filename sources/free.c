#include "fdf.h"

void    ft_free_2Dmatrix(char **matrix, int height)
{
    int         i;

    i = 0;
    while (i < height)
        free(matrix[i++]);
    free(matrix);
}
void    ft_free_3Dmatrix(char ***matrix, int height, int *width)
{
    int         i;
    int         j;
    i = 0;
    while  (i < height)
    {
        j = 0;
        while (j < width[i])
            free(matrix[i][j++]);
        free(matrix[i++]);
    }
    free(matrix);
}
void ft_free_map(t_datamap *datamap)
{

    int i = 0;
    while (i < datamap->height)
    {
        free(datamap->coors[i]);
        free(datamap->color[i]);
        i++;
    }
    free(datamap->width);
    free(datamap->coors);
    free(datamap->color);
    free(datamap);
}