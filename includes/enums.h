/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:40:46 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/18 13:01:06 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_wall_side
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST
}	t_wall_side;

typedef enum e_texture_path
{
	TEXTURE_PATH_N,
	TEXTURE_PATH_S,
	TEXTURE_PATH_W,
	TEXTURE_PATH_E,
}	t_texture_path;

#endif