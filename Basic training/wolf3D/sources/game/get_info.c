/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:37:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/07 13:22:07 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_map(t_map *map_info)
{
	int i;

	i = 0;
	map_info->map = (int **)malloc(sizeof(int *) * map_info->size_y);
	while (i < map_info->size_y)
		map_info->map[i++] = (int *)malloc(sizeof(int) * map_info->size_x);
}

int			read_map(t_map *map_info, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**numbers;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (countwords(line, ' ') != map_info->size_x)
			return (ERROR_NON_VALID_FILE);
		numbers = ft_strsplit(line, ' ');
		j = 0;
		while (j < map_info->size_x)
		{
			if (ft_strcmp(numbers[j], "0") != 0 &&
					ft_strcmp(numbers[j], "1") != 0)
				return (ERROR_NON_VALID_FILE);
			map_info->map[i][j] = ft_atoi(numbers[j]);
			free(numbers[j++]);
		}
		free(numbers);
		free(line);
		i++;
	}
	return (0);
}

void		init_player(t_player *player, char **numbers)
{
	player->x = ft_atoi(numbers[0]);
	player->y = ft_atoi(numbers[1]);
	player->point_of_view = ft_atoi(numbers[2]);
	player->is_shooting = 0;
	player->shooting_frame = PISTOL_LAST_FRAME;
	player->mouse_x = SIZE_WIN_X / 2;
	player->mouse_y = SIZE_WIN_Y / 2;
}
