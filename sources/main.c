#include "fdf.h"
#include "libft.h"
/*
int	close_mlx(int keycode, t_mlx **mlx)
{
    t_mlx *p_mlx;
    p_mlx = *mlx;
    (void)keycode;
    mlx_destroy_window(p_mlx->mlx, p_mlx->win);
	return (0);
}
*/

int main(int argc, char **argv)
{
	t_datamap	*datamap;
	//t_mlx		*p_mlx;

	argv_chekcer(argc, argv);
	ft_init(&datamap);
	ft_map_getter(argv[1], &datamap);
	ft_print_map(datamap);
   /*
	ft_init_mlx(&p_mlx);
    p_mlx->mlx = mlx_init();
	p_mlx->win = mlx_new_window(p_mlx->mlx, 1920, 1080, "Hello world!");
    //mlx_hook(p_mlx->win, 2, 1L<<0, close_mlx, &p_mlx);
	mlx_loop(p_mlx->mlx);
	*/
	ft_free_map(datamap);
	return (0);
}
