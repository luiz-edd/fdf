#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# define WIDTH 256
# define HEIGHT 256

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**z_matrix;

}		fdf;

//prototypes
int		read_file(char *file_name, fdf *data);

// typedef struct mlx
// {
// 	void	*window;
// 	void	*context;
// 	int32_t	width;
// 	int32_t	height;
// 	double	delta_time;
// }			mlx_t;

#endif
