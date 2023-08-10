#include "fdf.h"
#include "libft.h"
#include<fcntl.h>

void	ft_map(char *argv, t_map *map)
{
	ft_map_checker(argv);
	ft_height(argv, map);
	ft_width(argv, map);
	ft_set_coords(argv, map);
}

void	ft_map_checker(char *map)
{
	int		fd;
	char	*line;
	
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_error("Read map error"));
	line = get_next_line(fd);
	while (line)
	{
		if (ft_isnumstr(line) == 0)
			return (ft_error("INVALID MAP"));
		else
		{
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
}
void	ft_height(char *argv, t_map *map)
{
	int 	height;
	int 	fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error("Read map error"));
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->height = height;
}

void	ft_width(char *argv, t_map *map)
{	
	int	i;
	int	fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_error("Read map error"));
	i = 0;
	map->width = (int *)malloc(sizeof(int) * map->height);
	while (i <=  map->height)
	{
		line = get_next_line(fd);	
		map->width[i++] = ft_spacecounter(line) + 1;
		free(line);
	}
	close(fd);
}

void	ft_set_coords(char *argv, t_map *map)
{
	char    *line;
	char    **coor;
	int     fd;
	int	x;
	int	y;
	
	map->coords = (int **)malloc(map->height * (sizeof(int *)));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
        	return (ft_error("Read map error"));
	x = -1;
	y = -1;
	while (++x <= map->height)
	{
		line = get_next_line(fd);	
		coor = ft_split(line, ' ');
		free(line);
		map->coords[x] = (int *)malloc(sizeof(int) * map->width[x]);
		while (++y <= map->width[x])
			map->coords[x][y] = ft_atoi(coor[y]);
		y = 0;
		ft_freesplit(coor, map->width[x]);
	}
	close(fd);
}
