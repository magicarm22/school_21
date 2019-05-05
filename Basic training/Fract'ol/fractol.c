/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:18:33 by djast             #+#    #+#             */
/*   Updated: 2019/03/29 12:25:34 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char const *argv[])
{
	t_mlx *mlx;

	mlx = init_struct_mlx();
	if (argc < 2)
	{
		ft_putstr("Invalid argument\n");
		ft_putstr("Usage: ./fractol [julia/mandelbrot]");
		return (-1);
	}


	mlx->m_p = mlx_init();
	mlx->w_p = mlx_new_window(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y,
									"Fdf project djast");
	mlx->img = mlx_new_image(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img, &mlx->bbp,
		&mlx->size_line, &mlx->endian);
	mlx->type = (char *)argv[1];
	if (ft_strcmp(mlx->type, "julia") == 0)
	{
		mlx->clx = (t_complex *)malloc(sizeof(t_complex));
		mlx->clx->c = 0;
		mlx->clx->i = 0;
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		mlx->clx = (t_complex *)malloc(sizeof(t_complex));
		mlx->clx->c = 0;
		mlx->clx->i = 0;
		mandelbrot_threads(mlx->clx, mlx);
	}
	else
	{
		ft_putstr("Invalid argument\n");
		ft_putstr("Usage: ./fractol [julia/mandelbrot]");
		return (-1);
	}
	mlx_put_image_to_window(mlx->m_p, mlx->w_p, mlx->img, 0, 0);
	mlx_hook(mlx->w_p, 17, (1L << 17), close_win, mlx);
	mlx_hook(mlx->w_p, 2, (1L << 3), key_release, mlx);
	mlx_hook(mlx->w_p, 6, (1L << 6), mouse_move, mlx);
	mlx_mouse_hook(mlx->w_p, mouse_press, mlx);
	mlx_loop(mlx->m_p);
	return 0;
}