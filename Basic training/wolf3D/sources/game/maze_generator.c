/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:17 by djast             #+#    #+#             */
/*   Updated: 2019/09/25 14:44:20 by eharrag-         ###   ########.fr       */
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
	get_next_line(fd, &line);
	if (line == NULL || countwords(line, ' ') != 3)
		return (ERROR_NON_VALID_FILE);
	numbers = ft_strsplit(line, ' ');
	init_player(player, numbers);
	free(numbers[0]);
	free(numbers[1]);
	free(numbers[2]);
	free(numbers);
	return (0);
}

t_map		*get_map_from_file(t_player *player, int fd)
{
	t_map *map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (get_info_from_file(map_info, player, fd) == ERROR_NON_VALID_FILE)
		return (NULL);
	printf("X: %d Y: %d\n", map_info->size_x, map_info->size_y);
	init_map(map_info);
	if (read_map(map_info, fd) == ERROR_NON_VALID_FILE)
		return (NULL);
	if (map_info->map[player->y / 64][player->x / 64] == 1)
		return (NULL);
	print_map(map_info);
	return (map_info);
}
