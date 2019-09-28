/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:31:15 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/28 13:32:21 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_s(t_sdl *sdl, t_map *map_info, t_player *player)
{
	if (map_info->map[(int)(player->y + 60 * sin(player->point_of_view *
			RADIAN)) / 64][(int)(player->x + (-60 *
			cos(player->point_of_view * RADIAN))) / 64] == 0)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += -40 * cos(player->point_of_view * RADIAN);
		player->y += 40 * sin(player->point_of_view * RADIAN);
	}
}

void	key_w(t_sdl *sdl, t_map *map_info, t_player *player)
{
	if (map_info->map[(int)(player->y + (-60 * sin(player->point_of_view *
			RADIAN))) / 64][(int)((player->x + 60 *
			cos(player->point_of_view * RADIAN)) / 64)] == 0)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += 40 * cos(player->point_of_view * RADIAN);
		player->y += -40 * sin(player->point_of_view * RADIAN);
	}
}

void	key_d(t_sdl *sdl, t_map *map_info, t_player *player)
{
	if (map_info->map[(int)(player->y + (-50 * sin((player->point_of_view +
			270) * RADIAN))) / 64][(int)(player->x + 50 *
			cos((player->point_of_view + 270) * RADIAN)) / 64] == 0)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += 30 * cos((player->point_of_view + 270) * RADIAN);
		player->y += -30 * sin((player->point_of_view + 270) * RADIAN);
	}
}

void	key_a(t_sdl *sdl, t_map *map_info, t_player *player)
{
	if (map_info->map[(int)(player->y + (-50 * sin((player->point_of_view +
			90) * RADIAN))) / 64][(int)(player->x + 50 *
			cos((player->point_of_view + 90) * RADIAN)) / 64] == 0)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += 30 * cos((player->point_of_view + 90) * RADIAN);
		player->y += -30 * sin((player->point_of_view + 90) * RADIAN);
	}
}
