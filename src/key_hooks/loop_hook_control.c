/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:02:23 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/19 17:39:32 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

bool	handle_mouse_movement(t_cub3d *cub3d)
{
	float	rotation_multiplier;
	int		x;
	int		y;

	mlx_get_mouse_pos(cub3d->mlx, &x, &y);
	rotation_multiplier = fabs((x - SCREEN_WIDTH / 2) / 100.0);
	if (rotation_multiplier > 1)
		rotation_multiplier = 1;
	if (rotation_multiplier > 0.001)
	{
		if (x - SCREEN_WIDTH / 2 > 0)
			rotate_right(cub3d, rotation_multiplier);
		else if (x - SCREEN_WIDTH / 2 < 0)
			rotate_left(cub3d, rotation_multiplier);
		mlx_set_mouse_pos(cub3d->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		return (true);
	}
	return (false);
}

void	loop_hook_control(void *par)
{
	t_cub3d	*cub3d;
	bool	mouse_moved;

	cub3d = (t_cub3d *)par;
	mouse_moved = handle_mouse_movement(cub3d);
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		exit_success(cub3d);
	else if (mlx_is_key_down(cub3d->mlx, MLX_KEY_W))
		handle_key_w(cub3d);
	else if (mlx_is_key_down(cub3d->mlx, MLX_KEY_S))
		handle_key_s(cub3d);
	else if (mlx_is_key_down(cub3d->mlx, MLX_KEY_A))
		handle_key_a(cub3d);
	else if (mlx_is_key_down(cub3d->mlx, MLX_KEY_D))
		handle_key_d(cub3d);
	if (!mouse_moved)
	{
		if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
			rotate_left(cub3d, BUTTON_TURNING_COEF);
		else if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
			rotate_right(cub3d, BUTTON_TURNING_COEF);
	}
	draw_scene(cub3d);
}
