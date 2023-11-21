/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:27:27 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/21 17:23:30 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_map(t_fdf *data)
{
	int	i;

	i = 0;
	ft_printf("width: %d\n", data->width);
	ft_printf("heigh: %d\n", data->height);
	while (i < data->height)
	{
		free(data->matrix[i]);
		data->matrix[i] = NULL;
		i++;
	}
	free(data->matrix);
	data->matrix = NULL;
	free(data);
	get_next_line(-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if(argc != 2)
	{
		ft_printf("Insert an argument");
		return (2);
	}	
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!data->mlx)
		return (2);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image || (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0))
		return (2);
	if (!read_file("test_maps/julia.fdf", data))
		return (2);
	draw(data);
	mlx_loop_hook(data->mlx, deal_key, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	print_map(data);
}
