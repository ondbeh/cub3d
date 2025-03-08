/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:45:04 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 16:56:54 by obehavka         ###   ########.fr       */
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
	int			y;
	int			x;
	t_position	map;

	y = -1;
	while (++y < mm_height)
	{
		x = -1;
		while (++x < mm_width)
		{
			map = (t_position){x * mm_ratio.x, y * mm_ratio.y};
			if (map.y >= 0 && map.y < cub3d->map_height && map.x >= 0
				&& map.x < cub3d->map_width)
			{
				mlx_put_pixel(cub3d->minimap_image, x, y,
					get_tile_color(cub3d->map[map.y][map.x]));
			}
		}
	}
}

static void	draw_player(t_cub3d *cub3d, int mm_width, int mm_height,
		t_vector2D mm_ratio)
{
	int	player_x;
	int	player_y;
	int	player_size;
	int	i;
	int	j;

	player_x = (int)(cub3d->player.x / mm_ratio.x);
	player_y = (int)(cub3d->player.y / mm_ratio.y);
	player_size = cub3d->minimap_maximized ? 4 : 2;
	i = player_x - player_size;
	while (i <= player_x + player_size)
	{
		if (i < 0 || i >= mm_width)
		{
			i++;
			continue ;
		}
		j = player_y - player_size;
		while (j <= player_y + player_size)
		{
			if (j >= 0 && j < mm_height)
				mlx_put_pixel(cub3d->minimap_image, i, j, 0xFF0000FF);
			j++;
		}
		i++;
	}
}

static void	draw_direction(t_cub3d *cub3d, int mm_width, int mm_height,
		t_vector2D mm_ratio)
{
	int	player_x;
	int	player_y;
	int	line_length;
	int	i;
	int	x;
	int	y;

	player_x = (int)(cub3d->player.x / mm_ratio.x);
	player_y = (int)(cub3d->player.y / mm_ratio.y);
	line_length = cub3d->minimap_maximized ? 20 : 8;
	i = 0;
	while (i <= line_length)
	{
		x = player_x + (int)(cub3d->dir.x * i);
		y = player_y + (int)(cub3d->dir.y * i);
		if (x >= 0 && x < mm_width && y >= 0 && y < mm_height)
			mlx_put_pixel(cub3d->minimap_image, x, y, 0xFFFF00FF);
		i++;
	}
}

static void	draw_minimap(t_cub3d *cub3d)
{
	int			mm_width;
	int			mm_height;
	t_vector2D	mm_ratio;

	mm_width = (int)cub3d->minimap_image->width;
	mm_height = (int)cub3d->minimap_image->height;
	mm_ratio.x = (float)cub3d->map_width / (float)mm_width;
	mm_ratio.y = (float)cub3d->map_height / (float)mm_height;
	draw_map_tiles(cub3d, mm_width, mm_height, mm_ratio);
	draw_direction(cub3d, mm_width, mm_height, mm_ratio);
	draw_player(cub3d, mm_width, mm_height, mm_ratio);
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
