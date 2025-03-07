/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:11:15 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/07 10:19:11 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(t_cub3d cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d.map_height)
	{
		j = 0;
		while (j < cub3d.map_width)
		{
			if ((int)cub3d.player.x == i && (int)cub3d.player.y == j)
				printf("P");
			else
				printf("%c", cub3d.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		exit_error("Wrong number of arguments", NULL);
	cub3d.map = NULL;
	if (argc != 2)
		exit_error("Wrong number of arguments", NULL);
	cub3d_init(&cub3d, argv[1]);
	print_map(cub3d);
	draw_scene(&cub3d);
	mlx_loop(cub3d.mlx);
	exit_success(&cub3d);
}
