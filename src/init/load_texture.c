/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:58:09 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 08:58:09 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static mlx_texture_t	*load_texture(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free(texture);
		exit_error("mlx_load_png failed", NULL);
	}
	return (texture);
}

void	load_textures(t_cub3d *cub3d, t_textures textures)
{
	cub3d->texture[WALL_NORTH] = load_texture(textures.north);
	cub3d->texture[WALL_SOUTH] = load_texture(textures.south);
	cub3d->texture[WALL_EAST] = load_texture(textures.east);
	cub3d->texture[WALL_WEST] = load_texture(textures.west);
	cub3d->texture[WALL_DOOR] = load_texture(textures.door);
}
