/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_wall_vert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:06:45 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/25 14:19:58 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		find_crossing_vert(t_player *point, t_map *map_info)
{
	while (map_info->map[(int)(point->check_ver_y / 64)]
				[(int)(point->check_ver_x / 64)] == 0)
	{
		point->check_ver_x = point->check_ver_x + point->delta_x_vert;
		point->check_ver_y = point->check_ver_y + point->delta_y_vert;
		if (point->check_ver_y < 0 || point->check_ver_x < 0 ||
				map_info->size_x * 64 < point->check_ver_x ||
				map_info->size_y * 64 < point->check_ver_y)
			return (1);
	}
	return (0);
}

int		count_check_x(t_player *point, double angle)
{
	if (angle > 90 && angle < 270)
		point->check_ver_x = floor(point->x / 64) * 64 - 0.01;
	else if ((angle >= 0 && angle < 90) || (angle > 270 && angle <= 360))
		point->check_ver_x = floor(point->x / 64) * 64 + 64;
	else
		return (1);
	return (0);
}

double	find_a_wall_vert(t_map *map_info, t_player *point, double angle)
{
	point->delta_x_vert = 0;
	point->radian_angle_vert = angle * RADIAN;
	if (count_check_x(point, angle) == 1)
		return (0);
	point->check_ver_y = point->y + (point->x - point->check_ver_x) *
				tan(point->radian_angle_vert);
	if (point->check_ver_y < 0 || point->check_ver_x < 0 ||
				map_info->size_x * 64 < point->check_ver_x ||
				map_info->size_y * 64 < point->check_ver_y)
		return (0);
	if (map_info->map[(int)(point->check_ver_y / 64)]
				[(int)(point->check_ver_x / 64)] == 1)
	{
		point->res_vert = sqrt(pow(point->check_ver_y - point->y, 2) +
				pow(point->check_ver_x - point->x, 2));
		return (point->res_vert);
	}
	if (angle > 90 && angle < 270)
		point->delta_x_vert = -64;
	else if ((angle >= 0 && angle < 90) || (angle > 270 && angle <= 360))
		point->delta_x_vert = 64;
	point->delta_y_vert = -point->delta_x_vert * tan(point->radian_angle_vert);
	return (find_crossing_vert(point, map_info) == 1 ? 0 :
			sqrt(pow(point->check_ver_y - point->y, 2) +
			pow(point->check_ver_x - point->x, 2)));
}
