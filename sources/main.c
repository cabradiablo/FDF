#include "fdf.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_datamap *datamap;

	argv_chekcer(argc, argv);
	ft_init(&datamap);
	ft_map_getter(argv[1], &datamap);
	ft_print_map(datamap);
	ft_free_map(datamap);
	return (0);
}
