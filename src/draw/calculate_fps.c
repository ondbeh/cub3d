/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:26:40 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 13:15:23 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	calculate_fps(t_cub3d *cub3d)
{
	double	delta_time;
	char	*fps;
	char	*fps_text;

	delta_time = cub3d->mlx->delta_time;
	if (delta_time > 0)
	{
		fps = ft_itoa((int)(1 / delta_time));
		fps_text = ft_strjoin("FPS: ", fps);
		if (cub3d->fps_image)
			mlx_delete_image(cub3d->mlx, cub3d->fps_image);
		cub3d->fps_image = mlx_put_string(cub3d->mlx, fps_text, 0, 0);
		if (!cub3d->fps_image)
			exit_error("mlx_put_string failed", cub3d);
		free(fps);
		free(fps_text);
	}
}
