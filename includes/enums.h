/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:40:46 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 11:36:51 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_wall_side
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST,
	WALL_DOOR
}	t_wall_side;

typedef enum e_texture_path
{
	TEXTURE_PATH_N,
	TEXTURE_PATH_S,
	TEXTURE_PATH_W,
	TEXTURE_PATH_E,
	TEXTURE_PATH_DOOR
}	t_texture_path;

#endif