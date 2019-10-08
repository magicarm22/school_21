/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/08 12:56:40 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_sdl(t_sdl *sdl)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	sdl->shooting = Mix_LoadWAV("resources/game/shoot.wav");
	sdl->steps = Mix_LoadWAV("resources/game/step.wav");
	sdl->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
					SDL_WINDOW_OPENGL);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
					SDL_RENDERER_ACCELERATED);
	SDL_SetWindowFullscreen(sdl->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_ShowCursor(0);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	load_bmps(sdl);
}

void	check_map_info(t_map *map_info, t_player *player)
{
	if (map_info == NULL)
	{
		write(1, "Wrong with map format\n", 22);
		free(player);
		exit(-1);
	}
}

int		main(int argc, char **argv)
{
	t_map		*map_info;
	t_player	*player;
	int			fd;
	t_sdl		*sdl;

	if (argc < 2)
	{
		write(1, "Error, write map name\n", 22);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) == -1)
	{
		close(fd);
		write(1, "Error, no such map\n", 19);
		return (-1);
	}
	player = (t_player *)malloc(sizeof(t_player));
	map_info = get_map_from_file(player, fd);
	check_map_info(map_info, player);
	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	init_sdl(sdl);
	redraw(sdl, map_info, player);
	big_loop(sdl, map_info, player);
}
