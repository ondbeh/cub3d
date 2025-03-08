/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:13:39 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 14:23:17 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "defines.h"
# include "enums.h"
# include "libft.h"

typedef struct s_vector2D
{
	float				x;
	float				y;
}						t_vector2D;

typedef struct s_position
{
	int					x;
	int					y;
}						t_position;

typedef struct s_sprite
{
	t_vector2D			pos;
	char				*texture;
	mlx_texture_t		*texture_ptr;
	float				distance;
	t_vector2D			transform;
}						t_sprite;

typedef struct s_cub3d
{
	char				**map;
	t_list				*map_lines;
	mlx_texture_t		*texture[4];
	mlx_t				*mlx;
	mlx_image_t			*img;
	mlx_image_t			*minimap_image;
	mlx_win_cursor_t	*cursor;
	t_sprite			*sprites[MAX_SPRITE_COUNT];
	bool				minimap_maximized;
	t_vector2D			player;
	t_vector2D			dir;
	t_vector2D			plane;
	float				height_multiplier;
	float				rotation_angle;
	int					ceiling_color;
	int					floor_color;
	int					map_width;
	int					map_height;
	int					sprite_count;
	mlx_image_t			*fps_image;

}						t_cub3d;

typedef struct s_direction_hit
{
	float				distance;
	float				wall_x;
	t_wall_side			wall_side;
}						t_direction_hit;

typedef struct s_textures
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
}						t_textures;

typedef struct s_sprite_draw_data
{
	t_position			dimensions;
	t_position			start;
	t_position			end;
	int					stripe;
	int					tex_x;
}						t_sprite_draw_data;

#endif
