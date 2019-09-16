/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:27:22 by djast             #+#    #+#             */
/*   Updated: 2019/09/16 13:18:09 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void 	draw_right_panel(t_sdl *sdl)
{
	SDL_Rect r;

	r.x = SIZE_WIN_X * 0.7;
	r.y = 0;
	r.w = SIZE_WIN_X * 0.3;
	r.h = SIZE_WIN_Y;
	SDL_SetRenderDrawColor(sdl->renderer, 128, 128, 128, 255);

	SDL_RenderFillRect(sdl->renderer, &r);
}

static void 	draw_mesh(t_sdl *sdl)
{
	int i;

	SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 255, 255);
	i = 0;
	while (i != sdl->mesh->size_x + 1)
	{
		SDL_RenderDrawLine(sdl->renderer,
							sdl->mesh->x + i * sdl->mesh->zoom, sdl->mesh->y,
							sdl->mesh->x + i * sdl->mesh->zoom,
							sdl->mesh->y + sdl->mesh->zoom * sdl->mesh->size_y);
		i++;
	}
	i = 0;
	while (i != sdl->mesh->size_y + 1)
	{
		SDL_RenderDrawLine(sdl->renderer,
							sdl->mesh->x, sdl->mesh->y + i * sdl->mesh->zoom,
							sdl->mesh->x + sdl->mesh->zoom * sdl->mesh->size_x,
							sdl->mesh->y + i * sdl->mesh->zoom);
		i++;
	}
}

void			draw_texture(t_sdl *sdl)
{
	SDL_Rect r;
	int i;
	int j;

	i = 0;
	while (i != sdl->mesh->size_y)
	{
		j = 0;
		while (j != sdl->mesh->size_x)
		{
			r.x = sdl->mesh->x + j * sdl->mesh->zoom;
			r.y = sdl->mesh->y + i * sdl->mesh->zoom;
			r.w = sdl->mesh->zoom;
			r.h = sdl->mesh->zoom;
			if (sdl->mesh->map[i][j] == 0)
				SDL_RenderCopy(sdl->renderer, sdl->floor, NULL, &r);
			else if (sdl->mesh->map[i][j] == 1)
				SDL_RenderCopy(sdl->renderer, sdl->wall, NULL, &r);
			j++;
		}
		i++;
	}
}

void			draw_full(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);
	draw_texture(sdl);
	draw_mesh(sdl);
	draw_right_panel(sdl);
	SDL_RenderPresent(sdl->renderer);
}