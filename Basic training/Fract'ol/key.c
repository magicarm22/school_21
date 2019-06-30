/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:00:08 by djast             #+#    #+#             */
/*   Updated: 2019/06/13 16:47:43 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_mlx *mlx, int direction)
{
	double		step;

	step = direction == 123 || direction == 126 ? -0.1 / mlx->zoom :
												0.1 / mlx->zoom;
	if (direction == 123 || direction == 124)
		mlx->place_x = mlx->place_x + step;
	else if (direction == 126 || direction == 125)
		mlx->place_y = mlx->place_y + step;
	restart(mlx);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == 53)
		close_win(mlx);
	else if (key == 126 || key == 123 || key == 124 || key == 125)
		move(mlx, key);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
	{
		mlx->color_mode = key - 17;
		restart(mlx);
	}
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
	(void)mlx;
	free_mlx(mlx);
	exit(0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	long long tmp;

	if (button == 4)
	{
		if (mlx->zoom > 1)
		{
			mlx->zoom /= 2;
			restart(mlx);
		}
	}
	else if (button == 5)
	{
		tmp = (mlx->zoom * 2);
		if (tmp < 4611686018427387904)
		{
			mlx->place_x += (double)(x - (SIZE_MAP_X / 2)) / (mlx->zoom) / 400;
			mlx->place_y += (double)(y - (SIZE_MAP_Y / 2)) / (mlx->zoom) / 400;
			mlx->zoom = tmp;
		}
		restart(mlx);
	}
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	t_complex *clx;

	if (ft_strcmp(mlx->type, "julia") == 0 && mlx->fixed_image == 0)
	{
		restart(mlx);
		clx = (t_complex *)malloc(sizeof(t_complex));
		clx->c = ((double)x - (SIZE_MAP_X / 2)) / SIZE_MAP_X;
		clx->i = ((double)y - (SIZE_MAP_Y / 2)) / SIZE_MAP_Y;
		if (mlx->clx != NULL)
			free(mlx->clx);
		mlx->clx = clx;
		init_threads_and_start(clx, mlx);
	}
	return (0);
}
