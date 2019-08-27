/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/08/27 19:21:50 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main (int argc, char **argv)
{
	t_map *map_info;
	t_player *player;
	int fd;

	if (argc < 2)
	{
		write(1, "Error, write map name\n", 22);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) == -1)
	{
		write(1, "Error, no such map\n", 19);
		return (-1);
	}
	player = (t_player *)malloc(sizeof(t_player));
	map_info = get_map_from_file(player, fd);
	if (map_info == NULL)
	{
		write(1, "Wrong with map format\n", 22);
		return (-1);
	}
	// t_SDL *SDL;

	// SDL = (t_SDL *)malloc(sizeof(t_SDL));
	// SDL_Init(SDL_INIT_VIDEO);
 //   	SDL->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
 //                   SDL_WINDOWPOS_UNDEFINED, 1400, 1600,
 //                   SDL_WINDOW_OPENGL);
 //    SDL->renderer =  SDL_CreateRenderer( SDL->window, -1, SDL_RENDERER_ACCELERATED);
 //    //SDL_SetWindowFullscreen(SDL->window, SDL_WINDOW_FULLSCREEN_DESKTOP);

	// while ( 1 )
	// {
	// 	if ( SDL_PollEvent( &(SDL->windowEvent) ) )
	// 	{
	// 		if ( SDL_QUIT == SDL->windowEvent.type )
	// 			break;
	// 		else if ( SDLK_ESCAPE == SDL->windowEvent.key.keysym.sym )
	// 			break;
	// 	}
	// }
	// SDL_DestroyWindow(SDL->window);
	// SDL_Quit();
}
