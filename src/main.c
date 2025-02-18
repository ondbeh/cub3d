/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:11:15 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/18 15:09:26 by kmuhlbau         ###   ########.fr       */
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

	(void)argv;
	cub3d.map = NULL;
	if (argc != 2)
		exit_error("Wrong number of arguments", &cub3d);
	cub3d_init(&cub3d);
	print_map(cub3d);
	draw_scene(&cub3d);
	mlx_loop(cub3d.mlx);
	exit_success(&cub3d);
}
