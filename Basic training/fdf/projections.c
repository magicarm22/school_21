/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:03:45 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:43:19 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		iso(t_mlx *mlx)
{
	int		i;
	int		j;
	double	x;

	i = 0;
	while (i < mlx->size_map_y)
	{
		j = 0;
		while (j < mlx->size_map_x)
		{
			x = mlx->points[i][j].x;
			mlx->points[i][j].x = (x - mlx->points[i][j].y) * cos(0.523599);
			mlx->points[i][j].y = -mlx->points[i][j].z +
			(mlx->points[i][j].y + x) * sin(0.523599);
			j++;
		}
		i++;
	}
	restart(mlx);
}
