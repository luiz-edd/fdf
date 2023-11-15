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

void	centralize(fdf *data, point *p1, point *p2)
{
	float	shift_x;
	float	shift_y;
	if(data){

	}
	shift_y = (HEIGHT / 2);
	shift_x = (WIDTH / 2);
	p1->x += shift_x;
	p1->y += shift_y;
	p2->x += shift_x;
	p2->y += shift_y;
}

void	deal_key(void *param)
{
	fdf	*data;

	// printf("test");
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->shift_y -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->shift_y += 10;
		
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->shift_x -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->shift_x += 10;


	if (mlx_is_key_down(data->mlx, MLX_KEY_I))
		data->x_angle += 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_K))
		data->x_angle -= 0.05;

	if (mlx_is_key_down(data->mlx, MLX_KEY_J))
		data->y_angle += 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_L))
		data->y_angle -= 0.05;
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_O))
		data->z_angle += 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_U))
		data->z_angle -= 0.05;
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
		data->zoom += 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
		data->zoom -= 1;
	
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	draw(data);
}

void	move(fdf *data, point *p1, point *p2)
{
	p1->x += data->shift_x;
	p1->y += data->shift_y;
	p2->x += data->shift_x;
	p2->y += data->shift_y;
}

