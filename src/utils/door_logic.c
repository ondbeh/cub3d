/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:18:49 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/03/08 13:15:44 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_position	get_door_pos(t_cub3d *cub3d)
{
	t_position	door_pos;
	int			i;
	t_position	check_pos;

	door_pos = (t_position){-1, -1};
	i = 1;
	while (i <= DOOR_CHECK_DISTANCE)
	{
		check_pos.x = (int)(cub3d->player.x + cub3d->dir.x * i);
		check_pos.y = (int)(cub3d->player.y + cub3d->dir.y * i);
		if (check_pos.x >= 0 && check_pos.x < cub3d->map_width
			&& check_pos.y >= 0 && check_pos.y < cub3d->map_height)
		{
			if (cub3d->map[check_pos.y][check_pos.x] == 'D'
				|| cub3d->map[check_pos.y][check_pos.x] == 'E')
			{
				door_pos.x = check_pos.x;
				door_pos.y = check_pos.y;
				return (door_pos);
			}
		}
		i++;
	}
	return (door_pos);
}

void	toggle_door(t_cub3d *cub3d)
{
	t_position	player_pos;
	t_position	door_pos;

	player_pos = (t_position){cub3d->player.x, cub3d->player.y};
	door_pos = get_door_pos(cub3d);
	if (door_pos.x != -1 && door_pos.y != -1)
	{
		if (cub3d->map[door_pos.y][door_pos.x] == 'D')
			cub3d->map[door_pos.y][door_pos.x] = 'E';
		else if (cub3d->map[door_pos.y][door_pos.x] == 'E')
			cub3d->map[door_pos.y][door_pos.x] = 'D';
	}
}
