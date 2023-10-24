/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:54:00 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/24 10:10:14 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 256
#define HEIGHT 256

//print map
int	main(void)
{
	fdf	*data;
	int	i;
	int	j;
	int	height;
	int	width;

	data = (fdf *)malloc(sizeof(fdf));
	read_file("test_maps/10-2.fdf", data);
	i = 0;
	printf("width: %d\n", data->width);
	printf("heigh: %d\n", data->height);
	i = 0;
	height = data->height;
	width = data->width;
	while (i < height)
	{
		j = 0;
		while (j < width)
			printf("%3d", data->z_matrix[i][j++]);
		printf("\n");
		free(data->z_matrix[i++]);
	}
	free(data->z_matrix);
	free(data);
}
