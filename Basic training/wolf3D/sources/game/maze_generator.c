/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:17 by djast             #+#    #+#             */
/*   Updated: 2019/10/07 13:43:45 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_info_from_file(t_map *map_info, t_player *player, int fd)
{
	char *line;
	char **numbers;

	get_next_line(fd, &line);
	if (line == NULL || countwords(line, ' ') != 2)
		return (ERROR_NON_VALID_FILE);
	numbers = ft_strsplit(line, ' ');
	map_info->size_x = ft_atoi(numbers[0]);
	map_info->size_y = ft_atoi(numbers[1]);
	free(numbers[0]);
	free(numbers[1]);
	free(numbers);
	free(line);
	get_next_line(fd, &line);
	if (line == NULL || countwords(line, ' ') != 3)
		return (ERROR_NON_VALID_FILE);
	numbers = ft_strsplit(line, ' ');
	init_player(player, numbers);
	free(numbers[0]);
	free(numbers[1]);
	free(numbers[2]);
	free(numbers);
	free(line);
	return (0);
}

static int	check_map(t_map *map_info, t_player *player)
{
	int i;

	if (map_info->map[(player->y - 10) / 64][(player->x - 10) / 64] == 1)
		return (0);
	i = 0;
	while (i < map_info->size_x)
	{
		if (map_info->map[0][i] == 0 ||
								map_info->map[map_info->size_y - 1][i++] == 0)
			return (0);
	}
	i = 0;
	while (i < map_info->size_y)
	{
		if (map_info->map[i][0] == 0 ||
								map_info->map[i++][map_info->size_x - 1] == 0)
			return (0);
	}
	if (player->point_of_view < 0 || player->point_of_view > 360)
		return (0);
	return (1);
}

t_map		*get_map_from_file(t_player *player, int fd)
{
	t_map *map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (get_info_from_file(map_info, player, fd) == ERROR_NON_VALID_FILE ||
	player->x < 0 || player->y < 0 ||
	player->x > 64 * map_info->size_x || player->y > 64 * map_info->size_y)
	{
		free(map_info);
		return (NULL);
	}
	init_map(map_info);
	if (read_map(map_info, fd) == ERROR_NON_VALID_FILE ||
				check_map(map_info, player) == 0)
	{
		free(map_info);
		return (NULL);
	}
	close(fd);
	return (map_info);
}
