/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:19:03 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/21 18:07:59 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_z(t_fdf *data, t_point *p1, t_point *p2)
{
	if (p1->z != 0)
		p1->z *= data->z_scale;
	if (p2->z != 0)
		p2->z *= data->z_scale;
}

void	set_param(t_fdf *data, t_point *p1, t_point *p2)
{
	get_zoom(data, p1, p2);
	get_z(data, p1, p2);
	rotate_z(data, p1);
	rotate_z(data, p2);
	rotate_x(data, p1);
	rotate_x(data, p2);
	rotate_y(data, p1);
	rotate_y(data, p2);
	centralize(p1, p2);
	move(data, p1, p2);
}

void	draw_line(t_fdf *data, t_point p1, t_point p2)
{
	float			x_step;
	float			y_step;
	int				max;
	unsigned int	color;

	color = get_color(&p1, &p2);
	set_param(data, &p1, &p2);
	x_step = (p2.x - p1.x);
	y_step = (p2.y - p1.y);
	max = ft_maxval(ft_absolute(x_step), ft_absolute(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		if ((p1.x > 0 && p1.x < WIDTH) && (p1.y > 0 && p1.y < HEIGHT))
			mlx_put_pixel(data->image, p1.x, p1.y, color);
		p1.x += x_step;
		p1.y += y_step;
	}
}

void	draw(t_fdf *data)
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
				draw_line(data, data->matrix[(int)y][(int)x],
					data->matrix[(int)y][(int)x + 1]);
			if (y < data->height - 1)
				draw_line(data, data->matrix[(int)y][(int)x],
					data->matrix[(int)y + 1][(int)x]);
			x++;
		}
		y++;
	}
}
