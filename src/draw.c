/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/25 18:57:47 by leduard2         ###   ########.fr       */
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

void	get_zoom(float *x, float *y, float *x1, float *y1, fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}
// [3,5] [6,10]

void	bresenham(float x, float y, float x1, float y1, fdf *data, int color)
{
	float	x_step;
	float	y_step;
	int		max;

	get_zoom(&x, &y, &x1, &y1, data);
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

void	draw(fdf *data)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->color_matrix[y][x] == 0)
				data->color_matrix[y][x] = 4294967295;
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data, data->color_matrix[y][x]);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data, data->color_matrix[y][x]);
			x++;
		}
		y++;
	}
}