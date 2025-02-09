/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:52:45 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/09 16:52:45 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void calculate_distance(t_cub3d *cub3d, int i, t_direction_hit *hit)
{
    (void)cub3d;
    // TODO: Implement distance calculation
    if (i < SCREEN_WIDTH / 2)
    {
        hit->distance = 2 + i * 0.1;
        hit->wall_side = WALL_EAST;
    }
    else
    {
        hit->distance = 2 + (SCREEN_WIDTH - i) * 0.1;
        hit->wall_side = WALL_NORTH;
    }
}

void calculate_rays(t_cub3d *cub3d, t_direction_hit *hit_array)
{
    int i = 0;
    while (i < SCREEN_WIDTH)
    {
        calculate_distance(cub3d, i, &hit_array[i]);
        i++;
    }
}