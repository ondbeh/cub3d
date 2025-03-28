/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:59:04 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 13:15:33 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hooks.h"

/*
 * Moves forward (key W).
 * Uses the player's direction (cub3d->dir)
	and SPEED_COEF to compute the new position.
 * Collision is checked on each axis using
	a defined collision offset PLAYER_SIZE.
 */
void	handle_key_w(t_cub3d *cub3d)
{
	t_vector2D	new_pos;
	t_vector2D	offset;

	new_pos.x = cub3d->player.x + cub3d->dir.x * SPEED_COEF;
	new_pos.y = cub3d->player.y + cub3d->dir.y * SPEED_COEF;
	offset = (t_vector2D){PLAYER_SIZE, PLAYER_SIZE};
	if (cub3d->dir.x < 0)
		offset.x = -PLAYER_SIZE;
	if (cub3d->dir.y < 0)
		offset.y = -PLAYER_SIZE;
	if (cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == '0'
		|| cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == 'E')
		cub3d->player.x = new_pos.x;
	if (cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == '0'
		|| cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == 'E')
		cub3d->player.y = new_pos.y;
}

/*
 * Moves backward (key S).
 * New position is computed by reversing the player's direction.
 * The collision offset is inverted relative to forward movement.
 */
void	handle_key_s(t_cub3d *cub3d)
{
	t_vector2D	new_pos;
	t_vector2D	offset;

	new_pos.x = cub3d->player.x - cub3d->dir.x * SPEED_COEF;
	new_pos.y = cub3d->player.y - cub3d->dir.y * SPEED_COEF;
	offset = (t_vector2D){PLAYER_SIZE, PLAYER_SIZE};
	if (cub3d->dir.x > 0)
		offset.x = -PLAYER_SIZE;
	if (cub3d->dir.y > 0)
		offset.y = -PLAYER_SIZE;
	if (cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == '0'
		|| cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == 'E')
		cub3d->player.x = new_pos.x;
	if (cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == '0'
		|| cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == 'E')
		cub3d->player.y = new_pos.y;
}

/*
 * Strafes left (key A).
 * The left strafe vector is derived as (dir.y,
	-dir.x) so that a player facing north (0, -1) will move west.
 * Collision is checked on each axis using
	a defined collision offset PLAYER_SIZE.
 */
void	handle_key_a(t_cub3d *cub3d)
{
	t_vector2D	new_pos;
	t_vector2D	offset;
	t_vector2D	strafe;

	strafe.x = cub3d->dir.y;
	strafe.y = -cub3d->dir.x;
	new_pos.x = cub3d->player.x + strafe.x * SPEED_COEF;
	new_pos.y = cub3d->player.y + strafe.y * SPEED_COEF;
	offset = (t_vector2D){PLAYER_SIZE, PLAYER_SIZE};
	if (strafe.x < 0)
		offset.x = -PLAYER_SIZE;
	if (strafe.y < 0)
		offset.y = -PLAYER_SIZE;
	if (cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == '0'
		|| cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == 'E')
		cub3d->player.x = new_pos.x;
	if (cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == '0'
		|| cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == 'E')
		cub3d->player.y = new_pos.y;
}

/*
 * Strafes right (key D).
 * The right strafe vector is derived as (-dir.y,
	dir.x) so that a player facing north (0, -1) will move east.
 * Collision is checked on each axis using
	a defined collision offset PLAYER_SIZE.
 */
void	handle_key_d(t_cub3d *cub3d)
{
	t_vector2D	new_pos;
	t_vector2D	offset;
	t_vector2D	strafe;

	strafe.x = -cub3d->dir.y;
	strafe.y = cub3d->dir.x;
	new_pos.x = cub3d->player.x + strafe.x * SPEED_COEF;
	new_pos.y = cub3d->player.y + strafe.y * SPEED_COEF;
	offset = (t_vector2D){PLAYER_SIZE, PLAYER_SIZE};
	if (strafe.x < 0)
		offset.x = -PLAYER_SIZE;
	if (strafe.y < 0)
		offset.y = -PLAYER_SIZE;
	if (cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == '0'
		|| cub3d->map[(int)cub3d->player.y][(int)(new_pos.x + offset.x)] == 'E')
		cub3d->player.x = new_pos.x;
	if (cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == '0'
		|| cub3d->map[(int)(new_pos.y + offset.y)][(int)cub3d->player.x] == 'E')
		cub3d->player.y = new_pos.y;
}
