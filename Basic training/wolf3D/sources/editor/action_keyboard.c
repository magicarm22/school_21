/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:16:31 by djast             #+#    #+#             */
/*   Updated: 2019/09/21 13:37:27 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		action_keyboard(t_sdl *sdl)
{
	if (SDL_QUIT == sdl->windowEvent.type)
		return (1);
	else if (sdl->windowEvent.type == SDL_KEYDOWN && SDLK_ESCAPE == sdl->windowEvent.key.keysym.sym)
		return (1);
	else if (sdl->windowEvent.type == SDL_TEXTINPUT)
	{
		printf("AAAA\n");
		if (sdl->map_name->text_size + 1 < sdl->map_name->max_text_size)
		{
			ft_strcat(sdl->map_name->text, sdl->windowEvent.text.text);
			sdl->map_name->text_size++;
		}
	}
	else if (sdl->windowEvent.type == SDL_KEYDOWN)
	{
		if (sdl->windowEvent.key.keysym.sym == SDLK_BACKSPACE && sdl->map_name->text_size > 0)
		{
			sdl->map_name->text[sdl->map_name->text_size - 1] = '\0';
			sdl->map_name->text_size--;
		}
		else if (sdl->windowEvent.key.keysym.sym == SDLK_a)
			sdl->mesh->x -= 5;
		else if (sdl->windowEvent.key.keysym.sym == SDLK_d)
			sdl->mesh->x += 5;
		else if (sdl->windowEvent.key.keysym.sym == SDLK_w)
			sdl->mesh->y -= 5;
		else if (sdl->windowEvent.key.keysym.sym == SDLK_s)
			sdl->mesh->y += 5;
	}
	
	return (0);
}
