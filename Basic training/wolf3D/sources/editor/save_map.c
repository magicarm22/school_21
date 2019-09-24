/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:53:31 by djast             #+#    #+#             */
/*   Updated: 2019/09/24 14:54:44 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

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
	write(fd, ft_itoa(sdl->mesh->size_x), ft_num_len(sdl->mesh->size_x));
	write(fd, " ", 1);
	write(fd, ft_itoa(sdl->mesh->size_y), ft_num_len(sdl->mesh->size_y));
	write(fd, "\n", 1);
	write(fd, ft_itoa(sdl->player->x), ft_num_len(sdl->player->x));
	write(fd, " ", 1);
	write(fd, ft_itoa(sdl->player->y), ft_num_len(sdl->player->y));
	write(fd, " 0\n", 3);
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
