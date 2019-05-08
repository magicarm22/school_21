/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:42:55 by djast             #+#    #+#             */
/*   Updated: 2019/05/08 18:40:37 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		restart(t_mlx *mlx)
{
	char *steps;

	mlx_clear_window(mlx->m_p, mlx->w_p);
	ft_bzero(mlx->img_data, SIZE_MAP_X * SIZE_MAP_Y);
	init_threads_and_start(mlx->clx, mlx);
	mlx_put_image_to_window(mlx->m_p, mlx->w_p, mlx->img, 0, 0);
	mlx_string_put(mlx->m_p, mlx->w_p, 40, 40, 0xFFFFFF, "Fractol Steps: ");
	steps = ft_itoa(mlx->max_step);
	mlx_string_put(mlx->m_p, mlx->w_p, 190, 40, 0xFFFFFF, steps);
	free(steps);
}

void free_mlx(t_mlx *mlx)
{
	free(mlx->img_data);
	free(mlx->clx);
	free(mlx);
}

void free_args(t_thread **args)
{
	int i;

	i = 0;
	while (i < NUM_THREADS)
	{
		free(args[i]->clx);
		free(args[i++]);
	}
	free(args);
}
