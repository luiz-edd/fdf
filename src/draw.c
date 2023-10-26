/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/26 14:29:30 by leduard2         ###   ########.fr       */
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

void	get_zoom(cordenates *c, fdf *data)
{
	c->x *= data->zoom;
	c->y *= data->zoom;
	c->x1 *= data->zoom;
	c->y1 *= data->zoom;
}
// [3,5] [6,10]

void	bresenham(cordenates *c, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	get_zoom(c, data);
	x_step = (c->x1 - c->x);                  // 3
	y_step = (c->y1 - c->y);                  // 5
	max = maxval(sign(x_step), sign(y_step)); // 5
	x_step /= max;                            //
	y_step /= max;                            // -6/6 = -1;
	while ((int)(c->x - c->x1) || (int)(c->y - c->y1))
	{
		mlx_put_pixel(data->image, c->x, c->y, c->color);
		c->x += x_step;
		c->y += y_step;
	}
}

void	draw(fdf *data)
{
	cordenates	c;
	float		x;
	float		y;

	x = 0;
	y = 0;
	c.x = 0;
	c.y = 0;
	c.x1 = 0;
	c.y1 = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			c.x = x;
			c.y = y;
			c.x1 = x;
			c.y1 = y;
			if (x < data->width - 1)
			{
				c.x1 = x + 1;
				c.color = data->color_matrix[(int)y][(int)x];
				bresenham(&c, data);
			}
			c.x = x;
			c.y = y;
			c.x1 = x;
			c.y1 = y;
			if (y < data->height - 1)
			{
				c.y1 = y + 1;
				c.color = data->color_matrix[(int)y][(int)x];
				bresenham(&c, data);
			}
			x++;
		}
		y++;
	}
}
