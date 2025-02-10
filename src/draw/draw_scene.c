/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:11:39 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 23:03:24 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_scene(t_cub3d *cub3d)
{
	t_direction_hit	hit_array[SCREEN_WIDTH];

	if (cub3d->img)
		mlx_delete_image(cub3d->mlx, cub3d->img);
	cub3d->img = mlx_new_image(cub3d->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub3d->img)
		exit_error("mlx_new_image failed", cub3d);
	calculate_rays(cub3d, hit_array);
	draw_rays(cub3d, hit_array);
	calculate_fps(cub3d);
	mlx_image_to_window(cub3d->mlx, cub3d->img, 0, 0);
	mlx_set_instance_depth(cub3d->img->instances, 0);
	mlx_set_instance_depth(cub3d->fps_image->instances, 1);
}
