/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:31:15 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/07 13:22:57 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_s(t_sdl *sdl, t_map *map_info, t_player *player)
{
	int i;
	int status;

	i = 0;
	status = 1;
	while (i < 60)
	{
		if (map_info->map[(int)(player->y + 60 * sin(player->point_of_view *
			RADIAN)) / 64][(int)(player->x + (-60 *
			cos(player->point_of_view * RADIAN))) / 64] == 1)
		{
			status = 0;
			break ;
		}
		i++;
	}
	if (status == 1)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += -40 * cos(player->point_of_view * RADIAN);
		player->y += 40 * sin(player->point_of_view * RADIAN);
	}
}

void	key_w(t_sdl *sdl, t_map *map_info, t_player *player)
{
	int i;
	int status;

	i = 0;
	status = 1;
	while (i < 60)
	{
		if (map_info->map[(int)(player->y + (-i * sin(player->point_of_view *
				RADIAN))) / 64][(int)((player->x + i *
				cos(player->point_of_view * RADIAN)) / 64)] == 1)
		{
			status = 0;
			break ;
		}
		i++;
	}
	if (status == 1)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += 40 * cos(player->point_of_view * RADIAN);
		player->y += -40 * sin(player->point_of_view * RADIAN);
	}
}

void	key_d(t_sdl *sdl, t_map *map_info, t_player *player)
{
	int i;
	int status;

	i = 0;
	status = 1;
	while (i < 50)
	{
		if (map_info->map[(int)(player->y + (-i * sin((player->point_of_view +
				270) * RADIAN))) / 64][(int)(player->x + i *
				cos((player->point_of_view + 270) * RADIAN)) / 64] == 1)
		{
			status = 0;
			break ;
		}
		i++;
	}
	if (status == 1)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += 30 * cos((player->point_of_view + 270) * RADIAN);
		player->y += -30 * sin((player->point_of_view + 270) * RADIAN);
	}
}

void	key_a(t_sdl *sdl, t_map *map_info, t_player *player)
{
	int i;
	int status;

	i = 0;
	status = 1;
	while (i < 50)
	{
		if (map_info->map[(int)(player->y + (-i * sin((player->point_of_view +
			90) * RADIAN))) / 64][(int)(player->x + i *
			cos((player->point_of_view + 90) * RADIAN)) / 64] == 1)
		{
			status = 0;
			break ;
		}
		i++;
	}
	if (status == 1)
	{
		if (Mix_Playing(1) == 0)
			Mix_PlayChannel(1, sdl->steps, 0);
		player->x += 30 * cos((player->point_of_view + 90) * RADIAN);
		player->y += -30 * sin((player->point_of_view + 90) * RADIAN);
	}
}
