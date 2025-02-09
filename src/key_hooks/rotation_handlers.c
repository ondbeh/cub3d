/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:13:51 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/09 22:13:51 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void handle_key_left(t_cub3d *cub3d)
{
    t_vector2D old_dir;
    t_vector2D old_plane;

    old_dir = cub3d->dir;
    cub3d->dir.x = cub3d->dir.x * cos(-ROTATION_ANGLE) - cub3d->dir.y * sin(-ROTATION_ANGLE);
    cub3d->dir.y = old_dir.x * sin(-ROTATION_ANGLE) + cub3d->dir.y * cos(-ROTATION_ANGLE);
    old_plane = cub3d->plane;
    cub3d->plane.x = cub3d->plane.x * cos(-ROTATION_ANGLE) - cub3d->plane.y * sin(-ROTATION_ANGLE);
    cub3d->plane.y = old_plane.x * sin(-ROTATION_ANGLE) + cub3d->plane.y * cos(-ROTATION_ANGLE);
}

void handle_key_right(t_cub3d *cub3d)
{
    t_vector2D old_dir;
    t_vector2D old_plane;

    old_dir = cub3d->dir;
    cub3d->dir.x = cub3d->dir.x * cos(ROTATION_ANGLE) - cub3d->dir.y * sin(ROTATION_ANGLE);
    cub3d->dir.y = old_dir.x * sin(ROTATION_ANGLE) + cub3d->dir.y * cos(ROTATION_ANGLE);
    old_plane = cub3d->plane;
    cub3d->plane.x = cub3d->plane.x * cos(ROTATION_ANGLE) - cub3d->plane.y * sin(ROTATION_ANGLE);
    cub3d->plane.y = old_plane.x * sin(ROTATION_ANGLE) + cub3d->plane.y * cos(ROTATION_ANGLE);
}