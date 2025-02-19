/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ll_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:50:58 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/19 15:07:50 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_direction(t_cub3d *cub3d, char c)
{
	cub3d->dir.x = 0;
	cub3d->dir.y = 0;
	cub3d->plane.x = 0;
	cub3d->plane.y = 0;
	if (c == 'N')
		cub3d->dir.y = -1;
	else if (c == 'S')
		cub3d->dir.y = 1;
	else if (c == 'E')
		cub3d->dir.x = 1;
	else if (c == 'W')
		cub3d->dir.x = -1;
	if (c == 'N')
		cub3d->plane.x = 0.66;
	else if (c == 'S')
		cub3d->plane.x = -0.66;
	else if (c == 'E')
		cub3d->plane.y = 0.66;
	else if (c == 'W')
		cub3d->plane.y = -0.66;
}

static int	check_map_line(t_cub3d *cub3d, int i)
{
	int	j;

	j = 0;
	while (cub3d->map[i][j])
	{
		if ((cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S'
				|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')
			&& (cub3d->player.x == -1 || cub3d->player.y == -1))
		{
			cub3d->player.x = j + 0.5;
			cub3d->player.y = i + 0.5;
			set_direction(cub3d, cub3d->map[i][j]);
			cub3d->map[i][j] = '0';
		}
		else if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S'
			|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')
			return (0);
		j++;
	}
	return (1);
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
		if (!check_map_line(cub3d, i))
			exit_error("Invalid map line", cub3d);
		i++;
		current = current->next;
	}
}
