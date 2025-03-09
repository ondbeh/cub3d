/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:14:02 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/09 11:00:47 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "exit.h"
# include "structs.h"
# include <math.h>

void		draw_scene(t_cub3d *cub3d);
void		calculate_rays(t_cub3d *cub3d, t_direction_hit *hit_array);
void		draw_rays(t_cub3d *cub3d, t_direction_hit *hit_array);
void		calculate_fps(t_cub3d *cub3d);
void		create_minimap(t_cub3d *cub3d);
void		draw_sprites(t_cub3d *cub3d, t_direction_hit *hit_array);
void		sort_sprites(t_cub3d *cub3d);
void		calculate_sprite_position(t_cub3d *cub3d, int i,
				t_position *dimensions, int *sprite_screen_x);
void		calculate_sprite_boundaries(t_position dimensions,
				int sprite_screen_x, t_position *start, t_position *end);
uint32_t	get_tile_color(char tile);
void		prepare_dda_params(t_cub3d *cub3d, t_vector2D ray_dir,
				t_dda_params *params);
void		prepare_delta_dist(t_vector2D ray_dir, t_vector2D *delta_dist);
void		prepare_step_and_sidestep(t_cub3d *cub3d, t_dda_params *par);
void		update_sprite_animation(t_cub3d *cub3d, double current_time);

#endif
