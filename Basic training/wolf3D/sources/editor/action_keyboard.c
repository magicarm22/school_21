/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:16:31 by djast             #+#    #+#             */
/*   Updated: 2019/09/26 09:58:18 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	textinput(t_sdl *sdl)
{
	if (sdl->map_name->text_size + 1 < sdl->map_name->max_text_size)
	{
		ft_strcat(sdl->map_name->text, sdl->window_event.text.text);
		sdl->map_name->text_size++;
	}
}

int		action_keyboard(t_sdl *sdl)
{
	if (SDL_QUIT == sdl->window_event.type)
		return (1);
	else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_ESCAPE ==
				sdl->window_event.key.keysym.sym)
		return (1);
	else if (sdl->window_event.type == SDL_TEXTINPUT)
		textinput(sdl);
	else if (sdl->window_event.type == SDL_KEYDOWN)
	{
		if (sdl->window_event.key.keysym.sym == SDLK_BACKSPACE &&
				sdl->map_name->text_size > 0)
		{
			sdl->map_name->text[sdl->map_name->text_size - 1] = '\0';
			sdl->map_name->text_size--;
		}
		else if (sdl->window_event.key.keysym.sym == SDLK_a)
			sdl->mesh->x -= 5;
		else if (sdl->window_event.key.keysym.sym == SDLK_d)
			sdl->mesh->x += 5;
		else if (sdl->window_event.key.keysym.sym == SDLK_w)
			sdl->mesh->y -= 5;
		else if (sdl->window_event.key.keysym.sym == SDLK_s)
			sdl->mesh->y += 5;
	}
	return (0);
}
