/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:53:31 by djast             #+#    #+#             */
/*   Updated: 2019/09/28 11:42:27 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	write_info_to_file(t_sdl *sdl, int fd)
{
	char *tmp;

	tmp = ft_itoa(sdl->mesh->size_x);
	write(fd, tmp, ft_num_len(sdl->mesh->size_x));
	free(tmp);
	write(fd, " ", 1);
	tmp = ft_itoa(sdl->mesh->size_y);
	write(fd, tmp, ft_num_len(sdl->mesh->size_y));
	free(tmp);
	write(fd, "\n", 1);
	tmp = ft_itoa(sdl->player->x);
	write(fd, tmp, ft_num_len(sdl->player->x));
	free(tmp);
	write(fd, " ", 1);
	tmp = ft_itoa(sdl->player->y);
	write(fd, tmp, ft_num_len(sdl->player->y));
	free(tmp);
	write(fd, " 0\n", 3);
}

static int	create_and_write_header(t_sdl *sdl)
{
	int		fd;
	char	filename[120];

	ft_strcpy(filename, "resources/maps/");
	ft_strcat(filename, sdl->map_name->text);
	fd = open(filename, O_WRONLY);
	if (fd == -1)
	{
		open(filename, O_CREAT);
		fd = open(filename, O_WRONLY);
	}
	write_info_to_file(sdl, fd);
	return (fd);
}

static void	write_map(t_sdl *sdl, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < sdl->mesh->size_y)
	{
		j = 0;
		while (j < sdl->mesh->size_x)
		{
			if (sdl->mesh->map[i][j] == 1)
				write(fd, "1", 1);
			else if (sdl->mesh->map[i][j] == 2)
				write(fd, "0", 1);
			else if (sdl->mesh->map[i][j] == 0)
				write(fd, "0", 1);
			if (j + 1 != sdl->mesh->size_x)
				write(fd, " ", 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

void		save_map(t_sdl *sdl)
{
	int fd;

	if (sdl->player->x == -1 || sdl->player->y == -1)
	{
		sdl->status_save = ERROR_NO_PLAYER;
		return ;
	}
	else if (ft_strlen(sdl->map_name->text) == 0)
	{
		sdl->status_save = ERROR_NO_FILENAME;
		return ;
	}
	fd = create_and_write_header(sdl);
	write_map(sdl, fd);
	close(fd);
	sdl->status_save = ERROR_OK;
}
