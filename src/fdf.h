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

// typedef struct s_cordenates
// {
// 	float			x;
// 	float			y;
// 	float			x1;
// 	float			y1;
// 	int				z;
// 	unsigned int	color;
// }					cordenates;

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
	int				is_isometric;
	point			**matrix;
	float			zoom;
	float			shift_x;
	float			shift_y;
	float			z_scale;
	float			angle;
	float			x_angle;
	float			y_angle;
	float			z_angle;

	mlx_t			*mlx;
	mlx_image_t		*image;

}					fdf;

//prototypes
int					read_file(char *file_name, fdf *data);
void				bresenham(fdf *data, point p1, point p2);
void				draw(fdf *data);
unsigned int		get_color(point *p1, point *p2);
void				centralize(fdf *data, point *p1, point *p2);
void				deal_key(void *param);
void				move(fdf *data, point *p1, point *p2);

// typedef struct mlx
// {
// 	void	*window;
// 	void	*context;
// 	int32_t	width;
// 	int32_t	height;
// 	double	delta_time;
// }			mlx_t;

#endif
