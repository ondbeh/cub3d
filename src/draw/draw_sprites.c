/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:48:40 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 11:12:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static inline int	get_sprite_tex_x(int x, int w, int s_s_x, t_sprite *sprite)
{
	int	frame_width;
	int	frame_x;
	int	current_frame;

	current_frame = sprite->current_frame % sprite->count;
	frame_width = sprite->texture_ptr->width / sprite->count;
	frame_x = (int)((x - (-w / 2 + s_s_x)) * frame_width / w);
	return (frame_x + (current_frame * frame_width));
}

static int	get_sprite_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint8_t	*pixel;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (tex_x < 0 || tex_x >= (int)texture->width || tex_y < 0
		|| tex_y >= (int)texture->height)
		return (0);
	pixel = texture->pixels + (tex_y * texture->width + tex_x) * 4;
	if (!pixel[0] && !pixel[1] && !pixel[2])
		return (0);
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static void	draw_sprite_strip(t_cub3d *cub3d, t_direction_hit *hit_array, int i,
		t_sprite_draw_data *data)
{
	int		y;
	int		tex_y;
	float	y_ratio;
	int		color;

	if (cub3d->sprites[i]->transform.y <= 0 || data->stripe <= 0
		|| data->stripe > SCREEN_WIDTH
		|| cub3d->sprites[i]->transform.y > hit_array[data->stripe].distance)
		return ;
	y = data->start.y;
	while (y < data->end.y)
	{
		y_ratio = (float)(y - (SCREEN_HEIGHT / 2) + (data->dimensions.y / 2))
			/ data->dimensions.y;
		tex_y = (int)(y_ratio * cub3d->sprites[i]->texture_ptr->height);
		color = get_sprite_color(cub3d->sprites[i]->texture_ptr, data->tex_x,
				tex_y);
		if (color != 0)
			mlx_put_pixel(cub3d->img, data->stripe, y, color);
		y++;
	}
}

void	draw_sprite(t_cub3d *cub3d, t_direction_hit *hit_array, int i)
{
	t_position			dimensions;
	t_position			start;
	t_position			end;
	int					sprite_screen_x;
	t_sprite_draw_data	data;

	calculate_sprite_position(cub3d, i, &dimensions, &sprite_screen_x);
	calculate_sprite_boundaries(dimensions, sprite_screen_x, &start, &end);
	data.dimensions = dimensions;
	data.start = start;
	data.end = end;
	data.stripe = start.x;
	while (data.stripe < end.x)
	{
		data.tex_x = get_sprite_tex_x(data.stripe, dimensions.x,
				sprite_screen_x, cub3d->sprites[i]);
		draw_sprite_strip(cub3d, hit_array, i, &data);
		data.stripe++;
	}
}

void	draw_sprites(t_cub3d *cub3d, t_direction_hit *hit_array)
{
	int			i;
	t_vector2D	sprite_distance;
	float		angle_ratio;

	i = -1;
	while (++i < cub3d->sprite_count)
	{
		sprite_distance.x = cub3d->sprites[i]->pos.x - cub3d->player.x;
		sprite_distance.y = cub3d->sprites[i]->pos.y - cub3d->player.y;
		cub3d->sprites[i]->distance = sprite_distance.x * sprite_distance.x
			+ sprite_distance.y * sprite_distance.y;
		angle_ratio = 1.0 / (cub3d->plane.x * cub3d->dir.y - cub3d->dir.x
				* cub3d->plane.y);
		cub3d->sprites[i]->transform.x = angle_ratio * (cub3d->dir.y
				* sprite_distance.x - cub3d->dir.x * sprite_distance.y);
		cub3d->sprites[i]->transform.y = angle_ratio * (-cub3d->plane.y
				* sprite_distance.x + cub3d->plane.x * sprite_distance.y);
	}
	sort_sprites(cub3d);
	i = -1;
	while (++i < cub3d->sprite_count)
		draw_sprite(cub3d, hit_array, i);
}
