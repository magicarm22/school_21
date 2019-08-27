/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:17 by djast             #+#    #+#             */
/*   Updated: 2019/08/27 19:28:10 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void init_map(t_map *map_info)
{
	int i;

	i = 0;
	map_info->map = (int **)malloc(sizeof(int *) * map_info->size_y);
	while (i < map_info->size_y)
		map_info->map[i++] = (int *)malloc(sizeof(int) * map_info->size_x);
}

static void print_map(t_map *map_info)
{
	int i;
	int j;

	i = 0;
	while (i < map_info->size_y)
	{
		j = 0;
		while (j < map_info->size_x)
		{
			printf("%d", map_info->map[i][j]);
			if (j != map_info->size_x - 1)
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

static int read_map(t_map *map_info, int fd)
{
	int i;
	int j;
	char *line;
	char **numbers;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (countwords(line, ' ') != map_info->size_x)
			return (ERROR_NON_VALID_FILE);
		numbers = ft_strsplit(line, ' ');
		j = 0;
		while (j < map_info->size_x)
		{
			map_info->map[i][j] = ft_atoi(numbers[j]);
			free(numbers[j++]);
		}
		free(line);
		i++;
	}
	return (0);
}

static int get_info_from_file(t_map *map_info, t_player *player, int fd)
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
	if (line == NULL || countwords(line, ' ') != 2)
		return (ERROR_NON_VALID_FILE);
	numbers = ft_strsplit(line, ' ');
	player->coord_x = ft_atoi(numbers[0]);
	player->coord_y = ft_atoi(numbers[1]);
	free(numbers[0]);
	free(numbers[1]);
	free(numbers);
	return (0);
}

t_map *get_map_from_file(t_player *player, int fd)
{
	t_map *map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (get_info_from_file(map_info, player, fd) == ERROR_NON_VALID_FILE)
		return (NULL);
	printf("X: %d Y: %d\n", map_info->size_x, map_info->size_y);
	init_map(map_info);
	if (read_map(map_info, fd) == ERROR_NON_VALID_FILE)
		return (NULL);
	if (map_info->map[player->coord_y][player->coord_x] == 1)
		return (NULL);
	print_map(map_info);
	//return (map);
	return (map_info);
}