/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:26:59 by djast             #+#    #+#             */
/*   Updated: 2019/06/08 15:59:22 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		cubic_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
							t_fractol *fractol_params)
{
	int iteration;

	iteration = fractol_params->max_step;
	fractol_params->const_c->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) /
					(0.5 * mlx->zoom * SIZE_MAP_X) + mlx->place_x;
	fractol_params->const_c->i = (args->cur_y - SIZE_MAP_Y / 2) /
							(0.38 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
	clx->c = 0;
	clx->i = 0;
	while (clx->c * clx->c + clx->i * clx->i < 4 && --iteration > 0)
	{
		fractol_params->tmp = clx->c;
		clx->c = pow(clx->c, 3) - 3 * clx->c * clx->i * clx->i + fractol_params->const_c->c;
		clx->i = 3 * fractol_params->tmp * fractol_params->tmp * clx->i - pow(clx->i, 3) + + fractol_params->const_c->i;
	}
	put_color_by_mode(mlx, args, iteration);
}

void		quadratic_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
							t_fractol *fractol_params)
{
	int iteration;

	iteration = fractol_params->max_step;
	fractol_params->const_c->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) /
					(0.5 * mlx->zoom * SIZE_MAP_X) + mlx->place_x;
	fractol_params->const_c->i = (args->cur_y - SIZE_MAP_Y / 2) /
							(0.38 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
	clx->c = 0;
	clx->i = 0;
	while (clx->c * clx->c + clx->i * clx->i < 4 && --iteration > 0)
	{
		fractol_params->tmp = clx->c;
		clx->c = pow(clx->c, 4) - 6 * pow(clx->c, 2) * pow(clx->i, 2) +
					pow(clx->i, 4) + fractol_params->const_c->c;
		clx->i = 4 * pow(fractol_params->tmp, 3) * clx->i -
				4 * fractol_params->tmp * pow(clx->i, 3) +
				fractol_params->const_c->i;
	}
	put_color_by_mode(mlx, args, iteration);
}

void		 fifth_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
							t_fractol *fractol_params)
{
	int iteration;

	iteration = fractol_params->max_step;
	fractol_params->const_c->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) /
					(0.5 * mlx->zoom * SIZE_MAP_X) + mlx->place_x;
	fractol_params->const_c->i = (args->cur_y - SIZE_MAP_Y / 2) /
							(0.38 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
	clx->c = 0;
	clx->i = 0;
	while (clx->c * clx->c + clx->i * clx->i < 4 && --iteration > 0)
	{
		fractol_params->tmp = clx->c;
		clx->c = pow(clx->c, 5) - 10 * pow(clx->c, 3) * pow(clx->i, 2) +
				5 * clx->c * pow(clx->i, 4) + fractol_params->const_c->c;
		clx->i = 5 * pow(fractol_params->tmp, 4) * clx->i -
				10 * pow(fractol_params->tmp, 2) * pow(clx->i, 3) +
				pow(clx->i, 5) + fractol_params->const_c->i;
	}
	put_color_by_mode(mlx, args, iteration);
}

void		newton_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
						t_fractol *fractol_params)
{
	long double tmp;

	clx->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) / (0.5 * mlx->zoom *
												SIZE_MAP_X) + mlx->place_x;
	clx->i = (args->cur_y - SIZE_MAP_Y / 2) / (0.5 * mlx->zoom *
											SIZE_MAP_Y) + mlx->place_y;
	fractol_params->step = fractol_params->max_step - 30;
	while (clx->c * clx->c + clx->i * clx->i < 4 && fractol_params->step > 0)
	{
		tmp = clx->c;
		clx->c = (6 * pow(clx->c, 5) + 12 * pow(clx->c, 3) * pow(clx->i, 2) +
				3 * pow(clx->c, 2) + 6 * clx->c * pow(clx->i, 4) -
				3 * pow(clx->i, 2)) / (9 * pow(clx->c, 4) + 18 *
				pow(clx->c, 2) * pow(clx->i, 2) + 9 * pow(clx->i, 4));
		clx->i = (6 * pow(tmp, 4) * clx->i + 12 * pow(tmp, 2) *
				pow(clx->i, 3) - 6 * tmp * clx->i + 6 * pow(clx->i, 5)) /
				(9 * pow(tmp, 4) + 18 * pow(tmp, 2) * pow(clx->i, 2) +
				9 * pow(clx->i, 4));
		fractol_params->step -= 1;
	}
	put_color_by_mode(mlx, args, fractol_params->step);
}
