/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:34 by leduard2          #+#    #+#             */
/*   Updated: 2023/10/24 10:01:42 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = 0;
	height = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;
	char	**words;
	int		i;

	// int		j;
	i = 0;
	// j = 0;
	width = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	words = ft_split(line, ' ');
	while (words[i] != NULL)
	{
		if (words[i++][0] != '\n')
			width++;
	}
	ft_freepp(words);
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix_line(char *line, int *arr, int width)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(line, ' ');
	while (i < width)
	{
		arr[i] = ft_atoi(nums[i]);
		i++;
	}
	ft_freepp(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int i;
	char *line;
	int fd;
	fd = 0;

	i = 0;

	data->height = get_height(file_name);
	get_next_line(-1);
	data->width = get_width(file_name);
	get_next_line(-1);

	data->z_matrix = (int **)malloc(sizeof(int *) * data->height + 1);
	while (i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * data->width);
	i = 0;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matrix_line(line, data->z_matrix[i++], data->width);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->z_matrix[i] = NULL;
}