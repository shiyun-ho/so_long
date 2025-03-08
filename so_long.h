/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:30:56 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/08 21:40:54 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

/**
 * @brief: Structure for validating map data before
 * 			transitioning to game logic.
 */
typedef struct	s_map_val
{
	char	**grid;
	int		rows;
	int		cols;
}				t_map_val;

// Error Utils
void	handle_error(char *error_msg);

// Validation Utils
void	validate_file_format(char *file_name);
void	check_file_access(char *file_name);

#endif