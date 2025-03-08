/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:26:54 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/08 21:19:58by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**grid;
	if (argc != 2)
		handle_error("[ERROR] Invalid no. of arg.");
	validate_file_format(argv[1]);
	check_file_access(argv[1]);

	// Parse through the logic of map into a data struct
	grid = parse_map_to_2d_array(argv[1]);
	if (!grid)
	{
		// Free dynamically allocated memory assigned during parse_map_to_2d_array() 
		handle_error("[ERROR] Invalid map input.");
	}
	// Validate these rules of the map
	// Parse through the map
	// Interact with map for player
	// Clean up and exit

	return (0);
}