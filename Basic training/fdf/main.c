/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:40:24 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 17:26:30 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	start_fdf(int fd, const char *filename)
{
	t_mlx *info_map;

	info_map = init_struct_mlx(filename, fd);
	if (check_map(fd, info_map) == -1)
	{
		perror("Non valid file!");
		return ;
	}
	close(fd);
	if (!(fd = open(filename, O_RDONLY)))
	{
		perror("Can't open file");
		return ;
	}
	create_map(fd, &info_map);
	fill_mlx(info_map, 0);
	make_image(info_map);
	mlx_hook(info_map->w_p, 17, (1L << 17), close_win, info_map);
	mlx_hook(info_map->w_p, 2, (1L << 3), key_release, info_map);
	mlx_mouse_hook(info_map->w_p, mouse_press, info_map);
	mlx_put_image_to_window(info_map->m_p, info_map->w_p, info_map->img, 0, 0);
	create_legend(info_map);
	mlx_loop(info_map->m_p);
}

int		main(int argc, char const *argv[])
{
	int fd;

	if (argc != 2)
	{
		perror("Error argc");
		return (-1);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		perror("Can't open file");
		return (-1);
	}
	start_fdf(fd, argv[1]);
	return (0);
}
