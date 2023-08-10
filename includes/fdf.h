#ifndef FDF_H

# define FDF_H

# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_camera
{
	t_projection		projection;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;


typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;


typedef struct	s_mlx 
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;


typedef	struct s_datamap
{
	int			height;
	int			*width;
	int			**coors;
	int			**color;
}				t_datamap;

typedef struct s_fdf
{
	t_mlx		*mlx;
	t_datamap	*datamap;
}				t_fdf;


//READ MAP AND PARSE    map.c
int		ft_open(char *argv);
void 	ft_colorandcoors_getter(char ***coors, t_datamap **datamap);
char    ***ft_parse_coors(char *argv, int height);
int		*ft_width_getter(char *argv, int height);
int		ft_height_getter(char *argv);
void    ft_map_getter(char *argv, t_datamap **datamap);

//ERROR EXIT  error.c

void    ft_error(char *msg);


#endif

/*
//READ MAP AND PARSE    map3.c
void	ft_colorandcoors_getter(char ***coors, t_datamap **datamap);
char    ***ft_parse_coors(char *argv, int height);
int		*ft_width_getter(char *argv, int height);
int		ft_height_getter(char *argv);
void    ft_map_getter(char *argv, t_datamap **datamap);


//READ MAP AND PARSE    map2.c
void	ft_map(char *argv, t_map *map);
void	ft_map_checker(char *argv);
void	ft_height(char *argv, t_map *map);
void	ft_width(char *argv, t_map *map);
void	ft_set_coords(char *argv, t_map *map);
*/