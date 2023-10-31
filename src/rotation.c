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

void	centralize(fdf *data, cordenates *aux)
{
	float	shift_x;
	float	shift_y;

	shift_y = (HEIGHT / 2) - ((data->height) * (data->zoom)) / 2;
	shift_x = (WIDTH / 2) - ((data->width) * (data->zoom)) / 2;
	aux->x += shift_x;
	aux->y += shift_y;
	aux->x1 += shift_x;
	aux->y1 += shift_y;
}

// void	deal_key(int key, void *param)
// {
// 	fdf	*data;

// 	data = param;
// 	printf("%d\n, key");
// 	if (key == 126)
// 		data->shift_y -= 10;
// 	if (key == 125)
// 		data->shift_y += 10;
// 	if (key == 123)
// 		data->shift_x -= 10;
// 	if (key == 126)
// 		data->shift_x += 10;
// 	// mlx_delete_image(data->mlx, data->image);
// 	draw(data);
// 	return (0);
// }

// void	deal_key(void *param)
// {
// 	fdf	*data;

// 	data = param;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
// 		data->shift_y -= 10;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
// 		data->shift_y += 10;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
// 		data->shift_x -= 10;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
// 		data->shift_x += 10;
// 	draw(data);
// }

void	deal_key(void *param)
{
	fdf	*data;

	// printf("test");
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->shift_x += 10;
		// mlx_delete_image(data->mlx, data->image);
		draw(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		printf("a\n");
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		printf("s\n");
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		printf("d\n");
	
}

void	move(fdf *data, cordenates *cord)
{
	cord->x += data->shift_x;
	cord->y += data->shift_y;
	cord->x1 += data->shift_x;
	cord->y1 += data->shift_y;
}
