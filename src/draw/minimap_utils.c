/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:39:59 by obehavka          #+#    #+#             */
/*   Updated: 2025/03/08 18:40:08 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

uint32_t	get_tile_color(char tile)
{
	if (tile == '0')
		return (0x999922CC);
	else if (tile == 'D')
		return (0xAA5500CC);
	else if (tile == 'E')
		return (0x00FF00CC);
	else
		return (0xFFFFFFCC);
}
