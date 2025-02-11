/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:46:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/11 22:08:52 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void	key_hook_control(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		cub3d->minimap_maximized = true;
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		cub3d->minimap_maximized = false;
}
