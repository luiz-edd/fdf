/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:27:27 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/21 19:44:08 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	print_map(t_fdf *data)
{
	int	i;

	i = 0;
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
	ft_printf("Program finished");
	return (0);
}

int	free_and_error(t_fdf *data, char *message)
{
	free(data);
	ft_printf(message);
	return (-2);
}

void	ft_exit(void *param)
{
	t_fdf	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	mlx_delete_image(data->mlx, data->image);
	mlx_terminate(data->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_printf("Insert a valid argument\n");
		return (2);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!data->mlx)
		return (free_and_error(data, "mlx error"));
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image || (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0))
		return (free_and_error(data, "image error"));
	if (!read_file(argv[1], data))
		return (free_and_error(data, "entrou"));
	draw(data);
	mlx_loop_hook(data->mlx, deal_key, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	print_map(data);
}
