/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 12:58:10 by djast             #+#    #+#             */
/*   Updated: 2019/05/08 17:20:32 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		rotate_in_out(t_mlx *mlx, int direction)
{
	int		i;
	int		j;
	double	phi;
	double	x;

	phi = direction == 1 ? 0.174533 : -0.174533;
	i = 0;
	while (i < mlx->size_map_y)
	{
		j = 0;
		while (j < mlx->size_map_x)
		{
			x = mlx->points[i][j].x - mlx->middle_x;
			mlx->points[i][j].x = mlx->middle_x + x * cos(phi) -
			(mlx->points[i][j].y - mlx->middle_y) * sin(phi);
			mlx->points[i][j].y = mlx->middle_y + x * sin(phi) +
			(mlx->points[i][j].y - mlx->middle_y) * cos(phi);
			j++;
		}
		i++;
	}
	restart(mlx);
}

void		rotate_up_down(t_mlx *mlx, int direction)
{
	int		i;
	int		j;
	double	phi;
	double	y;

	phi = direction == 1 ? 0.174533 : -0.174533;
	i = 0;
	while (i < mlx->size_map_y)
	{
		j = 0;
		while (j < mlx->size_map_x)
		{
			y = mlx->points[i][j].y - mlx->middle_y;
			mlx->points[i][j].y = mlx->middle_y + y * cos(phi) +
			mlx->points[i][j].z * sin(phi);
			mlx->points[i][j].z = -y * sin(phi) + mlx->points[i][j].z
			* cos(phi);
			j++;
		}
		i++;
	}
	restart(mlx);
}

void		rotate_left_right(t_mlx *mlx, int direction)
{
	int		i;
	int		j;
	double	phi;
	double	x;

	phi = direction == 1 ? 0.174533 : -0.174533;
	i = 0;
	while (i < mlx->size_map_y)
	{
		j = 0;
		while (j < mlx->size_map_x)
		{
			x = mlx->points[i][j].x - mlx->middle_x;
			mlx->points[i][j].x = mlx->middle_x + x * cos(phi) +
			mlx->points[i][j].z * sin(phi);
			mlx->points[i][j].z = -x * sin(phi) + mlx->points[i][j].z
			* cos(phi);
			j++;
		}
		i++;
	}
	restart(mlx);
}
