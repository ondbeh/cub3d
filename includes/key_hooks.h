/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:46:19 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 18:46:30 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOKS_H
# define KEY_HOOKS_H

# include "draw.h"
# include "exit.h"
# include "structs.h"

void	key_hook_control(void *par);
void	handle_key_w(t_cub3d *cub3d);
void	handle_key_s(t_cub3d *cub3d);
void	handle_key_a(t_cub3d *cub3d);
void	handle_key_d(t_cub3d *cub3d);
void	handle_key_left(t_cub3d *cub3d);
void	handle_key_right(t_cub3d *cub3d);

#endif