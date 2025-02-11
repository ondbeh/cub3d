/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:45:04 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/11 09:45:04 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_minimap(t_cub3d *cub3d)
{
	int			color;
	uint32_t	y;
	uint32_t	x;
	t_vector2D	minimap_ratio;

	minimap_ratio.x = (float)cub3d->map_width
		/ (float)cub3d->minimap_image->width;
	minimap_ratio.y = (float)cub3d->map_height
		/ (float)cub3d->minimap_image->height;
	y = 0;
	while (y < cub3d->minimap_image->height)
	{
		x = 0;
		while (x < cub3d->minimap_image->width)
		{
			if (fabsf(cub3d->player.x - x * minimap_ratio.x) < PLAYER_SIZE
				&& fabsf(cub3d->player.y - y * minimap_ratio.y) < PLAYER_SIZE)
				color = 0xFF0000CC;
			else if (cub3d->map[(int)(y * minimap_ratio.y)][(int)(x
					* minimap_ratio.x)] == '0')
				color = 0x999922CC;
			else
				color = 0xFFFFFFCC;
			mlx_put_pixel(cub3d->minimap_image, x, y, color);
			x++;
		}
		y++;
	}
}

void	create_minimap(t_cub3d *cub3d)
{
	t_position mm_size;
	t_position mm_position;

	if (!cub3d->minimap_image)
	{
		mm_size = (t_position){cub3d->mlx->width / 5, cub3d->mlx->height / 5};
		cub3d->minimap_image = mlx_new_image(cub3d->mlx, mm_size.x, mm_size.y);
		if (!cub3d->minimap_image)
			exit_error("mlx_new_image failed", cub3d);
		draw_minimap(cub3d);
		mm_position = (t_position){cub3d->mlx->width - mm_size.x,
			cub3d->mlx->height - mm_size.y};
		mlx_image_to_window(cub3d->mlx, cub3d->minimap_image, mm_position.x,
			mm_position.y);
	}
	else
		draw_minimap(cub3d);
}