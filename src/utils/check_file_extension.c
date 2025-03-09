/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:52:04 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/03/09 11:52:21 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_file_extension(char *filename)
{
	int		len;
	char	*extension;

	if (!filename)
		exit_error("No filename provided", NULL);
	len = ft_strlen(filename);
	if (len < 5)
		exit_error("Invalid filename: too short", NULL);
	extension = filename + len - 4;
	if (ft_strncmp(extension, ".cub", 4) != 0)
		exit_error("Invalid file extension: must be .cub", NULL);
}
