/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/23 14:45:41 by leduard2         ###   ########.fr       */
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

void	draw(float x, float x1, float y, float y1) // [1,2] [3, 8]
{
	float x_step;
	float y_step;
	int max;
	mlx_t *mlx;
	mlx_image_t *img;

	x_step = (x - x1);                        // -2
	y_step = (y - y1);                        // -6
	max = maxval(sign(x_step), sign(y_step)); // 6

	x_step /= max;                         // -2/6 = -0.33
	y_step /= max;                         // -6/6 = -1;
	while ((int)(x - x1) || (int)(y - y1)) //try with &&
	{
		img = mlx_new_image(mlx, 256, 256);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_error();
		mlx_put_pixel(img, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}