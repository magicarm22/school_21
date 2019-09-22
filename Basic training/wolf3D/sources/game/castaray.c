/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castaray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:07:17 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/22 15:48:51 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	find_a_wall_hor(t_map *map_info, t_player *point, double angle) // горизонтальные пересечения
{
	double	radian_angle;
	double	delta_x;
	double	delta_y;
//	int		dest;

	delta_y = 0;
	radian_angle = angle * RADIAN;
	if (angle > 0 && angle < 180)
		point->check_hor_y = floor(point->y / 64) * 64 - 0.01;
	else if (angle > 180 && angle < 360)
		point->check_hor_y = floor(point->y / 64) * 64 + 64;
	else
		return (0);
	point->check_hor_x = point->x + (point->y - point->check_hor_y) / tan(radian_angle);
	if (point->check_hor_y < 0 || point->check_hor_x < 0 || map_info->size_x * 64 < point->check_hor_x || map_info->size_y * 64 < point->check_hor_y)
			return (0);
	if (map_info->map[(int)(point->check_hor_y / 64)][(int)(point->check_hor_x / 64)] == 1)
		return (sqrt(pow(point->check_hor_y - point->y, 2) + pow(point->check_hor_x - point->x, 2)));// distance_to_the_wall
	if (angle > 0 && angle < 180)
		delta_y = -64;
	else if (angle > 180 && angle < 360)
		delta_y = 64;
	delta_x = -delta_y / tan(radian_angle);
	//printf("hor: %f %f %f %f\n", point->check_x, point->check_y,  point->check_x / 64, point->check_y / 64);
	while (map_info->map[(int)(point->check_hor_y / 64)][(int)(point->check_hor_x / 64)] == 0)
	{
		point->check_hor_y = point->check_hor_y + delta_y;
		point->check_hor_x = point->check_hor_x + delta_x;
	//	printf("hor: %f %f %f %f\n", point->check_x, point->check_y,  point->check_x / 64, point->check_y / 64);
		if (point->check_hor_y < 0 || point->check_hor_x < 0 || map_info->size_x * 64 < point->check_hor_x || map_info->size_y * 64 < point->check_hor_y)
		{
			return (0);
		}
	}
	return (sqrt(pow(point->check_hor_y - point->y, 2) + pow(point->check_hor_x - point->x, 2)));// distance_to_the_wall
}

double	find_a_wall_vert(t_map *map_info, t_player *point, double angle)
{
	double	radian_angle;
	double	delta_x;
	double	delta_y;
//	int		dest;

	delta_x = 0;
	radian_angle = angle * RADIAN;
	if (angle > 90 && angle < 270)
		point->check_ver_x = floor(point->x / 64) * 64 - 0.01;
	else if ((angle >= 0 && angle < 90) || (angle > 270 && angle <= 360))
		point->check_ver_x = floor(point->x / 64) * 64 + 64;
	else
		return (0);
	point->check_ver_y = point->y + (point->x - point->check_ver_x) * tan(radian_angle);
//	printf("vert_b: %f %f\n", point->check_x, point->check_y);
	if (point->check_ver_y < 0 || point->check_ver_x < 0 || map_info->size_x * 64 < point->check_ver_x || map_info->size_y * 64 < point->check_ver_y)
		return (0);
	if (map_info->map[(int)(point->check_ver_y / 64)][(int)(point->check_ver_x / 64)] == 1)
		return (sqrt(pow(point->check_ver_y - point->y, 2) + pow(point->check_ver_x - point->x, 2)));// distance_to_the_wall
	if (angle > 90 && angle < 270)
		delta_x = -64;
	else if ((angle >= 0 && angle < 90) || (angle > 270 && angle <= 360))
		delta_x = 64;
	delta_y = -delta_x * tan(radian_angle);
//	printf("vert: %f %f %f %f\n", point->check_x, point->check_y,  point->check_x / 64, point->check_y / 64);
	while (map_info->map[(int)(point->check_ver_y / 64)][(int)(point->check_ver_x / 64)] == 0)
	{
		point->check_ver_x = point->check_ver_x + delta_x;
		point->check_ver_y = point->check_ver_y + delta_y;
	//	printf("vert: %f %f %f %f\n", point->check_x, point->check_y,  point->check_x / 64, point->check_y / 64);
		if (point->check_ver_y < 0 || point->check_ver_x < 0 || map_info->size_x * 64 < point->check_ver_x || map_info->size_y * 64 < point->check_ver_y)
			return (0);
	}
	return (sqrt(pow(point->check_ver_y - point->y, 2) + pow(point->check_ver_x - point->x, 2)));// distance_to_the_wall
}

void	cast_a_ray(t_SDL *sdl, t_player *point, t_map *map_info)
{
	int		ray;
	double	angle;
	double	dist_hor;
	double	dist_vert;

	ray = 0;
	angle = point->point_of_view - (FIELD_OF_VIEW / 2);
	if (angle < 0)
		angle = angle + 360;
	while (ray <= RESOL_X)
	{
		dist_hor = find_a_wall_hor(map_info, point, angle);
		dist_vert = find_a_wall_vert(map_info, point, angle);
		if ((dist_hor <= dist_vert && dist_hor != 0) || dist_vert == 0)
		{
			point->hor_or_vert = 1;
			point->strip = (int)point->check_hor_x;
			draw_a_wall(sdl, point, ray, dist_hor * cos((point->point_of_view - angle) * RADIAN));
		}
		else if ((dist_hor >= dist_vert && dist_vert != 0) || dist_hor == 0)
		{
			point->hor_or_vert = 2;
			point->strip = (int)point->check_ver_y;
			draw_a_wall(sdl, point, ray, dist_vert * cos((point->point_of_view - angle) * RADIAN));
		}
		angle = angle + FIELD_OF_VIEW / RESOL_X;
		if ((int)angle > 359)
			angle = angle - 360;
		ray++;
	}
}
