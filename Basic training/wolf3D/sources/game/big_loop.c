/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:17:53 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/26 13:20:12 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mousebutton(t_sdl *sdl, t_player *player)
{
	if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
			sdl->window_event.button.button == SDL_BUTTON_LEFT)
	{
		if (player->is_shooting == 0)
		{
			Mix_PlayChannel(2, sdl->shooting, 0);
			player->is_shooting = 1;
			player->shooting_frame = 0;
			player->shooting_time = SDL_GetTicks();
		}
	}
}

void	mousemotion(t_sdl *sdl, t_player *player)
{
	player->point_of_view -= sdl->window_event.motion.xrel / 12;
	if (player->point_of_view >= 361)
		player->point_of_view = 1;
	else if (player->point_of_view <= 0)
		player->point_of_view = 360;
}

void	poll_event(t_sdl *sdl, t_map *map_info, t_player *player)
{
	if (SDL_PollEvent(&(sdl->window_event)))
	{
		if (sdl->window_event.type == SDL_KEYDOWN && SDL_QUIT ==
					sdl->window_event.type)
			exit(0);
		else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_ESCAPE ==
					sdl->window_event.key.keysym.sym)
			exit(0);
		else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_a ==
					sdl->window_event.key.keysym.sym)
			key_a(sdl, map_info, player);
		else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_d ==
					sdl->window_event.key.keysym.sym)
			key_d(sdl, map_info, player);
		else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_w ==
					sdl->window_event.key.keysym.sym)
			key_w(sdl, map_info, player);
		else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_s ==
					sdl->window_event.key.keysym.sym)
			key_s(sdl, map_info, player);
		else if (sdl->window_event.type == SDL_MOUSEMOTION)
			mousemotion(sdl, player);
		mousebutton(sdl, player);
		redraw(sdl, map_info, player);
	}
}

void	big_loop(t_sdl *sdl, t_map *map_info, t_player *player)
{
	while (1)
	{
		poll_event(sdl, map_info, player);
		if (player->shooting_frame != PISTOL_LAST_FRAME)
			redraw(sdl, map_info, player);
		else
			player->is_shooting = 0;
	}
}
