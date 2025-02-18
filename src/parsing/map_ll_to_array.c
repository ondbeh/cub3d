/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ll_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:50:58 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/18 16:34:54 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	check_map_line(t_cub3d *cub3d, int i)
{
	int	j;

	j = 0;
	while (cub3d->map[i][j])
	{
		if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S'
			|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')
		{
			cub3d->map[i][j] = '0';
			cub3d->player.x = i + 0.5;
			cub3d->player.y = j + 0.5;
		}
		j++;
	}
}

void	map_ll_to_array(t_cub3d *cub3d)
{
	t_list	*current;
	int		i;
	char	*line;

	current = cub3d->map_lines;
	cub3d->map = ft_calloc(cub3d->map_height, sizeof(char *));
	if (!cub3d->map)
		exit_error("malloc failed", cub3d);
	i = 0;
	while (current)
	{
		line = current->content;
		cub3d->map[i] = ft_calloc(cub3d->map_width + 1, sizeof(char));
		if (!cub3d->map[i])
			exit_error("malloc failed", cub3d);
		ft_strlcpy(cub3d->map[i], line, cub3d->map_width + 1);
		check_map_line(cub3d, i);
		i++;
		current = current->next;
	}
}
