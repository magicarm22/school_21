/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:07:03 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 17:25:50 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			check_line(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	line = *line == '-' ? line + 1 : line;
	while (*line != '\0' && *line >= '0' && *line <= '9')
		line++;
	if (*line == '\0')
		return (1);
	if (*line == ',')
	{
		line++;
		if (*line == '0')
			line++;
		else
			return (-1);
		if (*line == 'x')
			line++;
		else
			return (-1);
		while ((i++ < 6 && *line >= '0' && *line <= '9') ||
			(*line >= 'A' && *line <= 'F') || (*line >= 'a' && *line <= 'f'))
			line++;
		mlx->is_color = 1;
	}
	return (*line != '\0' ? -1 : 1);
}

int			check_map(int fd, t_mlx *info_map)
{
	char	*line;
	char	**char_map;
	int		size_y;

	size_y = 0;
	while (get_next_line(fd, &line))
	{
		char_map = ft_strsplit(line, ' ');
		if (info_map->size_map_x < ft_arrc_size(char_map))
			info_map->size_map_x = ft_arrc_size(char_map);
		while (*char_map++)
		{
			if (check_line(info_map, *(char_map - 1)) == -1)
				return (-1);
		}
		size_y++;
	}
	info_map->size_map_y = size_y;
	return (1);
}
