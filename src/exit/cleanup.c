/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:48:33 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 12:07:32 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	cleanup_textures(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->sprite_count)
	{
		if (cub3d->sprites[i]->texture_ptr)
			mlx_delete_texture(cub3d->sprites[i]->texture_ptr);
		free(cub3d->sprites[i]);
		i++;
	}
	if (cub3d->texture[WALL_NORTH])
		mlx_delete_texture(cub3d->texture[WALL_NORTH]);
	if (cub3d->texture[WALL_SOUTH])
		mlx_delete_texture(cub3d->texture[WALL_SOUTH]);
	if (cub3d->texture[WALL_WEST])
		mlx_delete_texture(cub3d->texture[WALL_WEST]);
	if (cub3d->texture[WALL_EAST])
		mlx_delete_texture(cub3d->texture[WALL_EAST]);
	if (cub3d->texture[WALL_DOOR])
		mlx_delete_texture(cub3d->texture[WALL_DOOR]);
}

void	cleanup(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < cub3d->map_height)
		free(cub3d->map[i++]);
	free(cub3d->map);
	ft_lstclear(&cub3d->map_lines, free);
	if (cub3d->img)
		mlx_delete_image(cub3d->mlx, cub3d->img);
	if (cub3d->fps_image)
		mlx_delete_image(cub3d->mlx, cub3d->fps_image);
	if (cub3d->mlx)
		mlx_terminate(cub3d->mlx);
	cub3d->map = NULL;
	cub3d->img = NULL;
	cub3d->mlx = NULL;
}
