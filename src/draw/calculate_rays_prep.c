/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays_prep.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:51:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 09:22:34 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	prepare_dda_params(t_cub3d *cub3d, t_vector2D ray_dir,
		t_dda_params *params)
{
	params->ray_dir = ray_dir;
	prepare_delta_dist(ray_dir, &params->delta_dist);
	prepare_step_and_sidestep(cub3d, params);
}

void	prepare_delta_dist(t_vector2D ray_dir, t_vector2D *delta_dist)
{
	*delta_dist = (t_vector2D){1e30, 1e30};
	if (ray_dir.y != 0)
		delta_dist->y = fabs(1 / ray_dir.y);
	if (ray_dir.x != 0)
		delta_dist->x = fabs(1 / ray_dir.x);
}

void	prepare_step_and_sidestep(t_cub3d *cub3d, t_dda_params *par)
{
	t_position	curr_pos;

	curr_pos = (t_position){(int)cub3d->player.x, (int)cub3d->player.y};
	if (par->ray_dir.x < 0)
	{
		par->step.x = -1;
		par->side_dist.x = (cub3d->player.x - curr_pos.x) * par->delta_dist.x;
	}
	else
	{
		par->step.x = 1;
		par->side_dist.x = (curr_pos.x + 1.0 - cub3d->player.x)
			* par->delta_dist.x;
	}
	if (par->ray_dir.y < 0)
	{
		par->step.y = -1;
		par->side_dist.y = (cub3d->player.y - curr_pos.y) * par->delta_dist.y;
	}
	else
	{
		par->step.y = 1;
		par->side_dist.y = (curr_pos.y + 1.0 - cub3d->player.y)
			* par->delta_dist.y;
	}
}
