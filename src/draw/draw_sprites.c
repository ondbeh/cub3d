/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:48:40 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 10:53:09 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_sprites(t_cub3d *cub3d, t_direction_hit *hit_array)
{
	int	i;

	(void)hit_array;
	i = 0;
	while (i < cub3d->sprite_count)
	{
		printf("draw sprite %f / %f\n", cub3d->sprites[i]->pos.x,
			cub3d->sprites[i]->pos.y);
		i++;
	}
}
