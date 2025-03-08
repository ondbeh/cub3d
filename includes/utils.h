/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:14:58 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/03/08 13:14:59 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include <math.h>
# include <stdlib.h>

float	vector_size(t_vector2D vector);
void	vector_set_size(t_vector2D *vector, float size);
void	free_split(char **split);
int		ft_isspace(char c);
void	toggle_door(t_cub3d *cub3d);

#endif
