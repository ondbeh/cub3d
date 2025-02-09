/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:13:39 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/09 13:31:06 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "defines.h"

typedef struct s_vector2D
{
    double x;
    double y;
} t_vector2D;

typedef struct s_cub3d
{
    char **map;
    mlx_t *mlx;
    mlx_image_t *img;
    t_vector2D player;
    t_vector2D dir;
} t_cub3d;

#endif