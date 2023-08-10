#include "fdf.h"
#include "../includes/fdf.h"
#include "../Libft/libft.h"

int main(int argc, char **argv)
{
	t_datamap *datamap;
	if (argc != 2 || !*argv[1])
		ft_error("INVALID ARGUMENTS");
	ft_map_getter(argv[1], &datamap);
	return (0);
}
