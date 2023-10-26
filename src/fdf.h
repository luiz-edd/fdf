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
	int				width;
	int				height;
	int				**z_matrix;
	unsigned int	**color_matrix;
	int				zoom;

	mlx_t			*mlx;
	mlx_image_t		*image;

}					fdf;

typedef struct s_cordenates
{
	float			x;
	float			y;
	float			x1;
	float			y1;
	unsigned int	color;
}					cordenates;

//prototypes
int					read_file(char *file_name, fdf *data);
void				bresenham(cordenates *c, fdf *data);
void				draw(fdf *data);

// typedef struct mlx
// {
// 	void	*window;
// 	void	*context;
// 	int32_t	width;
// 	int32_t	height;
// 	double	delta_time;
// }			mlx_t;

#endif
