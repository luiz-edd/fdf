/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:54:00 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/30 17:53:41 by leduard2         ###   ########.fr       */
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

	i = 0;
	printf("width: %d\n", data->width);
	printf("heigh: %d\n", data->height);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%10u", data->matrix[i][j].color);
			j++;
		}
		printf("\n");
		// free(data->matrix[i]);
		i++;
	}
	// free(data->matrix);
	// free(data);
	return (0);
}

//print map and free
int	main(void)
{
	fdf	*data;

	// char *hex = "0xffffffff";
	// printf("%u",ft_atoi_base( ft_strchr(hex, 'x')+1, 16 )) ;
	// printf("%p", (ft_strchr("a", 'x')+1) );
	data = (fdf *)malloc(sizeof(fdf));
	if (data == NULL)
		return (2);
	data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!data->mlx)
		return (0); // ft_error();
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image || (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0))
		return (0); // ft_error();
	if (!read_file("test_maps/42.fdf", data))
		return (2);
	data->zoom = 40;
	draw(data);
	// bresenham(10,10,600,300, data);
	// mlx_loop_hook(data->mlx, , data->mlx);fd
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	print_map(data);
}
