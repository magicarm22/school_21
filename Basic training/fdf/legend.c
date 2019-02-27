/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 12:59:45 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:02:47 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	create_legend(t_mlx *m)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y++ < SIZE_MAP_Y)
	{
		x = 0;
		while (x++ < SIZE_MAP_X / 8)
			mlx_pixel_put(m->m_p, m->w_p, x - 1, y - 1, 0x3e4044);
	}
	x = 10;
	y = 30;
	mlx_string_put(m->m_p, m->w_p, x + 110, y, WH, "Legend");
	mlx_string_put(m->m_p, m->w_p, x, y + 20, WH, "Control:");
	mlx_string_put(m->m_p, m->w_p, x, y + 40, WH, "X-axis move: A/D");
	mlx_string_put(m->m_p, m->w_p, x, y + 60, WH, "Y-axis move: W/S");
	mlx_string_put(m->m_p, m->w_p, x, y + 80, WH, "X-axis rotate: Up/Down");
	mlx_string_put(m->m_p, m->w_p, x, y + 100, WH, "Y-axis rotate: Left/Right");
	mlx_string_put(m->m_p, m->w_p, x, y + 120, WH, "Z-axis rotate: 8/2 NumPad");
	mlx_string_put(m->m_p, m->w_p, x, y + 140, WH, "Zoom: Up/Down mouse wheel");
	mlx_string_put(m->m_p, m->w_p, x, y + 160, WH, "Reset: R");
	mlx_string_put(m->m_p, m->w_p, x, y + 180, WH, "Hide legend: H");
	mlx_string_put(m->m_p, m->w_p, x, y + 200, WH, "ISO: I");
}

void	change_state_legend(t_mlx *m)
{
	m->is_legend = m->is_legend == 1 ? 0 : 1;
	restart(m);
}
