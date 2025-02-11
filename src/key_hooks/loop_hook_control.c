/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:46:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/11 22:00:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void	loop_hook_control(void *par)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)par;
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
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
		handle_key_left(cub3d);
	else if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
		handle_key_right(cub3d);
	draw_scene(cub3d);
}
