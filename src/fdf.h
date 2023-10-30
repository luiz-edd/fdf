#ifndef FDF_H
# define FDF_H

# include "../lib/libft/src/libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 1000
# define WHITE 0xffffffff

typedef struct s_cordenates
{
	float			x;
	float			y;
	int				z;
	unsigned int	color;
}					cordenates;

typedef struct s_fdf
{
	int				width;
	int				height;
	cordenates		**matrix;
	int				zoom;

	mlx_t			*mlx;
	mlx_image_t		*image;

}					fdf;

//prototypes
int					read_file(char *file_name, fdf *data);
void				bresenham_y(float x, float y, fdf *data,
						unsigned int color);
void				bresenham_x(float x, float y, fdf *data,
						unsigned int color);
void				draw(fdf *data);
unsigned int		get_color(cordenates *cord, cordenates *cord1);

// typedef struct mlx
// {
// 	void	*window;
// 	void	*context;
// 	int32_t	width;
// 	int32_t	height;
// 	double	delta_time;
// }			mlx_t;

#endif
