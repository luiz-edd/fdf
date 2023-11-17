/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:20:18 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/17 19:24:02 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	float			z;
	unsigned int	color;
}					t_point;

typedef struct s_fdf
{
	int				width;
	int				height;
	t_point			**matrix;
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

}					t_fdf;

//read_file
int					read_file(char *file_name, t_fdf *data);

//draw
void				bresenham(t_fdf *data, t_point p1, t_point p2);
void				draw(t_fdf *data);

//positioning
void				get_zoom(t_fdf *data, t_point *p1, t_point *p2);
void				centralize(t_point *p1, t_point *p2);
void				move(t_fdf *data, t_point *p1, t_point *p2);
void				up_camera(t_fdf *data);
void				iso_camera(t_fdf *data);

//rotation
void				rotate_x(t_fdf *data, t_point *p1);
void				rotate_y(t_fdf *data, t_point *p1);
void				rotate_z(t_fdf *data, t_point *p1);

//color
unsigned int		get_color(t_point *p1, t_point *p2);

//control
void				deal_key(void *param);

#endif
