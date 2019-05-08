/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:05 by djast             #+#    #+#             */
/*   Updated: 2019/05/08 17:06:22 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol *init_fractol(t_complex *clx, t_mlx *mlx)
{
	t_fractol *fractol_params;

	fractol_params = (t_fractol *)malloc(sizeof(t_fractol));
	fractol_params->const_C = (t_complex *)malloc(sizeof(t_complex));
	fractol_params->const_C->c = clx->c;
	fractol_params->const_C->i = clx->i;
	fractol_params->step = 0;
	fractol_params->max_step = mlx->max_step;
	return (fractol_params);
}

void julia_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
										t_fractol *fractol_params)
{
	clx->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) / (0.5 * mlx->zoom *
												SIZE_MAP_X) + mlx->place_x;
    clx->i = (args->cur_y - SIZE_MAP_Y / 2) / (0.5 * mlx->zoom *
    										SIZE_MAP_Y) + mlx->place_y;
    fractol_params->step = fractol_params->max_step;
    while (clx->c*clx->c + clx->i*clx->i < 4 && fractol_params->step > 0)
    {
    	fractol_params->tmp = clx->c * clx->c - clx->i * clx->i +
    												fractol_params->const_C->c;
    	clx->i = 2.0 * clx->c * clx->i + fractol_params->const_C->i;
    	clx->c = fractol_params->tmp;
   		fractol_params->step -= 1;
    }
    mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
    					(fractol_params->step << 21) +
    					(fractol_params->step << 10) +
    					fractol_params->step * 8;
}

void mandelbrot_calculate(t_complex *clx, t_mlx *mlx, t_thread *args, t_fractol *fractol_params)
{
	int iteration;

	iteration = fractol_params->max_step;
	fractol_params->const_C->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) /
					(0.5 * mlx->zoom * SIZE_MAP_X) + mlx->place_x - 0.58;
	fractol_params->const_C->i = (args->cur_y - SIZE_MAP_Y / 2) /
							(0.5 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
	clx->c = 0;
	clx->i = 0;
	while (clx->c*clx->c + clx->i*clx->i < 4 && --iteration > 0)
	{
		fractol_params->tmp = clx->c;
		clx->c = clx->c * clx->c - clx->i * clx->i + fractol_params->const_C->c;
		clx->i = 2 * fractol_params->tmp * clx->i + fractol_params->const_C->i;
	}
    mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] = (iteration << 21) +
    					(iteration<< 10) + iteration * 8;
}

void burning_ship_calculate(t_complex *clx, t_mlx *mlx, t_thread *args, t_fractol *fractol_params)
{
	int iteration;

	iteration = fractol_params->max_step;
	fractol_params->const_C->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) /
					(0.5 * mlx->zoom * SIZE_MAP_X) + mlx->place_x - 0.58;
	fractol_params->const_C->i = (args->cur_y - SIZE_MAP_Y / 2) /
							(0.5 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
	clx->c = 0;
	clx->i = 0;
	while (clx->c*clx->c + clx->i*clx->i < 4 && --iteration > 0)
	{
		fractol_params->tmp = clx->c;
		clx->c = clx->c * clx->c - clx->i * clx->i + fractol_params->const_C->c;
		clx->i = 2 * fabsl(fractol_params->tmp * clx->i) + fractol_params->const_C->i;
	}
    mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] = (iteration << 21) +
    					(iteration<< 10) + iteration * 8;
}

void newton_calculate(t_complex *clx, t_mlx *mlx, t_thread *args, t_fractol *fractol_params)
{
	long double tmp;

	clx->c = 1.5 * (args->cur_x - SIZE_MAP_X / 2) / (0.5 * mlx->zoom *
												SIZE_MAP_X) + mlx->place_x;
    clx->i = (args->cur_y - SIZE_MAP_Y / 2) / (0.5 * mlx->zoom *
    										SIZE_MAP_Y) + mlx->place_y;
    fractol_params->step = fractol_params->max_step - 30;
    while (clx->c*clx->c + clx->i*clx->i < 4 && fractol_params->step > 0)
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
    	// fractol_params->tmp = clx->c * clx->c - clx->i * clx->i +
    	// 											fractol_params->const_C->c;
    	// clx->i = 2.0 * clx->c * clx->i + fractol_params->const_C->i;
    	// clx->c = fractol_params->tmp;
   		fractol_params->step -= 1;
    }
    mlx->img_data[args->cur_y * SIZE_MAP_X + args->cur_x] =
    					(fractol_params->step << 21) +
    					(fractol_params->step << 10) +
    					fractol_params->step * 8;
}

void *start_to_calc_fractol(void *arguments)
{
	t_fractol *fractol_params;
	t_thread *args;

	args = (t_thread *)arguments;

	fractol_params = init_fractol(args->clx, args->mlx);
	args->cur_x = args->min_x;
	while (args->cur_x < args->max_x)
	{
		args->cur_y = args->min_y;
		while (args->cur_y < args->max_y)
		{
			if (args->type_of_fractol == FRACTOL_JULIA)
				julia_calculate(args->clx, args->mlx, args, fractol_params);
			else if (args->type_of_fractol == FRACTOL_MANDEL)
				mandelbrot_calculate(args->clx, args->mlx, args, fractol_params);
			else if (args->type_of_fractol == FRACTOL_BURN)
				burning_ship_calculate(args->clx, args->mlx, args, fractol_params);
			else if (args->type_of_fractol == FRACTOL_NEWTON)
				newton_calculate(args->clx, args->mlx, args, fractol_params);
        	args->cur_y++;
		}
		args->cur_x++;
	}
	pthread_exit(NULL);
}
