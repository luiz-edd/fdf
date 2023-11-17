/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.point                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:01:11 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/31 15:24:06 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	rotate_x(fdf *data, point *p1)
{
	float	previous_y;

	previous_y = p1->y;
	p1->y = (previous_y * cos(data->x_angle * PI / 180 )) - (p1->z * sin(data->x_angle * PI / 180));
	p1->z = (previous_y * sin(data->x_angle * PI / 180)) + (p1->z * cos(data->x_angle * PI / 180));
}

void	rotate_y(fdf *data, point *p1)
{
	float	previous_x;

	previous_x = p1->x;
	p1->x = previous_x * cos(data->y_angle * PI / 180) + p1->z * sin(data->y_angle * PI / 180);
	p1->z = -previous_x * sin(data->y_angle * PI / 180) + p1->z * cos(data->y_angle * PI / 180);
}

void	rotate_z(fdf *data, point *p1)
{
	float	previous_x;
	float	previous_y;

	previous_x = p1->x;
	previous_y = p1->y;
	p1->x = previous_x * cos(data->z_angle * PI / 180) - previous_y * sin(data->z_angle * PI / 180);
	p1->y = previous_x * sin(data->z_angle * PI / 180) + previous_y * cos(data->z_angle * PI / 180);
}


