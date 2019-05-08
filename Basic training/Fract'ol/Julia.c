/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_params.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:05 by djast             #+#    #+#             */
/*   Updated: 2019/03/29 16:49:07 by djast            ###   ########.fr       */
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

void fractol_params_calculate(t_complex *clx, t_mlx *mlx, int x, int y, t_fractol *fractol_params)
{
	clx->c = 1.5 * (x - SIZE_MAP_X / 2) / (0.5 * mlx->zoom *  SIZE_MAP_X) + mlx->place_x;
    clx->i = (y - SIZE_MAP_Y / 2) / (0.5 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
    fractol_params->step = fractol_params->max_step;
    while (clx->c*clx->c + clx->i*clx->i < 4 && fractol_params->step > 0)
    {
    	fractol_params->tmp = clx->c * clx->c - clx->i * clx->i + fractol_params->const_C->c;
    	clx->i = 2.0 * clx->c * clx->i + fractol_params->const_C->i;
    	clx->c = fractol_params->tmp;
   		fractol_params->step -= 1;
    }
    mlx->img_data[y * SIZE_MAP_X + x] = (fractol_params->step << 21) +
    					(fractol_params->step << 10) + fractol_params->step * 8;
}

void mandelbrot_calculate(t_complex *clx, t_mlx *mlx, int x, int y, t_fractol *fractol_params)
{
	int iteration;

	iteration = fractol_params->max_step;
	fractol_params->const_C->c = 1.5 * (x - SIZE_MAP_X / 2)/(0.5 * mlx->zoom *  SIZE_MAP_X) + mlx->place_x - 0.58;
	fractol_params->const_C->i = (y - SIZE_MAP_Y / 2) / (0.5 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
	clx->c = 0;
	clx->i = 0;
	while (clx->c*clx->c + clx->i*clx->i < 4 && --iteration > 0)
	{
		fractol_params->tmp = clx->c;
		clx->c = clx->c * clx->c - clx->i * clx->i + fractol_params->const_C->c;
		clx->i = 2.0 * fractol_params->tmp * clx->i + fractol_params->const_C->i;
	}
    mlx->img_data[y * SIZE_MAP_X + x] = (iteration << 21) +
    					(iteration<< 10) + iteration * 8;
}

void *init_fractol_and_start_to_calc(void *arguments)
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
			if (args->type_of_fractol == FRACTOL_fractol_params)
				fractol_params_calculate(args->clx, args->mlx, args->cur_x, args->cur_y, fractol_params);
			else if (args->type_of_fractol == FRACTOL_MANDEL)
				mandelbrot_calculate(args->clx, args->mlx, args->cur_x, args->cur_y, fractol_params);
        	args->cur_y++;
		}
		args->cur_x++;
	}
	pthread_exit(NULL);
}

static int init_thread_args(t_thread ***args)
{
	int i;

	i = 0;
	*args = (t_thread **)malloc(sizeof(t_thread *) * NUM_THREADS);
	if (*args == NULL)
		return (0);
	while (i < NUM_THREADS)
	{
		(*args)[i] = (t_thread *)malloc(sizeof(t_thread));
		if ((*args)[i++] == NULL)
			return (0);
	}
	return (1);
}

static int filling_args_for_thread(t_complex *clx, t_mlx *mlx, t_thread *args)
{
	t_complex *new_clx;

	new_clx = (t_complex *)malloc(sizeof(t_complex));
	if (new_clx == NULL)
		return (0);
	new_clx->c = clx->c;
	new_clx->i = clx->i;
	args->clx = new_clx;
	args->mlx = mlx;
	args->min_x = SIZE_MAP_X / NUM_THREADS * args->num_thread;
	args->min_y = 0;
	args->max_x = SIZE_MAP_X / NUM_THREADS * (args->num_thread + 1);
	args->max_y = SIZE_MAP_Y;
	if (ft_strcmp(mlx->type, "fractol_params") == 0)
		args->type_of_fractol = FRACTOL_fractol_params;
	else if (ft_strcmp(mlx->type, "mandelbrot") == 0)
		args->type_of_fractol = FRACTOL_MANDEL;
	return (1);
}

int init_threads_and_start(t_complex *clx, t_mlx *mlx)
{
	t_thread **args;
	pthread_t threads[NUM_THREADS];
	int i;
	
	if (init_thread_args(&args) == 0)
		return (0);
	i = 0;
	while (i < NUM_THREADS)
	{
		args[i]->num_thread = i;
		if (filling_args_for_thread(clx, mlx, args[i]) == 1)
			pthread_create(&threads[i], NULL, init_fractol_and_start_to_calc, (void *)args[i]);
		i++;
	}
	while (i-- >= 0)
		pthread_join(threads[i], NULL);
	return (1);
}
