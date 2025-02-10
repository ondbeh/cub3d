/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:13:39 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 10:43:37 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "defines.h"
#include "enums.h"

typedef struct s_vector2D
{
    double x;
    double y;
} t_vector2D;

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_cub3d
{
    char **map;
    mlx_texture_t *texture[4];
    mlx_t *mlx;
    mlx_image_t *img;
    t_vector2D player;
    t_vector2D dir;
    t_vector2D plane;
    int ceiling_color;
    int floor_color;
    int map_width;
    int map_height;
} t_cub3d;

typedef struct s_direction_hit
{
    double distance;
    double wall_x;
    t_wall_side wall_side;
} t_direction_hit;

#endif