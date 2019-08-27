/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/08/27 14:10:16 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int	main ()
{
	SDL_Window      *window;
    SDL_Renderer    *renderer;
	SDL_Event		windowEvent;

	SDL_Init(SDL_INIT_VIDEO);
   	window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED,
                   SDL_WINDOWPOS_UNDEFINED, 1400, 1600,
                   SDL_WINDOW_OPENGL);
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetWindowFullscreen(SDL->window, SDL_WINDOW_FULLSCREEN_DESKTOP);

	while ( 1 )
	{
		if ( SDL_PollEvent( &windowEvent ) )
		{
			if ( SDL_QUIT == windowEvent.type )
				break;
			else if ( SDLK_ESCAPE == windowEvent.key.keysym.sym )
				break;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
}
