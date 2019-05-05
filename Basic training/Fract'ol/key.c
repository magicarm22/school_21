/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:00:08 by djast             #+#    #+#             */
/*   Updated: 2019/03/28 18:23:43 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(t_mlx *mlx, int direction)
{
	double		step;

	step = direction == 0 || direction == 13 ? -0.1/mlx->zoom: 0.10/mlx->zoom;
	if (direction == 0 || direction == 2)
		mlx->place_x = mlx->place_x + step;
	else if (direction == 13 || direction == 1)
		mlx->place_y = mlx->place_y + step;
	restart(mlx);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == 53)
		close_win(mlx);
	else if (key == 0 || key == 2 || key == 1 || key == 13)
		move(mlx, key);
	else if (key == 3)
		mlx->fixed_image = !mlx->fixed_image;
	else if (key == 69)
	{
		mlx->max_step += 10;
		restart(mlx);
	}
	return (0);
}

int		close_win(t_mlx *mlx)
{
	(void) mlx;
//	free_mem(mlx);
	exit(0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;

	(void)button;
	(void)mlx;
	if (button == 4)
	{
		if (mlx->zoom != 1)
		{
			mlx->zoom /= 2;
			restart(mlx);
		}
	}
	else if (button == 5)
	{
		mlx->zoom *= 2;
		restart(mlx);
	}
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	t_complex *clx;

	restart(mlx);
	if (ft_strcmp(mlx->type, "julia") == 0 && mlx->fixed_image == 0)
	{
		clx = (t_complex *)malloc(sizeof(t_complex));
		clx->c = ((double)x - (SIZE_MAP_X / 2)) /SIZE_MAP_X;
		clx->i = ((double)y - (SIZE_MAP_Y / 2)) /SIZE_MAP_Y;
		mlx->clx = clx;
		julia_threads(clx, mlx);
	}
	else if (ft_strcmp(mlx->type, "julia") == 0 && mlx->fixed_image == 1)
		julia_threads(mlx->clx, mlx);
	return (0);
}
