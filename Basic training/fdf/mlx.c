/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:08:52 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 17:26:33 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		fill_mlx(t_mlx *mlx, int flag)
{
	if (mlx->size_map_x < SIZE_MAP_X)
	{
		mlx->zoom = SIZE_MAP_X / mlx->size_map_x > SIZE_MAP_Y / mlx->size_map_y
				? SIZE_MAP_X / mlx->size_map_x : SIZE_MAP_Y / mlx->size_map_y;
		mlx->zoom /= 2;
	}
	mlx->middle_x = mlx->size_map_x / 2.0;
	mlx->middle_y = mlx->size_map_y / 2.0;
	mlx->place_x = (int)(SIZE_MAP_X / 2 - mlx->middle_x * mlx->zoom);
	mlx->place_y = (int)(SIZE_MAP_Y / 2 - mlx->middle_y * mlx->zoom);
	if (flag == 0)
	{
		mlx->m_p = mlx_init();
		mlx->w_p = mlx_new_window(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y,
									"Fdf project djast");
		mlx->img = mlx_new_image(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y);
		mlx->img_data = (int *)mlx_get_data_addr(mlx->img, &mlx->bbp,
			&mlx->size_line, &mlx->endian);
	}
}

t_mlx		*init_struct_mlx(const char *filename, int fd)
{
	t_mlx *s_mlx;

	s_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	s_mlx->size_map_y = -1;
	s_mlx->size_map_x = -1;
	s_mlx->points = NULL;
	s_mlx->m_p = NULL;
	s_mlx->w_p = NULL;
	s_mlx->filename = filename;
	s_mlx->fd = fd;
	s_mlx->delta_x = 0;
	s_mlx->delta_y = 0;
	s_mlx->sign_x = 0;
	s_mlx->sign_y = 0;
	s_mlx->delta_max = 0;
	s_mlx->zoom = 3;
	s_mlx->place_x = 25;
	s_mlx->place_y = 25;
	s_mlx->middle_x = 250;
	s_mlx->middle_y = 250;
	s_mlx->is_color = 0;
	s_mlx->is_legend = 1;
	return (s_mlx);
}

void		free_mem(t_mlx *mlx)
{
	int y;

	y = 0;
	while (y < mlx->size_map_y)
	{
		free(mlx->points[y]);
		y++;
	}
	free(mlx->points);
	free(mlx);
	mlx = NULL;
}

void		restart(t_mlx *mlx)
{
	mlx_destroy_image(mlx->m_p, mlx->img);
	mlx->img = mlx_new_image(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img,
		&mlx->bbp, &mlx->size_line, &mlx->endian);
	ft_bzero(mlx->img_data, SIZE_MAP_X * SIZE_MAP_Y);
	make_image(mlx);
	mlx_put_image_to_window(mlx->m_p, mlx->w_p, mlx->img, 0, 0);
	if (mlx->is_legend == 1)
		create_legend(mlx);
}
