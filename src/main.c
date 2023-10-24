/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:54:00 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/24 12:32:25 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 256
#define HEIGHT 256

int	print_map_free(fdf *data)
{
	int	i;
	int	j;

	if (!read_file("test_maps/test.fdf", data))
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
		free(data->z_matrix[i++]);
	}
	free(data->z_matrix);
	free(data);
	return (0);
}

//print map and free
int	main(void)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	if (data == NULL)
		return (2);
	print_map_free(data);
}
