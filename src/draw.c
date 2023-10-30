/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/30 17:59:32 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	maxval(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	sign(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	get_zoom(float *x, float *y, float zoom)
{
	*x *= zoom;
	*y *= zoom;
}
// [3,5] [6,10]

void	make_3d(float *x, float *y, int z)
{
	float	aux_x;
	float	aux_y;

	aux_x = *x;
	aux_y = *y;
	*x = (aux_x - aux_y) * cos(0.523599);
	*y = (aux_x + aux_y) * sin(0.523599) - z;
}

void	shift(float *x, float *y, float *x1, float *y1)
{
	int	shift_x;
	int	shift_y;

	shift_x = 400;
	shift_y = 300;
	*x += shift_x;
	*y += shift_y;
	*x1 += shift_x;
	*y1 += shift_y;
}

void	bresenham(fdf *data, cordenates *cord, float x1, float y1)
{
	float			x_step;
	float			y_step;
	float			x;
	float			y;
	int				max;
	unsigned int	color;

	x = cord->x;
	y = cord->y;
	//color
	color = get_color(cord, &data->matrix[(int)y1][(int)x1]);
	//3D
	make_3d(&x, &y, cord->z);
	make_3d(&x1, &y1, data->matrix[(int)y1][(int)x1].z);
	//zoom
	get_zoom(&x, &y, data->zoom);
	get_zoom(&x1, &y1, data->zoom);
	//shift
	shift(&x, &y, &x1, &y1);
	x_step = (x1 - x);                        // 3
	y_step = (y1 - y);                        // 5
	max = maxval(sign(x_step), sign(y_step)); // 5
	x_step /= max;                            //
	y_step /= max;                            // -6/6 = -1;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
			mlx_put_pixel(data->image, x, y, color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(data, &data->matrix[(int)y][(int)x], x + 1, y);
			if (y < data->height - 1)
				bresenham(data, &data->matrix[(int)y][(int)x], x, y + 1);
			x++;
		}
		y++;
	}
}

// void	bresenham_y(float x, float y, fdf *data, unsigned int color)
// {
// 	float	x_step;
// 	float	y_step;
// 	float	x1;
// 	float	y1;
// 	int		max;

// 	x1 = x;
// 	y1 = y + 1;
// 	// print_cordinates(x, y, x1, y1);
// 	get_zoom(&x, &y, data->zoom);
// 	get_zoom(&x1, &y1, data->zoom);
// 	x_step = (x1 - x);                        // 3
// 	y_step = (y1 - y);                        // 5
// 	max = maxval(sign(x_step), sign(y_step)); // 5
// 	x_step /= max;                            //
// 	y_step /= max;                            // -6/6 = -1;
// 	while ((int)(x - x1) || (int)(y - y1))
// 	{
// 		mlx_put_pixel(data->image, x, y, color);
// 		x += x_step;
// 		y += y_step;
// 	}
// }

// unsigned int	get_color_y(fdf *data, float x, float y)
// {
// 	float			x1;
// 	float			y1;
// 	unsigned int	color1;
// 	unsigned int	color2;

// 	x1 = x;
// 	y1 = y + 1;
// 	color1 = data->color_matrix[(int)y][(int)x];
// 	color2 = data->color_matrix[(int)y1][(int)x1];
// 	if (data->has_color)
// 	{
// 		if (color1 != 0xffffffff)
// 			return (color1);
// 		if (color2 != 0xffffffff)
// 			return (color2);
// 		return (color1);
// 	}
// 	if (data->z_matrix[(int)y][(int)x] != 0
// 		|| data->z_matrix[(int)y1][(int)x1] != 0)
// 		return (0xffff00ff);
// 	return (color1);
// }