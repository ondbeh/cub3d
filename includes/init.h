/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:04:07 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 10:50:09 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
#define INIT_H

#include "../libft/inc/libft.h"
#include "structs.h"
#include "exit.h"
#include "key_hooks.h"
#include <stdio.h>

void cub3d_init(t_cub3d *cub3d);
void mlx_prepare(t_cub3d *cub3d);
void load_textures(t_cub3d *cub3d);

#endif