/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:02:57 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/08 23:02:57 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static char **map_init(void)
{
	int i;
	int j;

	char **map = ft_calloc(11, sizeof(char *));
	if (!map)
		exit_error("malloc failed", NULL);
	i = 0;
	while (i < 10)
	{
		map[i] = ft_calloc(11, sizeof(char));
		if (!map[i])
			exit_error("malloc failed", NULL);
		j = -1;
		while (++j < 10)
			map[i][j] = (i == 0 || j == 0 || i == 9 || j == 9) + '0';
		i++;
	}

	return (map);
}

void cub3d_init(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->img = NULL;
	cub3d->map = map_init();
	cub3d->player.x = 1;
	cub3d->player.y = 1;
	cub3d->dir.x = 0;
	cub3d->dir.y = 0;
	mlx_prepare(cub3d);
}