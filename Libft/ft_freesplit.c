#include "libft.h"

int	ft_freesplit(char **matrix, int row)
{
	if (!matrix[row])
	{
		while (row--)
			free(matrix[row]);
		free(matrix);
		return (1);
	}
	return (0);
}


