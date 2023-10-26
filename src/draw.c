/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/26 18:34:58 by leduard2         ###   ########.fr       */
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

void	get_zoom(float *x, float *y, int zoom)
{
	*x *= zoom;
	*y *= zoom;
}
// [3,5] [6,10]

void	bresenham_x(float x, float y, fdf *data, unsigned int color)
{
	float	x_step;
	float	y_step;
	float	x1;
	float	y1;
	int		max;

	x1 = x + 1;
	y1 = y;
	get_zoom(&x, &y, data->zoom);
	get_zoom(&x1, &y1, data->zoom);
	x_step = (x1 - x);                        // 3
	y_step = (y1 - y);                        // 5
	max = maxval(sign(x_step), sign(y_step)); // 5
	x_step /= max;                            //
	y_step /= max;                            // -6/6 = -1;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(data->image, x, y, color);
		x += x_step;
		y += y_step;
	}
}
void	bresenham_y(float x, float y, fdf *data, unsigned int color)
{
	float	x_step;
	float	y_step;
	float	x1;
	float	y1;
	int		max;

	x1 = x;
	y1 = y + 1;
	get_zoom(&x, &y, data->zoom);
	get_zoom(&x1, &y1, data->zoom);
	x_step = (x1 - x);                        // 3
	y_step = (y1 - y);                        // 5
	max = maxval(sign(x_step), sign(y_step)); // 5
	x_step /= max;                            //
	y_step /= max;                            // -6/6 = -1;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(data->image, x, y, color);
		x += x_step;
		y += y_step;
	}
}

unsigned int	get_color_x(fdf *data, float x, float y)
{
	float			x1;
	float			y1;
	unsigned int	color1;
	unsigned int	color2;

	x1 = x + 1;
	y1 = y;
	color1 = data->color_matrix[(int)y][(int)x];
	color2 = data->color_matrix[(int)y1][(int)x1];
	if (data->has_color)
	{
		if (color1 = !0xffffffff)
			return (color1);
	}
	return (data->color_matrix[(int)y][(int)x]);
	if (data->z_matrix[(int)y][(int)x] > 0)
		return (0xff0000ff);
	return (data->color_matrix[(int)y][(int)x]);
}

unsigned int	get_color_y(fdf *data, float x, float y)
{
	float	x1;
	float	y1;

	x1 = x;
	y1 = y + 1;
	if (data->has_color)
		return (data->color_matrix[(int)y][(int)x]);
	if (data->z_matrix[(int)y][(int)x] > 0)
		return (0xff0000ff);
	return (data->color_matrix[(int)y][(int)x]);
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
				bresenham_x(x, y, data, get_color_x(data, x, y));
			if (y < data->height - 1)
				bresenham_y(x, y, data, get_color(data, x, y));
			x++;
		}
		y++;
	}
}
