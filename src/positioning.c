/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:02:16 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/17 19:24:55 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	up_camera(t_fdf *data)
{
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
}

void	iso_camera(t_fdf *data)
{
	data->x_angle = 54.7;
	data->y_angle = 0;
	data->z_angle = -45;
}

void	get_zoom(t_fdf *data, t_point *p1, t_point *p2)
{
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p1->z *= data->zoom;
	p2->x *= data->zoom;
	p2->y *= data->zoom;
	p2->z *= data->zoom;
}

void	move(t_fdf *data, t_point *p1, t_point *p2)
{
	p1->x += data->shift_x;
	p1->y += data->shift_y;
	p2->x += data->shift_x;
	p2->y += data->shift_y;
}

void	centralize(t_point *p1, t_point *p2)
{
	float	shift_x;
	float	shift_y;

	shift_y = (HEIGHT / 2);
	shift_x = (WIDTH / 2);
	p1->x += shift_x;
	p1->y += shift_y;
	p2->x += shift_x;
	p2->y += shift_y;
}
