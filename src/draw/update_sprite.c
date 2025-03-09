/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 10:59:03 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 11:36:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	update_sprite_animation(t_cub3d *cub3d, double current_time)
{
	int		i;
	double	animation_speed;

	animation_speed = BASE_ANIMATION_SPEED;
	i = 0;
	while (i < cub3d->sprite_count)
	{
		if (cub3d->sprites[i]->count > 1)
		{
			if (current_time
				- cub3d->sprites[i]->last_frame_time > animation_speed)
			{
				cub3d->sprites[i]->current_frame += 1;
				cub3d->sprites[i]->current_frame %= cub3d->sprites[i]->count;
				cub3d->sprites[i]->last_frame_time = current_time;
			}
		}
		i++;
	}
}
