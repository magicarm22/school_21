/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:14:23 by djast             #+#    #+#             */
/*   Updated: 2019/09/16 13:21:12 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void reset_swaped(t_sdl *sdl)
{
	int i;
	int j;

	i = 0;
	while (i < sdl->mesh->size_y)
	{
		j = 0;
		while (j < sdl->mesh->size_x)
			sdl->mesh->swaped[i][j++] = 0;
		i++;
	}
}

void mouse_action(t_sdl *sdl, int *click)
{
	if (sdl->windowEvent.type == SDL_MOUSEBUTTONDOWN &&
					sdl->windowEvent.button.button == SDL_BUTTON_LEFT)
		*click = 1;
	else if (sdl->windowEvent.type == SDL_MOUSEMOTION)
	{
		if (sdl->windowEvent.button.button == SDL_BUTTON_LEFT && *click == 1 && sdl->mesh->swaped[(sdl->windowEvent.button.y - sdl->mesh->y) / sdl->mesh->zoom][(sdl->windowEvent.button.x - sdl->mesh->x) / sdl->mesh->zoom] == 0 && 
			(sdl->windowEvent.button.y - sdl->mesh->y) / sdl->mesh->zoom < sdl->mesh->size_y && (sdl->windowEvent.button.x - sdl->mesh->x) / sdl->mesh->zoom < sdl->mesh->size_x )
		{
			sdl->mesh->map[(sdl->windowEvent.button.y - sdl->mesh->y) / sdl->mesh->zoom][(sdl->windowEvent.button.x - sdl->mesh->x) / sdl->mesh->zoom] = sdl->mesh->map[(sdl->windowEvent.button.y - sdl->mesh->y) / sdl->mesh->zoom][(sdl->windowEvent.button.x - sdl->mesh->x) / sdl->mesh->zoom] == 0 ? 1 : 0;
			sdl->mesh->swaped[(sdl->windowEvent.button.y - sdl->mesh->y) / sdl->mesh->zoom][(sdl->windowEvent.button.x - sdl->mesh->x) / sdl->mesh->zoom] = 1;
		}
	}
	else if (sdl->windowEvent.type == SDL_MOUSEBUTTONUP &&
			sdl->windowEvent.button.button == SDL_BUTTON_LEFT)
	{
		reset_swaped(sdl);
		*click = 0;
	}
}