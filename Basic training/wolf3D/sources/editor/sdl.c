/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:40:04 by djast             #+#    #+#             */
/*   Updated: 2019/09/24 14:56:50 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		init_textures(t_sdl *sdl)
{
	sdl->surface = SDL_LoadBMP("resources/editor/floor.bmp");
	sdl->floor = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
	sdl->surface = SDL_LoadBMP("resources/editor/wall.bmp");
	sdl->wall = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
	sdl->surface = SDL_LoadBMP("resources/editor/player.bmp");
	sdl->player_texture = SDL_CreateTextureFromSurface(sdl->renderer,
							sdl->surface);
	SDL_FreeSurface(sdl->surface);
	sdl->surface = SDL_LoadBMP("resources/editor/background.bmp");
	sdl->backgroud = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
	sdl->font = TTF_OpenFont("resources/editor/34455.ttf", 500);
	sdl->surface = SDL_LoadBMP("resources/editor/arrow-up.bmp");
	sdl->arrow_up = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
	sdl->surface = SDL_LoadBMP("resources/editor/arrow-down.bmp");
	sdl->arrow_down = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
}

t_sdl			*init_sdl(void)
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO);
	sdl->window = SDL_CreateWindow("Editor", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
					SDL_WINDOW_OPENGL);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
					SDL_RENDERER_ACCELERATED);
	sdl->button_pushed = WALL_PUSH;
	sdl->input_pushed = 0;
	sdl->player = NULL;
	sdl->status_save = 0;
	init_textures(sdl);
	return (sdl);
}
