#include "libft.h"
#include <stdio.h>

int	ft_isnumstr(char *s)
{
	if (s[0] == ' ')
		return (0);
	while (*s != '\0')
	{
		if ((ft_isdigit(*s)) == 1)
		{
			if ((*(s + 1) == ' ' || (ft_isdigit(*(s + 1)) == 1) || *(s + 1) == '\n' || *(s + 1) == '\0'))
				return (ft_isnumstr(s + 1));
		}
		else if (*s == ' ')
		{	
			if (((ft_isdigit(*(s + 1))) == 1 || *(s + 1) == '-'))
				return (ft_isnumstr(s + 1));
		}
		else if (*s == '-')
		{
			if ((ft_isdigit(*(s + 1))) == 1)
				return (ft_isnumstr(s + 1));
		}
		else if(*s == '\n')
		{
			if (*(s + 1) == '-' || (ft_isdigit(*(s + 1))) == 1)
				return (ft_isnumstr(s + 1));
		}
		else
			return (0);
		return (1);
	}
	return (1);
}
