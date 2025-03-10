/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:15:04 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/10 20:45:47 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

int		calculate_rows(int fd, void *buffer, size_t count)
{
	int		i;
	int		row_count;

	i = 0;
	row_count = 0;
	while (read(fd, buffer, count) > 0)
	{
		while (buffer[i])
		{
			if (buffer[i] == '\0')
				row_count++;
			i++;
		}
	}
}

int		calculate_cols(int fd, void *buffer, size_t count)
{
	int		i;
	int		col_count;

	i = 0;
	row_count = 0;
	while (read(fd, buffer, count) > 0)
	{
		while (buffer[i])
		{
			if (buffer[i] == '\0')
			{
				if (col_count == 0)
					col_count = i;
			}
			i++;
		}
	}
}

char	**parse_map_to_2d_array(char *filename)
{
	int		fd;
	char	buffer[10];
	char	**map;
	int		y;
	int		x;

	fd = open(filename, 0_RDONLY);
	map = NULL;
	
	// Count the rows and columns
	/**
	 * Should I validate and free the stufd lat
	 */
	y = calculate_rows(fd, buffer, 10);
	x = calculate_cols(fd, buffer, 10);
}