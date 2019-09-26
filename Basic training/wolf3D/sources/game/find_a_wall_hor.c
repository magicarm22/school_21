/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_wall_hor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:00:32 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/25 14:19:42 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		find_crossing_hor(t_player *point, t_map *map_info)
{
	while (map_info->map[(int)(point->check_hor_y / 64)]
				[(int)(point->check_hor_x / 64)] == 0)
	{
		point->check_hor_y = point->check_hor_y + point->delta_y_hor;
		point->check_hor_x = point->check_hor_x + point->delta_x_hor;
		if (point->check_hor_y < 0 || point->check_hor_x < 0 ||
				map_info->size_x * 64 < point->check_hor_x ||
				map_info->size_y * 64 < point->check_hor_y)
			return (1);
	}
	return (0);
}

int		count_check_y(t_player *point, double angle)
{
	if (angle > 0 && angle < 180)
		point->check_hor_y = floor(point->y / 64) * 64 - 0.01;
	else if (angle > 180 && angle < 360)
		point->check_hor_y = floor(point->y / 64) * 64 + 64;
	else
		return (1);
	return (0);
}

double	find_a_wall_hor(t_map *map_info, t_player *point, double angle)
{
	point->delta_y_hor = 0;
	point->radian_angle_hor = angle * RADIAN;
	if (count_check_y(point, angle) == 1)
		return (0);
	point->check_hor_x = point->x + (point->y - point->check_hor_y) /
				tan(point->radian_angle_hor);
	if (point->check_hor_y < 0 || point->check_hor_x < 0 ||
				map_info->size_x * 64 < point->check_hor_x ||
				map_info->size_y * 64 < point->check_hor_y)
		return (0);
	if (map_info->map[(int)(point->check_hor_y / 64)]
				[(int)(point->check_hor_x / 64)] == 1)
	{
		point->res_hor = sqrt(pow(point->check_hor_y - point->y, 2) +
				pow(point->check_hor_x - point->x, 2));
		return (point->res_hor);
	}
	if (angle > 0 && angle < 180)
		point->delta_y_hor = -64;
	else if (angle > 180 && angle < 360)
		point->delta_y_hor = 64;
	point->delta_x_hor = -point->delta_y_hor / tan(point->radian_angle_hor);
	return (find_crossing_hor(point, map_info) == 1 ? 0 :
			sqrt(pow(point->check_hor_y - point->y, 2) +
			pow(point->check_hor_x - point->x, 2)));
}
