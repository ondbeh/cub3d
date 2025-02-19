/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_and_bounds_check.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:57:55 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/19 15:01:00 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Helper function to check if position is within map bounds
static bool	is_within_bounds(t_cub3d *cub3d, int x, int y)
{
	return (x >= 0 && y >= 0 && x < cub3d->map_width && y < cub3d->map_height);
}

// Helper function to check if character is valid for flood fill
static bool	is_valid_space(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

bool	flood_fill(t_cub3d *cub3d, t_position pos, bool **visited)
{
	if (!is_within_bounds(cub3d, pos.x, pos.y))
		return (false);
	if (cub3d->map[pos.y][pos.x] == '1' || visited[pos.y][pos.x])
		return (true);
	if (!is_valid_space(cub3d->map[pos.y][pos.x]))
		return (false);
	visited[pos.y][pos.x] = true;
	if (!flood_fill(cub3d, (t_position){pos.x + 1, pos.y}, visited))
		return (false);
	if (!flood_fill(cub3d, (t_position){pos.x - 1, pos.y}, visited))
		return (false);
	if (!flood_fill(cub3d, (t_position){pos.x, pos.y + 1}, visited))
		return (false);
	if (!flood_fill(cub3d, (t_position){pos.x, pos.y - 1}, visited))
		return (false);
	return (true);
}
