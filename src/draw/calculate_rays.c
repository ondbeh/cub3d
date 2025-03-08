/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:52:45 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 18:51:46 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"


static void	perform_dda(t_cub3d *cub3d, t_direction_hit *hit,
		t_position *curr_pos, t_dda_params *params)
{
	int	hit_wall;

	hit_wall = 0;
	while (!hit_wall)
	{
		hit->is_door = false;
		if (params->side_dist.x < params->side_dist.y)
		{
			params->side_dist.x += params->delta_dist.x;
			curr_pos->x += params->step.x;
			hit->wall_side = (params->ray_dir.x < 0) ? WALL_WEST : WALL_EAST;
		}
		else
		{
			params->side_dist.y += params->delta_dist.y;
			curr_pos->y += params->step.y;
			hit->wall_side = (params->ray_dir.y < 0) ? WALL_NORTH : WALL_SOUTH;
		}
		if (cub3d->map[curr_pos->y][curr_pos->x] != '0'
			&& cub3d->map[curr_pos->y][curr_pos->x] != 'E')
		{
			hit_wall = 1;
			if (cub3d->map[curr_pos->y][curr_pos->x] == 'D')
				hit->is_door = true;
		}
	}
}

static void	calculate_hit_distance(t_cub3d *cub3d, t_direction_hit *hit,
		t_position curr_pos, t_dda_params params)
{
	if (hit->wall_side == WALL_NORTH || hit->wall_side == WALL_SOUTH
		|| hit->wall_side == WALL_DOOR)
	{
		hit->distance = (curr_pos.y - cub3d->player.y + (1 - params.step.y) / 2)
			/ params.ray_dir.y;
		hit->wall_x = cub3d->player.x + hit->distance * params.ray_dir.x;
	}
	else
	{
		hit->distance = (curr_pos.x - cub3d->player.x + (1 - params.step.x) / 2)
			/ params.ray_dir.x;
		hit->wall_x = cub3d->player.y + hit->distance * params.ray_dir.y;
	}
	hit->wall_x -= floor(hit->wall_x);
}

static void	calculate_distance(t_cub3d *cub3d, t_direction_hit *hit,
		t_vector2D ray_dir)
{
	t_position		curr_pos;
	t_dda_params	params;

	curr_pos = (t_position){(int)cub3d->player.x, (int)cub3d->player.y};
	prepare_dda_params(cub3d, ray_dir, &params);
	perform_dda(cub3d, hit, &curr_pos, &params);
	calculate_hit_distance(cub3d, hit, curr_pos, params);
}

void	calculate_rays(t_cub3d *cub3d, t_direction_hit *hit_array)
{
	float		camera_x;
	t_vector2D	ray_dir;
	int			i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		camera_x = 2 * i / (float)SCREEN_WIDTH - 1;
		ray_dir.x = cub3d->dir.x + cub3d->plane.x * camera_x;
		ray_dir.y = cub3d->dir.y + cub3d->plane.y * camera_x;
		calculate_distance(cub3d, &hit_array[i], ray_dir);
		i++;
	}
}
