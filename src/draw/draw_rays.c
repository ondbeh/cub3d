/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:12:06 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/09 17:12:06 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void draw_ray(t_cub3d *cub3d, int x, t_direction_hit hit)
{
    int line_height;
    int first_pixel;
    int last_pixel;
    int color;

    line_height = (int)(cub3d->mlx->height / hit.distance);
    first_pixel = cub3d->mlx->height / 2 - line_height / 2;
    last_pixel = cub3d->mlx->height / 2 + line_height / 2;
    if (first_pixel < 0)
    {
        first_pixel = 0;
        last_pixel = cub3d->mlx->height;
    }
    if (hit.wall_side == WALL_NORTH)
        color = 0x00DD00FF;
    else
        color = 0x22FF22FF;
    while (first_pixel < last_pixel)
    {
        mlx_put_pixel(cub3d->img, x, first_pixel, color);
        first_pixel++;
    }
}

void draw_rays(t_cub3d *cub3d, t_direction_hit *hit_array)
{
    int x = 0;
    while (x < SCREEN_WIDTH)
    {
        draw_ray(cub3d, x, hit_array[x]);
        x++;
    }
}