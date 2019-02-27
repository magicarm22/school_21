/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:00:40 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:54:22 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		move(t_mlx *mlx, int direction)
{
	int		step;

	step = direction == 0 || direction == 13 ? -1 * mlx->zoom : 1 * mlx->zoom;
	if (direction == 0 || direction == 2)
		mlx->place_x = mlx->place_x + step;
	else if (direction == 13 || direction == 1)
		mlx->place_y = mlx->place_y + step;
	restart(mlx);
}

void		zoom_in_out(t_mlx *mlx, int direction)
{
	int step;

	step = direction == 1 ? -1 : 1;
	mlx->zoom += step;
	restart(mlx);
}
