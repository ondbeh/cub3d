/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:02:57 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/19 17:20:58 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	set_default_values(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->img = NULL;
	cub3d->fps_image = NULL;
	cub3d->minimap_image = NULL;
	cub3d->minimap_maximized = false;
	cub3d->cursor = NULL;
	cub3d->plane.x = 0;
	cub3d->plane.y = 0.66;
	cub3d->player.x = -1;
	cub3d->player.y = -1;
	cub3d->height_multiplier = BASE_HEIGHT_MULTIPLIER;
	cub3d->rotation_angle = BASE_ROTATION_ANGLE;
	cub3d->map = NULL;
	cub3d->map_lines = NULL;
	cub3d->ceiling_color = 0;
	cub3d->floor_color = 0;
}

static void	get_map_dimensions(t_cub3d *cub3d)
{
	t_list	*current;
	int		map_width;
	int		map_height;

	current = cub3d->map_lines;
	map_width = 0;
	map_height = 0;
	while (current)
	{
		if (ft_strlen(current->content) > map_width)
			map_width = ft_strlen(current->content);
		current = current->next;
		map_height++;
	}
	cub3d->map_width = map_width;
	cub3d->map_height = map_height;
}

void	cub3d_init(t_cub3d *cub3d)
{
	t_textures	textures;

	textures = (t_textures){NULL, NULL, NULL, NULL};
	cub3d->map_lines = NULL;
	cub3d->ceiling_color = 0x87CEEBFF;
	cub3d->floor_color = 0x8B4513FF;
	set_default_values(cub3d);
	parse_file(cub3d, &textures, "map.cub");
	load_textures(cub3d, textures);
	free(textures.east);
	free(textures.north);
	free(textures.south);
	free(textures.west);
	get_map_dimensions(cub3d);
	map_ll_to_array(cub3d);
	if (!validate_map_and_textures(cub3d, &textures))
		exit_error("Invalid map configuration", cub3d);
	mlx_prepare(cub3d);
}
