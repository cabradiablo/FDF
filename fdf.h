#ifndef FDF_H
# define FDF_H
# include "./Libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <mlx.h>

typedef struct	s_mlx 
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_fdf
{
	t_mlx		*mlx;
	t_datamap	*datamap;
}				t_fdf;

typedef	struct s_datamap
{
	int			height;
	int			*width;
	int			**coors;
	int			**color,
}				t_datamap;

typedef struct	s_2Dpixel
{
	int			x;
	int			y;
	int			pixelcolor;
}				t_2Dpixel;

typedef struct	s_Rvec
{
	float			x;
	float			y;
}				t_Rvec;

typedef struct	s_3Dpoint
{
	int			x;
	int			y;
	int			z;
}				t_3Dpoint;


#endif