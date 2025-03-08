/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:31:52 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 10:53:22 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_sprite(t_cub3d *cub3d, char **split)
{
	t_sprite	*sprite;

	if (cub3d->sprite_count >= MAX_SPRITE_COUNT)
		exit_error("Too many sprites", cub3d);
	if (!split[0] || !split[1] || !split[2] || !split[3] || split[4])
		exit_error("Invalid sprite line", cub3d);
	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		exit_error("Memory allocation failed", cub3d);
	sprite->pos.x = ft_atoi(split[1]) + 0.5;
	sprite->pos.y = ft_atoi(split[2]) + 0.5;
	sprite->texture_ptr = mlx_load_png(split[3]);
	if (!sprite->texture_ptr)
	{
		free(sprite);
		free_split(split);
		exit_error("mlx_load_png failed", cub3d);
	}
	sprite->distance = 0;
	cub3d->sprites[cub3d->sprite_count++] = sprite;
}
