/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:13 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/08 23:34:13 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
#define EXIT_H

#include "structs.h"
#include "../libft/inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

void exit_error(char *message, t_cub3d *cub3d);
void exit_success(t_cub3d *cub3d);
void cleanup(t_cub3d *cub3d);

#endif