/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:51:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/18 14:26:23 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "exit.h"
# include "libft.h"
# include "structs.h"
# include "utils.h"
# include <fcntl.h>

void	parse_file(t_cub3d *cub3d, t_textures *textures, char *data_file);
int		validate_map_and_textures(t_cub3d *cub3d, t_textures *textures);
void	map_ll_to_array(t_cub3d *cub3d);

#endif
