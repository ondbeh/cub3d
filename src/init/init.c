/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:02:57 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/11 23:05:37 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static char	**map_init(void)
{
	int		i;
	int		j;
	char	**map;

	map = ft_calloc(11, sizeof(char *));
	if (!map)
		exit_error("malloc failed", NULL);
	i = 0;
	while (i < 10)
	{
		map[i] = ft_calloc(11, sizeof(char));
		if (!map[i])
			exit_error("malloc failed", NULL);
		j = -1;
		while (++j < 10)
			map[i][j] = (i == 0 || j == 0 || i == 9 || j == 9 || (i % 3 == 0
						&& j % 3 == 0)) + '0';
		i++;
	}
	return (map);
}

void	cub3d_init(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->img = NULL;
	cub3d->last_frame_time = 0;
	cub3d->fps_image = NULL;
	cub3d->minimap_image = NULL;
	cub3d->minimap_maximized = false;
	cub3d->cursor = NULL;
	cub3d->map = map_init();
	load_textures(cub3d);
	cub3d->map_width = 10;
	cub3d->map_height = 10;
	cub3d->player.x = 2.5;
	cub3d->player.y = 2.5;
	cub3d->dir.x = 1;
	cub3d->dir.y = 0;
	cub3d->plane.x = 0;
	cub3d->plane.y = 0.66;
	cub3d->height_multiplier = BASE_HEIGHT_MULTIPLIER;
	cub3d->rotation_angle = BASE_ROTATION_ANGLE;
	cub3d->ceiling_color = 0x87CEEBFF;
	cub3d->floor_color = 0x8B4513FF;
	mlx_prepare(cub3d);
}
