/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:53:10 by djast             #+#    #+#             */
/*   Updated: 2019/03/29 11:54:03 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*init_struct_mlx()
{
	t_mlx *s_mlx;

	s_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	s_mlx->size_map_y = -1;
	s_mlx->size_map_x = -1;
	s_mlx->m_p = NULL;
	s_mlx->w_p = NULL;
	s_mlx->points = NULL;
	s_mlx->zoom = 1;
	s_mlx->place_x = 0;
	s_mlx->place_y = 0;
	s_mlx->max_step = 40;
	s_mlx->fixed_image = 0;
	return (s_mlx);
}
