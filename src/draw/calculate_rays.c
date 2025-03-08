/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:52:45 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 13:15:26 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	prepare_step_and_sidestep(t_cub3d *cub3d, t_vector2D ray_dir,
		t_position *step, t_vector2D *side_dist, t_vector2D delta_dist)
{
	t_position	curr_pos;

	curr_pos = (t_position){(int)cub3d->player.x, (int)cub3d->player.y};
	if (ray_dir.x < 0)
	{
		step->x = -1;
		side_dist->x = (cub3d->player.x - curr_pos.x) * delta_dist.x;
	}
	else
	{
		step->x = 1;
		side_dist->x = (curr_pos.x + 1.0 - cub3d->player.x) * delta_dist.x;
	}
	if (ray_dir.y < 0)
	{
		step->y = -1;
		side_dist->y = (cub3d->player.y - curr_pos.y) * delta_dist.y;
	}
	else
	{
		step->y = 1;
		side_dist->y = (curr_pos.y + 1.0 - cub3d->player.y) * delta_dist.y;
	}
}

void	prepare_delta_dist(t_vector2D ray_dir, t_vector2D *delta_dist)
{
	*delta_dist = (t_vector2D){1e30, 1e30};
	if (ray_dir.y != 0)
		delta_dist->y = fabs(1 / ray_dir.y);
	if (ray_dir.x != 0)
		delta_dist->x = fabs(1 / ray_dir.x);
}

static void	calculate_distance(t_cub3d *cub3d, t_direction_hit *hit,
		t_vector2D ray_dir)
{
	t_position	curr_pos;
	t_position	step;
	t_vector2D	side_dist;
	t_vector2D	delta_dist;
	int			hit_wall;

	hit_wall = 0;
	curr_pos = (t_position){(int)cub3d->player.x, (int)cub3d->player.y};
	prepare_delta_dist(ray_dir, &delta_dist);
	prepare_step_and_sidestep(cub3d, ray_dir, &step, &side_dist, delta_dist);
	while (!hit_wall)
	{
		hit->is_door = false;
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			curr_pos.x += step.x;
			hit->wall_side = (ray_dir.x < 0) ? WALL_WEST : WALL_EAST;
		}
		else
		{
			side_dist.y += delta_dist.y;
			curr_pos.y += step.y;
			hit->wall_side = (ray_dir.y < 0) ? WALL_NORTH : WALL_SOUTH;
		}
		if (cub3d->map[curr_pos.y][curr_pos.x] != '0'
			&& cub3d->map[curr_pos.y][curr_pos.x] != 'E')
		{
			hit_wall = 1;
			if (cub3d->map[curr_pos.y][curr_pos.x] == 'D')
				hit->is_door = true;
		}
	}
	if (hit->wall_side == WALL_NORTH || hit->wall_side == WALL_SOUTH
		|| hit->wall_side == WALL_DOOR)
	{
		hit->distance = (curr_pos.y - cub3d->player.y + (1 - step.y) / 2)
			/ ray_dir.y;
		hit->wall_x = cub3d->player.x + hit->distance * ray_dir.x;
	}
	else
	{
		hit->distance = (curr_pos.x - cub3d->player.x + (1 - step.x) / 2)
			/ ray_dir.x;
		hit->wall_x = cub3d->player.y + hit->distance * ray_dir.y;
	}
	hit->wall_x -= floor(hit->wall_x);
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
