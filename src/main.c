/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:54:00 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/25 15:06:17 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	print_map(fdf *data)
{
	int	i;
	int	j;

	if (!read_file("test_maps/42.fdf", data))
	{
		free(data);
		return (2);
	}
	i = 0;
	printf("width: %d\n", data->width);
	printf("heigh: %d\n", data->height);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			printf("%3d", data->z_matrix[i][j++]);
		printf("\n");
		i++;
		// free(data->z_matrix[i++]);
	}
	// free(data->z_matrix);
	// free(data);
	return (0);
}



//print map and free
int	main(void)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	if (data == NULL)
		return (2);
	data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!data->mlx)
		return (0); // ft_error();
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image || (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0))
		return (0); // ft_error();
	// print_map_free(data);
	read_file("test_maps/42.fdf", data);
	data->zoom = 30;
	draw(data);
	// bresenham(10,10,600,300, data);
	// mlx_loop_hook(data->mlx, , data->mlx);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	print_map(data);
}
