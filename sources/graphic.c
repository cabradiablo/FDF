#include "fdf.h"

/*
int	close(int keycode, t_mlx **mlx)
{
    t_mlx *p_mlx;
    p_mlx = *mlx;
    (void)keycode;
    mlx_destroy_window(p_mlx->mlx, p_mlx->win);
	return (0);
}

void    mlx_launcher(t_mlx   **datamlx)
{
    t_mlx *p_mlx;

    p_mlx = *datamlx;
    p_mlx->mlx = mlx_init();
	p_mlx->win = mlx_new_window(p_mlx->mlx, 1920, 1080, "Hello world!");
    mlx_hook(p_mlx->win, 2, 1L<<0, close, &p_mlx);
	mlx_loop(p_mlx->mlx);
}
*/