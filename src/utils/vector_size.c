/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/10 22:25:14 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/10 22:25:14 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	vector_size(t_vector2D vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}

void	vector_set_size(t_vector2D *vector, float size)
{
	float	current_size;

	current_size = vector_size(*vector);
	vector->x *= size / current_size;
	vector->y *= size / current_size;
}
