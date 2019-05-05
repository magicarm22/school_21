/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:42:55 by djast             #+#    #+#             */
/*   Updated: 2019/03/29 12:55:45 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		restart(t_mlx *mlx)
{
	mlx_clear_window(mlx->m_p, mlx->w_p);
	ft_bzero(mlx->img_data, SIZE_MAP_X * SIZE_MAP_Y);
	if (ft_strcmp(mlx->type, "julia") == 0)
	{
		julia_threads(mlx->clx, mlx);
	}
	if (ft_strcmp(mlx->type, "mandelbrot") == 0)
	{
		mandelbrot_threads(mlx->clx, mlx);
	}
		mlx_put_image_to_window(mlx->m_p, mlx->w_p, mlx->img, 0, 0);
}