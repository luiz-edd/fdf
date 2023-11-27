/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:20:05 by leduard2          #+#    #+#             */
/*   Updated: 2023/11/27 19:59:49 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
			ft_printf("MAP ERROR\n");
			return (0);
		}
		line = get_next_line(fd);
	}
	return (1);
}

void	fill_matrix(t_fdf *data, int y, char *line)
{
	int		i;
	char	**nums;
	int		x;

	x = 0;
	i = 0;
	nums = ft_split(line, ' ');
	while (i < data->width)
	{
		data->matrix[y][x].x = x - ((data->width) / 2);
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

void	create_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	data->matrix = (t_point **)ft_calloc(sizeof(t_point *), data->height + 1);
	while (i < data->height)
	{
		data->matrix[i] = (t_point *)ft_calloc(sizeof(t_point), data->width);
		i++;
	}
	data->zoom = 1700 / hypot((double)data->height, (double)data->width);
	data->shift_x = 0;
	data->shift_y = 0;
	data->x_angle = 54.7;
	data->y_angle = 0;
	data->z_angle = -45;
	data->z_scale = 1;
}

int	read_file(char *file_name, t_fdf *data)
{
	int		y;
	char	*line;
	int		fd;

	y = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("MAP NOT FOUND\n");
		return (0);
	}
	if (!update_height_width(file_name, &data->height, &data->width))
		return (0);
	create_matrix(data);
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
