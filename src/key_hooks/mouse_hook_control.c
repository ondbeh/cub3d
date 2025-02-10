/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:44:04 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 21:44:04 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void	scroll_hook_control(double x_delta, double y_delta, void *par)
{
	t_cub3d	*cub3d;

	(void)x_delta;
	cub3d = (t_cub3d *)par;
	if (y_delta > 0 && vector_size(cub3d->plane) < MAX_FOV)
	{
		cub3d->plane.y *= 1.05;
		cub3d->plane.x *= 1.05;
		cub3d->height_multiplier *= 1.05;
		cub3d->rotation_angle *= 1.05;
	}
	else if (y_delta < 0 && vector_size(cub3d->plane) > MIN_FOV)
	{
		cub3d->plane.y *= 0.95;
		cub3d->plane.x *= 0.95;
		cub3d->height_multiplier *= 0.95;
		cub3d->rotation_angle *= 0.95;
	}
}

void	mouse_hook_control(mouse_key_t button, action_t action,
		modifier_key_t mods, void *par)
{
	t_cub3d	*cub3d;

	(void)mods;
	cub3d = (t_cub3d *)par;
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_PRESS)
	{
		vector_set_size(&cub3d->plane, BASE_FOV);
		cub3d->height_multiplier = BASE_HEIGHT_MULTIPLIER;
		cub3d->rotation_angle = BASE_ROTATION_ANGLE;
	}
}
