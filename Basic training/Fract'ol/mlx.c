/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:53:10 by djast             #+#    #+#             */
/*   Updated: 2019/05/27 18:38:17 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*init_struct_mlx(void)
{
	t_mlx *s_mlx;

	s_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	s_mlx->size_map_y = -1;
	s_mlx->size_map_x = -1;
	s_mlx->m_p = NULL;
	s_mlx->w_p = NULL;
	s_mlx->zoom = 1;
	s_mlx->place_x = 0;
	s_mlx->place_y = 0;
	s_mlx->max_step = 40;
	s_mlx->fixed_image = 0;
	s_mlx->color_mode = 1;
	return (s_mlx);
}

void		start_mlx(const char *fractol_name)
{
	t_mlx *mlx;

	mlx = init_struct_mlx();
	mlx->m_p = mlx_init();
	mlx->w_p = mlx_new_window(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y,
									"Fractol project djast");
	mlx->img = mlx_new_image(mlx->m_p, SIZE_MAP_X, SIZE_MAP_Y);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img, &mlx->bbp,
		&mlx->size_line, &mlx->endian);
	mlx->type = (char *)fractol_name;
	mlx->clx = (t_complex *)malloc(sizeof(t_complex));
	mlx->clx->c = 0;
	mlx->clx->i = 0;
	if (ft_strcmp(fractol_name, "julia") != 0)
		init_threads_and_start(mlx->clx, mlx);
	mlx_put_image_to_window(mlx->m_p, mlx->w_p, mlx->img, 0, 0);
	mlx_hook(mlx->w_p, 17, (1L << 17), close_win, mlx);
	mlx_hook(mlx->w_p, 2, (1L << 3), key_release, mlx);
	mlx_hook(mlx->w_p, 6, (1L << 6), mouse_move, mlx);
	mlx_mouse_hook(mlx->w_p, mouse_press, mlx);
	mlx_string_put(mlx->m_p, mlx->w_p, 40, 40, 0x00000, "Fractol Steps: ");
	mlx_loop(mlx->m_p);
}
