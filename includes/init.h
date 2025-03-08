/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:04:07 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 13:15:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../libft/inc/libft.h"
# include "exit.h"
# include "key_hooks.h"
# include "parsing.h"
# include "structs.h"
# include <stdio.h>

void	cub3d_init(t_cub3d *cub3d, char *filename);
void	mlx_prepare(t_cub3d *cub3d);
void	load_textures(t_cub3d *cub3d, t_textures textures);

#endif
