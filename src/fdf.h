#ifndef FDF_H
# define FDF_H

# include "../lib/libft/src/libft.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;

	mlx_t		*mlx;
	mlx_image_t	*image;

}				fdf;

//prototypes
int				read_file(char *file_name, fdf *data);
void			bresenham(float x, float x1, float y, float y1, fdf *data);

// typedef struct mlx
// {
// 	void	*window;
// 	void	*context;
// 	int32_t	width;
// 	int32_t	height;
// 	double	delta_time;
// }			mlx_t;

#endif
