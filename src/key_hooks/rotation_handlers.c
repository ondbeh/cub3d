/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:13:51 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/15 12:42:44 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void	rotate_left(t_cub3d *cub3d, float rotation_multiplier)
{
	t_vector2D	old_dir;
	t_vector2D	old_plane;
	float		final_angle;

	final_angle = cub3d->rotation_angle * rotation_multiplier;
	old_dir = cub3d->dir;
	cub3d->dir.x = cub3d->dir.x * cos(-final_angle) - cub3d->dir.y
		* sin(-final_angle);
	cub3d->dir.y = old_dir.x * sin(-final_angle) + cub3d->dir.y
		* cos(-final_angle);
	old_plane = cub3d->plane;
	cub3d->plane.x = cub3d->plane.x * cos(-final_angle) - cub3d->plane.y
		* sin(-final_angle);
	cub3d->plane.y = old_plane.x * sin(-final_angle) + cub3d->plane.y
		* cos(-final_angle);
}

void	rotate_right(t_cub3d *cub3d, float rotation_multiplier)
{
	t_vector2D	old_dir;
	t_vector2D	old_plane;
	float		final_angle;

	final_angle = cub3d->rotation_angle * rotation_multiplier;
	old_dir = cub3d->dir;
	cub3d->dir.x = cub3d->dir.x * cos(final_angle) - cub3d->dir.y
		* sin(final_angle);
	cub3d->dir.y = old_dir.x * sin(final_angle) + cub3d->dir.y
		* cos(final_angle);
	old_plane = cub3d->plane;
	cub3d->plane.x = cub3d->plane.x * cos(final_angle) - cub3d->plane.y
		* sin(final_angle);
	cub3d->plane.y = old_plane.x * sin(final_angle) + cub3d->plane.y
		* cos(final_angle);
}
