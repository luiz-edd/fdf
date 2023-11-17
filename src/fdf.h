#ifndef FDF_H
# define FDF_H

# include "../lib/libft/src/libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# define WIDTH 1920
# define HEIGHT 1080
# define WHITE 0xffffffff
# define ISO_ANGLE 0.523599
# ifndef PI
#  define PI 3.141592653
# endif

typedef struct s_point
{
	float			x;
	float			y;
	int				z;
	unsigned int	color;
}					point;

typedef struct s_fdf
{
	int				width;
	int				height;
	point			**matrix;
	float			zoom;
	float			shift_x;
	float			shift_y;
	// int				z_scale;
	float			angle;
	float			x_angle;
	float			y_angle;
	float			z_angle;
	mlx_t			*mlx;
	mlx_image_t		*image;

}					fdf;

//read_file
int					read_file(char *file_name, fdf *data);

//draw
void				bresenham(fdf *data, point p1, point p2);
void				draw(fdf *data);

//positioning
void				get_zoom(fdf *data, point *p1, point *p2);
void				centralize(point *p1, point *p2);
void				deal_key(void *param);
void				move(fdf *data, point *p1, point *p2);
float				get_initial_zoom(fdf *data);

//rotation
void				rotate_x(fdf *data, point *p1);
void				rotate_y(fdf *data, point *p1);
void				rotate_z(fdf *data, point *p1);

//color
unsigned int		get_color(point *p1, point *p2);

#endif
