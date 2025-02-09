/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:46:00 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/09 13:46:00 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

void key_hook_control(void *par)
{
    t_cub3d *cub3d;

    cub3d = (t_cub3d *)par;
    if (mlx_is_key_down(cub3d->mlx, MLX_KEY_ESCAPE))
        exit_success(cub3d);
    else
        return;
}