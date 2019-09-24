/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:01:05 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/24 14:24:35 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_bmps(t_sdl *sdl)
{
	sdl->temp = SDL_LoadBMP("resources/game/north.bmp");
	sdl->texture_north = SDL_CreateTextureFromSurface(sdl->renderer, sdl->temp);
	SDL_FreeSurface(sdl->temp);
	sdl->temp = SDL_LoadBMP("resources/game/south.bmp");
	sdl->texture_south = SDL_CreateTextureFromSurface(sdl->renderer, sdl->temp);
	SDL_FreeSurface(sdl->temp);
	sdl->temp = SDL_LoadBMP("resources/game/east.bmp");
	sdl->texture_east = SDL_CreateTextureFromSurface(sdl->renderer, sdl->temp);
	SDL_FreeSurface(sdl->temp);
	sdl->temp = SDL_LoadBMP("resources/game/west.bmp");
	sdl->texture_west = SDL_CreateTextureFromSurface(sdl->renderer, sdl->temp);
	SDL_FreeSurface(sdl->temp);
	sdl->temp = SDL_LoadBMP("resources/game/animated_pistol.bmp");
	sdl->pistol = SDL_CreateTextureFromSurface(sdl->renderer, sdl->temp);
	SDL_FreeSurface(sdl->temp);
	sdl->temp = SDL_LoadBMP("resources/game/bluesky.bmp");
	sdl->texture_sky = SDL_CreateTextureFromSurface(sdl->renderer, sdl->temp);
	SDL_FreeSurface(sdl->temp);
}
