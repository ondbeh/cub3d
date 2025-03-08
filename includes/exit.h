/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:13 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 13:15:09 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "../libft/inc/libft.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>

void	exit_error(char *message, t_cub3d *cub3d);
void	exit_success(t_cub3d *cub3d);
void	cleanup(t_cub3d *cub3d);

#endif