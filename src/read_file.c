/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.point                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:34 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/31 14:09:06 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line)
{
	int		i;
	int		width;
	char	**words;

	i = 0;
	width = 0;
	if (line == NULL)
		return (0);
	words = ft_split(line, ' ');
	while (words[i] != NULL)
	{
		if (words[i++][0] != '\n')
			width++;
	}
	ft_freepp(words);
	return (width);
}

int	update_height_width(char *file_name, int *heigh, int *width)
{
	int		i;
	int		fd;
	char	*line;
	int		aux_width;

	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	*heigh = 0;
	*width = 0;
	aux_width = get_width(line);
	while (line != NULL)
	{
		*heigh += 1;
		*width = get_width(line);
		free(line);
		if (aux_width != *width)
		{
			get_next_line(-1);
			printf("MAP ERROR\n");
			return (0);
		}
		line = get_next_line(fd);
	}
	return (1);
}

void	fill_matrix(fdf *data, int y, char *line)
{
	int		i;
	char	**nums;
	int		x;

	x = 0;
	i = 0;
	nums = ft_split(line, ' ');
	while (i < data->width)
	{
		data->matrix[y][x].x = x - ((data->width) / 2 );
		data->matrix[y][x].y = y - (data->height / 2);
		data->matrix[y][x].z = ft_atoi(nums[i]);
		if ((ft_strchr(nums[i], 'x')) != NULL)
		{
			data->matrix[y][x].color = ((ft_atoi_base(ft_strchr(nums[i], 'x')
							+ 1, 16) << 8) | 0xFF);
		}
		else
			data->matrix[y][x].color = 0;
		i++;
		x++;
	}
	ft_freepp(nums);
}

void	create_matrix(fdf *data)
{
	int	i;

	i = 0;
	data->matrix = (point **)malloc(sizeof(point *) * data->height + 1);
	while (i < data->height)
	{
		data->matrix[i] = (point *)malloc(sizeof(point) * data->width);
		i++;
	}
	data->zoom = 1;
	
	data->shift_x = 0;
	data->shift_y = 0;

	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;

	data->is_isometric = 0;
}

int	read_file(char *file_name, fdf *data)
{
	int		y;
	char	*line;
	int		fd;

	y = 0;
	if (!update_height_width(file_name, &data->height, &data->width))
		return (0);
	create_matrix(data);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (y < data->height)
	{
		fill_matrix(data, y, line);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	data->matrix[y] = NULL;
	return (1);
}

// unsigned int	add_transparency(char *color)
// {
// 	unsigned int	new_color;
// 	unsigned int	mask;

// 	mask = 2147483648;
// 	new_color = ft_atoi_base(color, 16);
// 	// return ((new_color & 0x00FFFFFF) | mask);
// 	return ((new_color << 8) | 0xff);
// }
