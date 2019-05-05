/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:05 by djast             #+#    #+#             */
/*   Updated: 2019/03/29 16:49:07 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_julia *init_julia(t_complex *clx, t_mlx *mlx)
{
	t_julia *julia;

	julia = (t_julia *)malloc(sizeof(t_julia));
	julia->const_C = (t_complex *)malloc(sizeof(t_complex));
	julia->const_C->c = clx->c;
	julia->const_C->i = clx->i;
	julia->step = 0;
	julia->max_step = mlx->max_step;
	return (julia);
}

void julia_calculate(t_complex *clx, t_mlx *mlx, int x, int y, t_julia *julia)
{
	clx->c = 1.5 * (x - SIZE_MAP_X / 2)/(0.5 * mlx->zoom *  SIZE_MAP_X) + mlx->place_x;
    clx->i = (y - SIZE_MAP_Y / 2) / (0.5 * mlx->zoom * SIZE_MAP_Y) + mlx->place_y;
    julia->step = julia->max_step;
    while (clx->c*clx->c + clx->i*clx->i < 4 && julia->step > 0)
    {
    	julia->tmp = clx->c * clx->c - clx->i * clx->i + julia->const_C->c;
    	clx->i = 2.0 * clx->c * clx->i + julia->const_C->i;
    	clx->c = julia->tmp;
   		julia->step -= 1;
    }
    printf("%d\n", julia->step);
    mlx->img_data[y * SIZE_MAP_X + x] = (julia->step << 21) +
    					(julia->step << 10) + julia->step * 8;
}

void *julia_fractol(void *arguments)
{
	t_julia *julia;
	t_thread *args;

	args = (t_thread *)arguments;

	julia = init_julia(args->clx, args->mlx);
	args->cur_x = args->min_x;
	while (args->cur_x < args->max_x)
	{
		args->cur_y = args->min_y;
		while (args->cur_y < args->max_y)
		{
			julia_calculate(args->clx, args->mlx, args->cur_x, args->cur_y, julia);
        	args->cur_y++;
		}
		args->cur_x++;
	}
	pthread_exit(NULL);
}

static void init_thread_args(t_thread ***args)
{
	int i;

	i = 0;
	*args = (t_thread **)malloc(sizeof(t_thread *) * NUM_THREADS);

	while (i < NUM_THREADS)
	{
		(*args)[i++] = (t_thread *)malloc(sizeof(t_thread));
	}
}

void julia_threads(t_complex *clx, t_mlx *mlx)
{
	pthread_t threads[NUM_THREADS];
	int i;
	t_thread **args;

	init_thread_args(&args);
	i = 0;
	while (i < NUM_THREADS)
	{
		t_complex *new_clx = (t_complex *)malloc(sizeof(t_complex));
		new_clx->c = clx->c;
		new_clx->i = clx->i;
		args[i]->clx = new_clx;
		args[i]->mlx = mlx;
		args[i]->min_x = SIZE_MAP_X / NUM_THREADS * i;
		args[i]->min_y = 0;
		args[i]->max_x = SIZE_MAP_X / NUM_THREADS * (i + 1);
		args[i]->max_y = SIZE_MAP_Y;
		args[i]->num_thread = i;
		pthread_create(&threads[i], NULL, julia_fractol, (void *)args[i]);
		i++;
	}
	while (i-- >= 0)
		pthread_join(threads[i], NULL);
}