/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/09/16 13:21:13 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int main()
{
	t_sdl *sdl;
	int click;

	sdl = init_sdl();
    init_mesh(&sdl);
    init_map(&(sdl->mesh));
    draw_full(sdl);
    click = 0;
	while (1)
	{
		if (SDL_PollEvent(&(sdl->windowEvent)))
		{
			if (SDL_QUIT == sdl->windowEvent.type)
			 	break;
			else if (sdl->windowEvent.type == SDL_KEYDOWN && SDLK_ESCAPE == sdl->windowEvent.key.keysym.sym)
				break;
			else if (sdl->windowEvent.type == SDL_MOUSEWHEEL)
    		{
				if (sdl->windowEvent.wheel.y > 0)
				{
					if (sdl->mesh->zoom != INT_MAX - 2)
						sdl->mesh->zoom += 2;
				}
				else if (sdl->windowEvent.wheel.y < 0)
				{
					if (sdl->mesh->zoom != 2)
						sdl->mesh->zoom -= 2;
				}
			}
			mouse_action(sdl, &click);
			draw_full(sdl);
		}
	}
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}