/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:02:57 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/18 14:37:42 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

// static char	**map_init(void)
// {
// 	int		i;
// 	int		j;
// 	char	**map;

// 	map = ft_calloc(11, sizeof(char *));
// 	if (!map)
// 		exit_error("malloc failed", NULL);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		map[i] = ft_calloc(11, sizeof(char));
// 		if (!map[i])
// 			exit_error("malloc failed", NULL);
// 		j = -1;
// 		while (++j < 10)
// 			map[i][j] = (i == 0 || j == 0 || i == 9 || j == 9 || (i % 3 == 0
// 						&& j % 3 == 0)) + '0';
// 		i++;
// 	}
// 	return (map);
// }

static void	set_default_values(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->img = NULL;
	cub3d->last_frame_time = 0;
	cub3d->fps_image = NULL;
	cub3d->minimap_image = NULL;
	cub3d->minimap_maximized = false;
	cub3d->cursor = NULL;
	cub3d->plane.x = 0;
	cub3d->plane.y = 0.66;
	cub3d->height_multiplier = BASE_HEIGHT_MULTIPLIER;
	cub3d->rotation_angle = BASE_ROTATION_ANGLE;
}

void	print_cub_struct(t_cub3d *cub3d)
{
	printf("cub3d->map_width: %d\n", cub3d->map_width);
	printf("cub3d->map_height: %d\n", cub3d->map_height);
	printf("cub3d->player.x: %f\n", cub3d->player.x);
	printf("cub3d->player.y: %f\n", cub3d->player.y);
	printf("cub3d->dir.x: %f\n", cub3d->dir.x);
	printf("cub3d->dir.y: %f\n", cub3d->dir.y);
	printf("cub3d->ceiling_color: %d\n", cub3d->ceiling_color);
	printf("cub3d->floor_color: %d\n", cub3d->floor_color);
	printf("cub3d->mlx: %p\n", cub3d->mlx);
	printf("cub3d->img: %p\n", cub3d->img);
	printf("cub3d->last_frame_time: %f\n", cub3d->last_frame_time);
	printf("cub3d->fps_image: %p\n", cub3d->fps_image);
	printf("cub3d->minimap_image: %p\n", cub3d->minimap_image);
	printf("cub3d->minimap_maximized: %d\n", cub3d->minimap_maximized);
	printf("cub3d->cursor: %p\n", cub3d->cursor);
	printf("cub3d->plane.x: %f\n", cub3d->plane.x);
	printf("cub3d->plane.y: %f\n", cub3d->plane.y);
	printf("cub3d->height_multiplier: %f\n", cub3d->height_multiplier);
	printf("cub3d->rotation_angle: %f\n", cub3d->rotation_angle);
	// print ll map
	t_list *current = cub3d->map_lines;
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}

void	cub3d_init(t_cub3d *cub3d)
{
	t_textures	textures;

	textures = (t_textures){NULL, NULL, NULL, NULL};
	cub3d->map_lines = NULL;
	set_default_values(cub3d);
	// check map is valid and parsed into multi-dimensional array cub3d->map
	parse_file(cub3d, &textures, "map.cub");
	printf("textures: %s, %s, %s, %s\n", textures.north, textures.south,
		textures.west, textures.east);
	load_textures(cub3d, textures);
	cub3d->map_width = 10;
	cub3d->map_height = 10;
	cub3d->player.x = 2.5;
	cub3d->player.y = 2.5;
	cub3d->dir.x = 1;
	cub3d->dir.y = 0;
	cub3d->ceiling_color = 0x87CEEBFF;
	cub3d->floor_color = 0x8B4513FF;
	print_cub_struct(cub3d);
	mlx_prepare(cub3d);
}
