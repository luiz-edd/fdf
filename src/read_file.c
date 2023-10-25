/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:34 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/25 18:27:45 by leduard2         ###   ########.fr       */
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

void	fill_matrix(char *line, int *z, int *color, int width)
{
	int				i;
	char			**nums;
	unsigned int	color_hex;

	i = 0;
	nums = ft_split(line, ' ');
	while (i < width)
	{	color_hex = 0;
		z[i] = ft_atoi(nums[i]);
		if ((ft_strchr(nums[i], 'x')) != NULL)
			color_hex = ft_atoi_base(ft_strchr(nums[i], 'x') + 1, 16);
		color[i] = color_hex;
		i++;
	}
	ft_freepp(nums);
}

// void	fill_matrix_color(char *line, int *arr, int width)
// {
// 	int		i;
// 	char	**nums;

// 	i = 0;
// 	nums = ft_split(line, ' ');
// 	while (i < width)
// 	{
// 		arr[i] = ft_strchr() ft_atoi(nums[i]);
// 		i++;
// 	}
// 	ft_freepp(nums);
// }

void	create_matrix(fdf *data)
{
	int	i;

	i = 0;
	data->z_matrix = (int **)malloc(sizeof(int *) * data->height + 1);
	data->color_matrix = (int **)malloc(sizeof(int *) * data->height + 1);
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		data->color_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		i++;
	}
}

int	read_file(char *file_name, fdf *data)
{
	int i;
	char *line;
	int fd;
	i = 0;

	if (!update_height_width(file_name, &data->height, &data->width))
		return (0);
	create_matrix(data);
	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix(line, data->z_matrix[i], data->color_matrix[i],
				data->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
	return (1);
}