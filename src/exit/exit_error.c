/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:33:59 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/18 13:18:02 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	exit_error(char *message, t_cub3d *cub3d)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	if (cub3d)
		cleanup(cub3d);
	exit(1);
}
