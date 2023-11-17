/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:27:27 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/17 19:27:39 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	print_map(t_fdf *data)
// {
// 	int	i;
// 	int	j;
// 	i = 0;
// 	printf("width: %d\n", data->width);
// 	printf("heigh: %d\n", data->height);
// 	i = 0;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			printf("%10u", data->matrix[i][j].color);
// 			j++;
// 		}
// 		printf("\n");
// 		// free(data->matrix[i]);
// 		i++;
// 	}
// 	// free(data->matrix);
// 	// free(data);
// 	return (0);
// }

int	main(void)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (data == NULL)
		return (2);
	// ft_error();
	data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!data->mlx)
		return (0);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// ft_error();
	if (!data->image || (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0))
		return (0);
	if (!read_file("test_maps/42.fdf", data))
		return (2);
	draw(data);
	mlx_loop_hook(data->mlx, deal_key, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	// print_map(data);
}
