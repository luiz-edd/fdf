/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:54:00 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/23 11:22:33 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	fdf	*data;
	

	// int height;
	// int width;
	data = (fdf *)malloc(sizeof(fdf));
	read_file("test_maps/test.fdf", data);

	int	i;
	int	j;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			printf("%3d", data->z_matrix[i][j++]);
		i++;
		printf("\n");
	}
	// i = 0;
	// int j = 0;
	// int height = data->height;
	// int width = data->width;
	// while (i < height)
	// {
	// 	free(data->z_matrix[i++]);
	// 	while()
	// }
	// free(data->z_matrix);
	// free(data);
	
}

//test GNL
// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	fd = open("test_maps/test.fdf", O_RDONLY);
// 	printf("%d\n", fd);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }