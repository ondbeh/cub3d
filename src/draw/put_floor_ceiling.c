/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:17:40 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 18:47:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	put_floor_ceiling(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->mlx->height / 2)
	{
		x = 0;
		while (x < cub3d->mlx->width)
		{
			mlx_put_pixel(cub3d->img, x, y, cub3d->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < cub3d->mlx->height)
	{
		x = 0;
		while (x < cub3d->mlx->width)
		{
			mlx_put_pixel(cub3d->img, x, y, cub3d->floor_color);
			x++;
		}
		y++;
	}
}
