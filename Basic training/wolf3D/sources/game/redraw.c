/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:52:19 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/26 13:09:45 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	redraw(t_sdl *sdl, t_map *map_info, t_player *player)
{
	SDL_Rect	floor;

	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);
	floor.x = 0;
	floor.y = SIZE_WIN_Y / 2;
	floor.w = SIZE_WIN_X;
	floor.h = SIZE_WIN_Y / 2;
	SDL_SetRenderDrawColor(sdl->renderer, 30, 50, 20, 0);
	SDL_RenderFillRect(sdl->renderer, &floor);
	draw_the_sky(sdl, player->point_of_view);
	cast_a_ray(sdl, player, map_info);
	draw_a_weapon(sdl, player);
	SDL_RenderPresent(sdl->renderer);
}
