/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:05 by djast             #+#    #+#             */
/*   Updated: 2019/06/08 15:33:12 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_color_by_mode(t_mlx *mlx, t_thread *args, int step)
{
	if (mlx->color_mode == 1)
		mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
						(step << 21) + (step << 10) +
						step * 8;
	else if (mlx->color_mode == 2)
		mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
						((step << 14) * 3) + (step << 11) +
						step * 8;
	else if (mlx->color_mode == 3)
		mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
						((step << 18) * 2) + ((step << 10) * 4) +
						step * 10;
	else if (mlx->color_mode == 4)
		mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
						((step << 9) * 20) + ((step << 4) * 10) +
						step * 10;
	else if (mlx->color_mode == 6)
		mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
						((step << 20) * 2) + ((step << 1) * 3) +
						step * 30;
}

t_fractol		*init_fractol(t_complex *clx, t_mlx *mlx)
{
	t_fractol *fractol_params;

	fractol_params = (t_fractol *)malloc(sizeof(t_fractol));
	fractol_params->const_c = (t_complex *)malloc(sizeof(t_complex));
	fractol_params->const_c->c = clx->c;
	fractol_params->const_c->i = clx->i;
	fractol_params->step = 0;
	fractol_params->max_step = mlx->max_step;
	return (fractol_params);
}

static void		take_fractol(t_thread *args, t_fractol *fractol_params)
{
	if (args->type_of_fractol == FRACTOL_JULIA)
		julia_calculate(args->clx, args->mlx, args, fractol_params);
	else if (args->type_of_fractol == FRACTOL_MANDEL)
		mandelbrot_calculate(args->clx, args->mlx, args, fractol_params);
	else if (args->type_of_fractol == FRACTOL_BURN)
		burning_ship_calculate(args->clx, args->mlx, args, fractol_params);
	else if (args->type_of_fractol == FRACTOL_NEWTON)
		newton_calculate(args->clx, args->mlx, args, fractol_params);
	else if (args->type_of_fractol == FRACTOL_CUBIC)
		cubic_calculate(args->clx, args->mlx, args, fractol_params);
	else if (args->type_of_fractol == FRACTOL_QUADRATIC)
		quadratic_calculate(args->clx, args->mlx, args, fractol_params);
	else if (args->type_of_fractol == FRACTOL_FIFTH)
		fifth_calculate(args->clx, args->mlx, args, fractol_params);
}

void			*start_to_calc_fractol(void *arguments)
{
	t_fractol		*fractol_params;
	t_thread		*args;

	args = (t_thread *)arguments;
	fractol_params = init_fractol(args->clx, args->mlx);
	args->cur_x = args->min_x;
	while (args->cur_x < args->max_x)
	{
		args->cur_y = args->min_y;
		while (args->cur_y < args->max_y)
		{
			take_fractol(args, fractol_params);
			args->cur_y++;
		}
		args->cur_x++;
	}
	free(fractol_params->const_c);
	free(fractol_params);
	pthread_exit(NULL);
}
