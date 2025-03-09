/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:46:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 12:32:33 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void	key_hook_control(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
		exit_success(cub3d);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		cub3d->minimap_maximized = true;
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		cub3d->minimap_maximized = false;
	else if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		toggle_door(cub3d);
}
