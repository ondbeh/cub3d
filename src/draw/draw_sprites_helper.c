/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:22:23 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 14:36:16 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	sort_sprites(t_cub3d *cub3d)
{
	int			i;
	int			j;
	t_sprite	*temp;

	i = 0;
	while (i < cub3d->sprite_count)
	{
		j = 0;
		while (j < cub3d->sprite_count - 1)
		{
			if (cub3d->sprites[j]->distance < cub3d->sprites[j + 1]->distance)
			{
				temp = cub3d->sprites[j];
				cub3d->sprites[j] = cub3d->sprites[j + 1];
				cub3d->sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	calculate_sprite_position(t_cub3d *cub3d, int i, t_position *dimensions,
		int *sprite_screen_x)
{
	*sprite_screen_x = (int)((SCREEN_WIDTH / 2) * (1
				+ cub3d->sprites[i]->transform.x
				/ cub3d->sprites[i]->transform.y));
	dimensions->y = abs((int)(SCREEN_HEIGHT / (cub3d->height_multiplier
					* cub3d->sprites[i]->transform.y)));
	dimensions->x = abs((int)(SCREEN_HEIGHT / (cub3d->height_multiplier
					* cub3d->sprites[i]->transform.y)));
}

void	calculate_sprite_boundaries(t_position dimensions, int sprite_screen_x,
		t_position *start, t_position *end)
{
	start->y = -dimensions.y / 2 + SCREEN_HEIGHT / 2;
	if (start->y < 0)
		start->y = 0;
	end->y = dimensions.y / 2 + SCREEN_HEIGHT / 2;
	if (end->y >= SCREEN_HEIGHT)
		end->y = SCREEN_HEIGHT - 1;
	start->x = -dimensions.x / 2 + sprite_screen_x;
	if (start->x < 0)
		start->x = 0;
	end->x = dimensions.x / 2 + sprite_screen_x;
	if (end->x >= SCREEN_WIDTH)
		end->x = SCREEN_WIDTH - 1;
}
