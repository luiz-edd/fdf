/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/24 15:51:23 by leduard2         ###   ########.fr       */
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

void	bresenham(float x, float y, float x1, float y1, fdf *data) // [3,5] [6, 10]
{
	float x_step;
	float y_step;
	int max;

	x_step = (x1 - x);                        // 3
	y_step = (y1 - y);                        // 5
	max = maxval(sign(x_step), sign(y_step)); // 5

	x_step /= max; // 
	y_step /= max; // -6/6 = -1;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(data->image, x, y, 0xffffffff);
		x += x_step;
		y += y_step;
	}
}