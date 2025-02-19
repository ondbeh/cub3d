/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:36:15 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/19 15:07:24 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	**init_visited_array(t_cub3d *cub3d)
{
	bool	**visited;
	int		i;

	visited = malloc(sizeof(bool *) * cub3d->map_height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < cub3d->map_height)
	{
		visited[i] = calloc(cub3d->map_width, sizeof(bool));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

static void	free_visited_array(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

static bool	check_remaining_spaces(t_cub3d *cub3d, bool **visited)
{
	t_position	pos;
	bool		is_valid;

	is_valid = true;
	pos.y = 0;
	while (pos.y < cub3d->map_height && is_valid)
	{
		pos.x = 0;
		while (pos.x < cub3d->map_width && is_valid)
		{
			if (cub3d->map[pos.y][pos.x] == '0' && !visited[pos.y][pos.x])
				is_valid = flood_fill(cub3d, (t_position){pos.x, pos.y},
					visited);
			pos.x++;
		}
		pos.y++;
	}
	return (is_valid);
}

int	check_map_validity(t_cub3d *cub3d)
{
	bool	**visited;
	bool	is_valid;

	visited = init_visited_array(cub3d);
	if (!visited)
		return (0);
	is_valid = flood_fill(cub3d,
			(t_position){cub3d->player.x, cub3d->player.y}, visited);
	if (is_valid)
		is_valid = check_remaining_spaces(cub3d, visited);
	free_visited_array(visited, cub3d->map_height);
	return (is_valid);
}

int	validate_map_and_textures(t_cub3d *cub3d, t_textures *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (0);
	if (cub3d->floor_color == -1 || cub3d->ceiling_color == -1)
		return (0);
	if (cub3d->map == NULL)
		return (0);
	if (cub3d->player.x == -1 || cub3d->player.y == -1)
		return (0);
	if (!check_map_validity(cub3d))
		return (0);
	return (1);
}
