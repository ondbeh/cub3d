/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:45:04 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 17:53:24 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static uint32_t	get_tile_color(char tile)
{
	if (tile == '0')
		return (0x999922CC);
	else if (tile == 'D')
		return (0xAA5500CC);
	else if (tile == 'E')
		return (0x00FF00CC);
	else
		return (0xFFFFFFCC);
}

static void	draw_map_tiles(t_cub3d *cub3d, int mm_width, int mm_height,
		t_vector2D mm_ratio)
{
	int			color;
	uint32_t	y;
	uint32_t	x;
	t_vector2D	mm_ratio;

	mm_ratio.x = (float)cub3d->map_width / (float)cub3d->minimap_image->width;
	mm_ratio.y = (float)cub3d->map_height / (float)cub3d->minimap_image->height;
	y = 0;
	while (y < cub3d->minimap_image->height)
	{
		x = 0;
		while (x < cub3d->minimap_image->width)
		{
			if (fabsf(cub3d->player.x - x * mm_ratio.x) < PLAYER_SIZE
				&& fabsf(cub3d->player.y - y * mm_ratio.y) < PLAYER_SIZE)
				color = 0xFF0000CC;
			else if (cub3d->map[(int)(y * mm_ratio.y)][(int)(x
					* mm_ratio.x)] == '0')
				color = 0x999922CC;
			else
				color = 0xFFFFFFCC;
			mlx_put_pixel(cub3d->minimap_image, x++, y, color);
		}
		y++;
	}
}

void	create_minimap(t_cub3d *cub3d)
{
	static bool	is_maximized = false;
	t_position	size;
	t_position	mm_position;

	if (!cub3d->minimap_image || is_maximized != cub3d->minimap_maximized)
	{
		if (cub3d->minimap_image)
			mlx_delete_image(cub3d->mlx, cub3d->minimap_image);
		if (cub3d->minimap_maximized)
			size = (t_position){cub3d->mlx->width, cub3d->mlx->height};
		else
			size = (t_position){cub3d->mlx->width / 5, cub3d->mlx->height / 5};
		cub3d->minimap_image = mlx_new_image(cub3d->mlx, size.x, size.y);
		if (!cub3d->minimap_image)
			exit_error("mlx_new_image failed", cub3d);
		draw_minimap(cub3d);
		mm_position = (t_position){cub3d->mlx->width - size.x,
			cub3d->mlx->height - size.y};
		mlx_image_to_window(cub3d->mlx, cub3d->minimap_image, mm_position.x,
			mm_position.y);
		is_maximized = cub3d->minimap_maximized;
	}
	else
		draw_minimap(cub3d);
}
