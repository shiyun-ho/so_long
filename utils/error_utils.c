/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:29:44 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/08 21:19:14 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	handle_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}