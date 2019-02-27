/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:04:52 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 17:05:22 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			make_image(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->size_map_y)
	{
		j = 0;
		while (j < mlx->size_map_x)
		{
			if (j < mlx->size_map_x - 1)
				draw_line(mlx, mlx->points[i][j], mlx->points[i][j + 1]);
			if (i < mlx->size_map_y - 1)
				draw_line(mlx, mlx->points[i][j], mlx->points[i + 1][j]);
			j++;
		}
		i++;
	}
}

void			push_coords(t_mlx **mlx, int x, int y, char **split)
{
	(*mlx)->points[y][x].x = x;
	(*mlx)->points[y][x].y = y;
	(*mlx)->points[y][x].z = ft_atoi(*split) * 0.5;
	(*mlx)->points[y][x].color = *(*split + ft_si(ft_atoi(*split))) == ',' ?
	parse_color(*split + ft_si(ft_atoi(*split)) + 3) : WH;
}

void			create_map(int fd, t_mlx **mlx)
{
	char	*line;
	char	**split;
	int		x;
	int		y;

	y = 0;
	(*mlx)->points = (t_point **)malloc(sizeof(t_point *) * (*mlx)->size_map_y);
	while (get_next_line(fd, &line))
	{
		(*mlx)->points[y] = (t_point*)malloc(sizeof(t_point) *
			(*mlx)->size_map_x);
		split = ft_strsplit(line, ' ');
		x = 0;
		while (*split++)
		{
			push_coords(mlx, x, y, split - 1);
			x++;
		}
		add_zeroes(mlx, x, y);
		y++;
	}
}
