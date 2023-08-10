#include "fdf.h"
#include <unistd.h>

void    ft_error(char *msg)
{
   	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(2, &msg[i], 1);
		i++;
	}
    exit(1);
}