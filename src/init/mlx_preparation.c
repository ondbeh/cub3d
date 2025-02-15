/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:25:55 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/15 12:43:34 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	mlx_prepare(t_cub3d *cub3d)
{
	mlx_win_cursor_t	*cursor;

	cub3d->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", 0);
	if (!cub3d->mlx)
		exit_error("mlx_init failed", cub3d);
	cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	if (!cursor)
		exit_error("mlx_create_std_cursor failed", cub3d);
	cub3d->img = NULL;
	mlx_set_cursor(cub3d->mlx, cursor);
	mlx_loop_hook(cub3d->mlx, &loop_hook_control, cub3d);
	mlx_key_hook(cub3d->mlx, &key_hook_control, cub3d);
	mlx_mouse_hook(cub3d->mlx, &mouse_hook_control, cub3d);
	mlx_scroll_hook(cub3d->mlx, &scroll_hook_control, cub3d);
	mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cub3d->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
