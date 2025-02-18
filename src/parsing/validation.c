/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:36:15 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/18 14:36:05 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map_validity(t_cub3d *cub3d)
{
	// int	i;
	// int	j;
	// i = 0;
	(void)cub3d;
	return (1);
}

int	validate_map_and_textures(t_cub3d *cub3d, t_textures *textures)
{
	// TODO FIX
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (0);
	if (cub3d->floor_color == -1 || cub3d->ceiling_color == -1)
		return (0);
	if (cub3d->map == NULL)
		return (0);
	check_map_validity(cub3d);
	return (1);
}
