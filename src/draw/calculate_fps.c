/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:44:15 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 14:44:15 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	calculate_fps(t_cub3d *cub3d)
{
	double	current_time;
	double	delta_time;
	char	*fps;
	char	*fps_text;

	current_time = mlx_get_time();
	delta_time = (current_time - cub3d->last_frame_time) * 1000;
	if (delta_time > 0)
	{
		fps = ft_itoa((int)(1000 / (int)delta_time));
		fps_text = ft_strjoin("FPS: ", fps);
		if (cub3d->fps_image)
			mlx_delete_image(cub3d->mlx, cub3d->fps_image);
		cub3d->fps_image = mlx_put_string(cub3d->mlx, fps_text, 0, 0);
		if (!cub3d->fps_image)
			exit_error("mlx_put_string failed", cub3d);
		free(fps);
		free(fps_text);
	}
	cub3d->last_frame_time = current_time;
}
