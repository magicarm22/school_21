/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:17:39 by djast             #+#    #+#             */
/*   Updated: 2019/06/08 15:33:39 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		init_thread_args(t_thread ***args)
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

static int		filling_args_for_thread(t_complex *clx, t_mlx *mlx,
										t_thread *args)
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
	if (ft_strcmp(mlx->type, "julia") == 0)
		args->type_of_fractol = FRACTOL_JULIA;
	else if (ft_strcmp(mlx->type, "mandelbrot") == 0)
		args->type_of_fractol = FRACTOL_MANDEL;
	else if (ft_strcmp(mlx->type, "burning ship") == 0)
		args->type_of_fractol = FRACTOL_BURN;
	else if (ft_strcmp(mlx->type, "newton") == 0)
		args->type_of_fractol = FRACTOL_NEWTON;
	else if (ft_strcmp(mlx->type, "cubic") == 0)
		args->type_of_fractol = FRACTOL_CUBIC;
	else if (ft_strcmp(mlx->type, "quadratic") == 0)
		args->type_of_fractol = FRACTOL_QUADRATIC;
	else if (ft_strcmp(mlx->type, "fifth") == 0)
		args->type_of_fractol = FRACTOL_FIFTH;
	return (1);
}

int				init_threads_and_start(t_complex *clx, t_mlx *mlx)
{
	t_thread		**args;
	pthread_t		threads[NUM_THREADS];
	int				i;

	if (init_thread_args(&args) == 0)
		return (0);
	i = 0;
	while (i < NUM_THREADS)
	{
		args[i]->num_thread = i;
		if (filling_args_for_thread(clx, mlx, args[i]) == 1)
			pthread_create(&threads[i], NULL, start_to_calc_fractol,
							(void *)args[i]);
		i++;
	}
	while (i-- >= 0)
		pthread_join(threads[i], NULL);
	free_args(args);
	return (1);
}
