/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:02:57 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 12:00:42 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	set_default_values(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	cub3d->mlx = NULL;
	cub3d->img = NULL;
	cub3d->fps_image = NULL;
	cub3d->minimap_image = NULL;
	cub3d->minimap_maximized = false;
	cub3d->texture[WALL_NORTH] = NULL;
	cub3d->texture[WALL_SOUTH] = NULL;
	cub3d->texture[WALL_WEST] = NULL;
	cub3d->texture[WALL_EAST] = NULL;
	cub3d->texture[WALL_DOOR] = NULL;
	cub3d->cursor = NULL;
	cub3d->plane = (t_vector2D){0, BASE_FOV};
	cub3d->player = (t_vector2D){-1, -1};
	cub3d->height_multiplier = BASE_HEIGHT_MULTIPLIER;
	cub3d->rotation_angle = BASE_ROTATION_ANGLE;
	cub3d->map = NULL;
	cub3d->map_lines = NULL;
	cub3d->ceiling_color = -1;
	cub3d->floor_color = -1;
	cub3d->sprite_count = 0;
	while (i < MAX_SPRITE_COUNT)
		cub3d->sprites[i++] = NULL;
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

void	cub3d_init(t_cub3d *cub3d, char *filename)
{
	t_textures	textures;

	textures = (t_textures){NULL, NULL, NULL, NULL, NULL};
	cub3d->map_lines = NULL;
	set_default_values(cub3d);
	parse_file(cub3d, &textures, filename);
	load_textures(cub3d, textures);
	free(textures.east);
	free(textures.north);
	free(textures.south);
	free(textures.west);
	free(textures.door);
	get_map_dimensions(cub3d);
	map_ll_to_array(cub3d);
	if (!validate_map_and_textures(cub3d, &textures))
		exit_error("Invalid map configuration", cub3d);
	mlx_prepare(cub3d);
}
