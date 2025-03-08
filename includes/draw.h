/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:14:02 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 14:26:43 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "exit.h"
# include "structs.h"
# include <math.h>

void	draw_scene(t_cub3d *cub3d);
void	calculate_rays(t_cub3d *cub3d, t_direction_hit *hit_array);
void	draw_rays(t_cub3d *cub3d, t_direction_hit *hit_array);
void	calculate_fps(t_cub3d *cub3d);
void	create_minimap(t_cub3d *cub3d);
void	draw_sprites(t_cub3d *cub3d, t_direction_hit *hit_array);
void	sort_sprites(t_cub3d *cub3d);
void	calculate_sprite_position(t_cub3d *cub3d, int i, t_position *dimensions,
			int *sprite_screen_x);
void	calculate_sprite_boundaries(t_position dimensions, int sprite_screen_x,
			t_position *start, t_position *end);
#endif
