#include "libft.h"

int	ft_spacecounter(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			count++;
		i++;
	}
	return (count);
}
