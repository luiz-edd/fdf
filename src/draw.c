/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.point                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:36 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/31 15:12:59 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_zoom(cordenates *aux, float zoom)
{
	aux->x *= zoom;
	aux->y *= zoom;
	aux->x1 *= zoom;
	aux->y1 *= zoom;
}
// [3,5] [6,10]

// void	make_3d(float *x, float *y, int z)
// {
// 	float	aux_x;
// 	float	aux_y;

// 	aux_x = *x;
// 	aux_y = *y;
// 	*x = (aux_x - aux_y) * cos(0.523599);
// 	*y = (aux_x + aux_y) * sin(0.523599) - z;
// }

void	make_3d(cordenates *aux, int z, int z1, fdf *data)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	x = aux->x;
	y = aux->y;
	x1 = aux->x1;
	y1 = aux->y1;
	aux->x = (x - y) * cos(data->angle);
	aux->y = (x + y) * sin(data->angle) - (z);
	aux->x1 = (x1 - y1) * cos(data->angle);
	aux->y1 = (x1 + y1) * sin(data->angle) - (z1);
}

void	bresenham(fdf *data, point *p1, float x1, float y1)
{
	float			x_step;
	float			y_step;
	int				max;
	unsigned int	color;
	cordenates		cord;

	cord.x = p1->x;
	cord.y = p1->y;
	cord.x1 = x1;
	cord.y1 = y1;
	//color
	color = get_color(p1, &data->matrix[(int)cord.y1][(int)cord.x1]);
	//3D
	make_3d(&cord, p1->z, data->matrix[(int)cord.y1][(int)cord.x1].z, data);
	//zoom
	get_zoom(&cord, data->zoom);
	//offset
	centralize(data, &cord);
	//move
	move(data, &cord);
	x_step = (cord.x1 - cord.x);
	y_step = (cord.y1 - cord.y);
	max = ft_maxval(ft_absolute(x_step), ft_absolute(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(cord.x - cord.x1) || (int)(cord.y - cord.y1))
	{
		if ((cord.x > 0 && cord.x < WIDTH) && (cord.y > 0 && cord.y < HEIGHT))
			mlx_put_pixel(data->image, cord.x, cord.y, color);
		cord.x += x_step;
		cord.y += y_step;
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