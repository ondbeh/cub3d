/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:25:55 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/09 13:25:55 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void mlx_prepare(t_cub3d *cub3d)
{
    cub3d->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", 0);
    if (!cub3d->mlx)
        exit_error("mlx_init failed", cub3d);
    cub3d->img = NULL;
    mlx_loop_hook(cub3d->mlx, &key_hook_control, cub3d);
}
