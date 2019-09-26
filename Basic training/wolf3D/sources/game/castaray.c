/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castaray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:07:17 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/25 14:30:44 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	choose_the_range(t_sdl *sdl, t_player *point)
{
	if ((point->dist_hor <= point->dist_vert && point->dist_hor != 0) ||
			point->dist_vert == 0)
	{
		point->hor_or_vert = 1;
		point->strip = (int)point->check_hor_x;
		draw_a_wall(sdl, point, point->ray, point->dist_hor *
			cos((point->point_of_view - point->angle) * RADIAN));
	}
	else if ((point->dist_hor >= point->dist_vert && point->dist_vert != 0) ||
			point->dist_hor == 0)
	{
		point->hor_or_vert = 2;
		point->strip = (int)point->check_ver_y;
		draw_a_wall(sdl, point, point->ray, point->dist_vert *
			cos((point->point_of_view - point->angle) * RADIAN));
	}
}

void	cast_a_ray(t_sdl *sdl, t_player *point, t_map *map_info)
{
	point->ray = 0;
	point->angle = point->point_of_view - (FIELD_OF_VIEW / 2);
	if (point->angle < 0)
		point->angle = point->angle + 360;
	while (point->ray <= RESOL_X)
	{
		point->dist_hor = find_a_wall_hor(map_info, point, point->angle);
		point->dist_vert = find_a_wall_vert(map_info, point, point->angle);
		choose_the_range(sdl, point);
		point->angle = point->angle + FIELD_OF_VIEW / RESOL_X;
		if ((int)point->angle > 359)
			point->angle = point->angle - 360;
		point->ray++;
	}
}
