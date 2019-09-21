/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:17:48 by djast             #+#    #+#             */
/*   Updated: 2019/09/19 16:15:52 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int get_info_from_file(t_sdl *sdl, int fd)
{
	char *line;
	char **numbers;

	get_next_line(fd, &line);
	if (line == NULL || countwords(line, ' ') != 2)
		return (ERROR_NON_VALID_FILE);
	numbers = ft_strsplit(line, ' ');
	sdl->mesh->size_x = ft_atoi(numbers[0]);
	sdl->mesh->size_y = ft_atoi(numbers[1]);
	free(numbers[0]);
	free(numbers[1]);
	free(numbers);
	get_next_line(fd, &line);
	if (line == NULL || countwords(line, ' ') != 3)
		return (ERROR_NON_VALID_FILE);
	numbers = ft_strsplit(line, ' ');
	sdl->player->x = ft_atoi(numbers[0]);
	sdl->player->y = ft_atoi(numbers[1]);
	free(numbers[0]);
	free(numbers[1]);
	free(numbers[2]);
	free(numbers);
	return (0);
}

static int read_map(t_sdl *sdl, int fd)
{
	int i;
	int j;
	char *line;
	char **numbers;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (countwords(line, ' ') != sdl->mesh->size_x)
			return (ERROR_NON_VALID_FILE);
		numbers = ft_strsplit(line, ' ');
		j = 0;
		while (j < sdl->mesh->size_x)
		{
			sdl->mesh->map[i][j] = ft_atoi(numbers[j]);
			free(numbers[j++]);
		}
		free(line);
		i++;
	}
	sdl->mesh->map[(sdl->player->y - 32) / 64][(sdl->player->x - 32) / 64] = 2;
	return (0);
}

void load_map(t_sdl *sdl)
{
	int fd;
	(void) sdl;
	char filename[120];

	ft_strcpy(filename, "resources/maps/");
	ft_strcat(filename, sdl->map_name->text);
	fd = open(filename, O_RDONLY);
	if (read(fd, NULL, 0) == -1)
		sdl->status_save = ERROR_NO_FILE;
 	else if (get_info_from_file(sdl, fd) == ERROR_NON_VALID_FILE)
 		sdl->status_save = ERROR_NON_VALID_FILE;
 	else if (read_map(sdl, fd) == ERROR_NON_VALID_FILE)
 		sdl->status_save = ERROR_NON_VALID_FILE;
 	else if (sdl->mesh->map[sdl->player->y / 64][sdl->player->x / 64] == 1)
 		sdl->status_save = ERROR_NON_VALID_FILE;
 	else
 		sdl->status_save = ERROR_OK;
}





// t_map *get_map_from_file(t_sdl *sdl, int fd)
// {
// 	t_mesh *map_info;

// 	if (get_info_from_file(sdl, fd) == ERROR_NON_VALID_FILE)
// 		return (NULL);
// 	printf("X: %d Y: %d\n", sdl->mesh->size_x, sdl->mesh->size_y);
// 	init_map(sdl->mesh->map_info);
// 	if (read_map(map_info, fd) == ERROR_NON_VALID_FILE)
// 		return (NULL);
// 	if (map_info->map[player->y / 64][player->x / 64] == 1)
// 		return (NULL);
// 	print_map(map_info);
// 	return (map_info);
// }