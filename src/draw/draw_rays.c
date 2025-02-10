/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:12:06 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 18:46:53 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	reverse_color(int color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (color & 0x000000FF) >> 0;
	g = (color & 0x0000FF00) >> 8;
	b = (color & 0x00FF0000) >> 16;
	return ((r << 24) | (g << 16) | (b << 8) | 0x000000FF);
}

static int	get_color(t_cub3d *cub3d, t_direction_hit hit, int first_pixel,
		int last_pixel, int y)
{
	float		y_ratio;
	t_position	texture_pos;
	int			texture_color;
	int			*tex_pixels;

	tex_pixels = (int *)cub3d->texture[hit.wall_side]->pixels;
	if (y < 0 || y > cub3d->mlx->height)
		return (0);
	y_ratio = (float)(y - first_pixel) / (last_pixel - first_pixel);
	texture_pos.x = (int)(hit.wall_x * cub3d->texture[hit.wall_side]->width);
	texture_pos.y = (int)(y_ratio * cub3d->texture[hit.wall_side]->height);
	texture_color = tex_pixels[texture_pos.y
		* cub3d->texture[hit.wall_side]->width + texture_pos.x];
	texture_color = reverse_color(texture_color);
	return (texture_color);
}

static void	draw_ray(t_cub3d *cub3d, int x, t_direction_hit hit)
{
	int	line_height;
	int	first_pixel;
	int	last_pixel;
	int	color;
	int	y;

	line_height = (int)(cub3d->mlx->height / hit.distance);
	first_pixel = cub3d->mlx->height / 2 - line_height / 2;
	last_pixel = cub3d->mlx->height / 2 + line_height / 2;
	y = first_pixel;
	while (y < last_pixel)
	{
		color = get_color(cub3d, hit, first_pixel, last_pixel, y);
		if (y >= 0 && y < cub3d->mlx->height)
			mlx_put_pixel(cub3d->img, x, y, color);
		y++;
	}
}

void	draw_rays(t_cub3d *cub3d, t_direction_hit *hit_array)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		draw_ray(cub3d, x, hit_array[x]);
		x++;
	}
}
