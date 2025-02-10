/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:14:02 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 14:49:51 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "structs.h"
#include "exit.h"
#include <math.h>

void draw_scene(t_cub3d *cub3d);
void put_floor_ceiling(t_cub3d *cub3d);
void calculate_rays(t_cub3d *cub3d, t_direction_hit *hit_array);
void draw_rays(t_cub3d *cub3d, t_direction_hit *hit_array);
void calculate_fps(t_cub3d *cub3d);

#endif