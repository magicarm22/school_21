/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:36:30 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:53:50 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static	void	draw_x(t_mlx *mlx, int x, int y, t_point coord2)
{
	int d;

	d = -mlx->delta_x;
	while (mlx->delta_max--)
	{
		if (x < SIZE_MAP_X && y < SIZE_MAP_Y && x > 0 && y > 0)
			mlx->img_data[x + y * SIZE_MAP_X] = coord2.color;
		x += mlx->sign_x;
		d += 2 * mlx->delta_y;
		if (d > 0)
		{
			d -= 2 * mlx->delta_x;
			y += mlx->sign_y;
		}
	}
}

static	void	draw_y(t_mlx *mlx, int x, int y, t_point coord2)
{
	int d;

	d = -mlx->delta_y;
	while (mlx->delta_max--)
	{
		if (x < SIZE_MAP_X && y < SIZE_MAP_Y && x > 0 && y > 0)
			mlx->img_data[x + y * SIZE_MAP_X] = coord2.color;
		y += mlx->sign_y;
		d += 2 * mlx->delta_x;
		if (d > 0)
		{
			d -= 2 * mlx->delta_y;
			x += mlx->sign_x;
		}
	}
}

void			draw_line(t_mlx *mlx, t_point coord1, t_point coord2)
{
	int x;
	int y;

	x = coord1.x * mlx->zoom + mlx->place_x;
	y = coord1.y * mlx->zoom + mlx->place_y;
	mlx->sign_x = (coord2.x * mlx->zoom + mlx->place_x - x >= 0 ? 1 : -1);
	mlx->sign_y = (coord2.y * mlx->zoom + mlx->place_y - y >= 0 ? 1 : -1);
	mlx->delta_x = fabs(coord2.x * mlx->zoom + mlx->place_x - x);
	mlx->delta_y = fabs(coord2.y * mlx->zoom + mlx->place_y - y);
	mlx->delta_max = mlx->delta_x > mlx->delta_y ? mlx->delta_x + 1 :
													mlx->delta_y + 1;
	if (mlx->delta_max == 0)
		if (x < SIZE_MAP_X && y < SIZE_MAP_Y && x > 0 && y > 0)
			mlx->img_data[x + y * SIZE_MAP_X] = coord1.color;
	if (mlx->delta_y <= mlx->delta_x)
		draw_x(mlx, x, y, coord2);
	else
		draw_y(mlx, x, y, coord2);
}
