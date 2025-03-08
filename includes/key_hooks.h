/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:46:19 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:25 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOKS_H
# define KEY_HOOKS_H

# include "draw.h"
# include "exit.h"
# include "structs.h"
# include "utils.h"

void	key_hook_control(mlx_key_data_t keydata, void *param);
void	loop_hook_control(void *par);
void	mouse_hook_control(mouse_key_t button, action_t action,
			modifier_key_t mods, void *par);
void	scroll_hook_control(double x_delta, double y_delta, void *par);
void	handle_key_w(t_cub3d *cub3d);
void	handle_key_s(t_cub3d *cub3d);
void	handle_key_a(t_cub3d *cub3d);
void	handle_key_d(t_cub3d *cub3d);
void	rotate_left(t_cub3d *cub3d, float rotation_multiplier);
void	rotate_right(t_cub3d *cub3d, float rotation_multiplier);

#endif
