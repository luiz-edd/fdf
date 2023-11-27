/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:00:30 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/27 19:57:48 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	basic_movement_control(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->shift_y -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->shift_y += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->shift_x -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->shift_x += 10;
}

void	rotation_control(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_I))
		data->x_angle += 7;
	if (mlx_is_key_down(data->mlx, MLX_KEY_K))
		data->x_angle -= 7;
	if (mlx_is_key_down(data->mlx, MLX_KEY_J))
		data->y_angle += 7;
	if (mlx_is_key_down(data->mlx, MLX_KEY_L))
		data->y_angle -= 7;
	if (mlx_is_key_down(data->mlx, MLX_KEY_O))
		data->z_angle += 7;
	if (mlx_is_key_down(data->mlx, MLX_KEY_U))
		data->z_angle -= 7;
}

void	scale_control(t_fdf *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		data->z_scale *= 1.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		data->z_scale /= 1.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
		data->zoom *= 1.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
		data->zoom /= 1.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_0))
		up_camera(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_9))
		iso_camera(data);
}

void	deal_key(void *param)
{
	t_fdf	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	draw(data);
}
