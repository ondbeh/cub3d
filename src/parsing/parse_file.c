/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:49:35 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/03/08 10:30:23 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

static int	is_map_line(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	return (*line == '1' || *line == '0');
}

static int	parse_color(char *color_str, t_cub3d *cub3d)
{
	char	**rgb;
	int		i;
	int		color_array[3];

	rgb = ft_split(color_str, ',');
	if (!rgb)
		exit_error("Memory allocation failed", cub3d);
	i = 0;
	while (i < 3 && rgb[i])
	{
		color_array[i] = ft_atoi(rgb[i]);
		if (color_array[i] < 0 || color_array[i] > 255)
			exit_error("Invalid color value", cub3d);
		i++;
	}
	if (i != 3)
		exit_error("Invalid color format", cub3d);
	free_split(rgb);
	return (color_array[0] << 24 | color_array[1] << 16 | color_array[2] << 8 | 0xFF);
}

static void	parse_texture_or_color(t_cub3d *cub3d, t_textures *textures,
		char *line)
{
	char	**split;
	char	*trimmed;

	while (*line && ft_isspace(*line))
		line++;
	if (!*line || *line == '\n')
		return ;
	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		exit_error("Memory allocation failed", cub3d);
	split = ft_split(trimmed, ' ');
	free(trimmed);
	if (!split)
		exit_error("Memory allocation failed", cub3d);
	if (ft_strncmp(split[0], "NO", 3) == 0)
		textures->north = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		textures->south = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		textures->west = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		textures->east = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "F", 2) == 0)
		cub3d->floor_color = parse_color(split[1], cub3d);
	else if (ft_strncmp(split[0], "C", 2) == 0)
		cub3d->ceiling_color = parse_color(split[1], cub3d);
	else if (ft_strncmp(split[0], "S", 2) == 0)
		parse_sprite(cub3d, split);
	free_split(split);
}

static void	parse_map_line(t_cub3d *cub3d, char *line)
{
	t_list	*new_node;

	line = ft_strtrim(line, "\n");
	if (!line)
		exit_error("Memory allocation failed", cub3d);
	new_node = ft_lstnew(line);
	if (!new_node)
		exit_error("Memory allocation failed", cub3d);
	ft_lstadd_back(&cub3d->map_lines, new_node);
}

void	parse_file(t_cub3d *cub3d, t_textures *textures, char *data_file)
{
	char	*line;
	int		fd;
	int		parsing_map;

	fd = open(data_file, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open map file", cub3d);
	parsing_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!parsing_map && is_map_line(line))
			parsing_map = 1;
		if (parsing_map)
			parse_map_line(cub3d, line);
		else
			parse_texture_or_color(cub3d, textures, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
