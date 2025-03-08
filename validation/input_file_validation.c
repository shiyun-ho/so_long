/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:34:58 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/03/08 20:43:38by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	validate_file_format(char *file_name)
{
	int		str_len;
	char	*file_extension;

	str_len = ft_strlen(file_name);
	if (str_len < 4)
		handle_error("[ERROR] Insufficient length for file name.");
	file_extension = ft_substr(file_name, str_len - 4, 4);
	if (!file_extension)
		handle_error("[ERROR] Unable to apply ft_substr() on file.");
	if (ft_strncmp(file_extension, ".ber", 4) != 0)
	{
		free(file_extension);
		handle_error("[ERROR] File does not end with .ber.");
	}
	free(file_extension);
}

void	check_file_access(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror("open");	
	else
		close(fd);
}