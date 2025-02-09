/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clenup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:48:33 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/08 23:48:33 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void cleanup(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (cub3d->map && cub3d->map[i])
    {
        free(cub3d->map[i]);
        i++;
    }
    free(cub3d->map);
    if (cub3d->mlx)
        mlx_terminate(cub3d->mlx);
    cub3d->map = NULL;
    cub3d->img = NULL;
    cub3d->mlx = NULL;
}