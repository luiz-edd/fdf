/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:34 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/27 13:43:56 by leduard2         ###   ########.fr       */
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

void	fill_matrix(char *line, int *z, unsigned int *color, fdf *data)
{
	int				i;
	char			**nums;
	unsigned int	color_hex;

	i = 0;
	nums = ft_split(line, ' ');
	while (i < data->width)
	{
		color_hex = 0xffffffff;
		z[i] = ft_atoi(nums[i]);
		if ((ft_strchr(nums[i], 'x')) != NULL)
		{
			data->has_color = 1;
			color_hex = ((ft_atoi_base(ft_strchr(nums[i], 'x') + 1, 16)) << 8) + 0xFF;
		}
		color[i] = color_hex;
		i++;
	}
	ft_freepp(nums);
}

void	create_matrix(fdf *data)
{
	int	i;

	i = 0;
	data->z_matrix = (int **)malloc(sizeof(int *) * data->height + 1);
	data->color_matrix = (unsigned int **)malloc(sizeof(unsigned int *)
			* data->height + 1);
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		data->color_matrix[i] = (unsigned int *)malloc(sizeof(unsigned int)
				* data->width);
		i++;
	}
	data->has_color = 0;
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
		fill_matrix(line, data->z_matrix[i], data->color_matrix[i], data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
	return (1);
}