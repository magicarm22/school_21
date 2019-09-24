/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:27:22 by djast             #+#    #+#             */
/*   Updated: 2019/09/24 14:43:46 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			draw_button(t_sdl *sdl, SDL_Rect r, char *name, int color)
{
	SDL_Color	*color_text;

	if (color == COLOR_PUSHED)
		SDL_SetRenderDrawColor(sdl->renderer, 50, 205, 50, 255);
	else if (color == COLOR_UNPUSHED)
		SDL_SetRenderDrawColor(sdl->renderer, 255, 69, 0, 255);
	else if (color == COLOR_NEUTRAL)
		SDL_SetRenderDrawColor(sdl->renderer, 64, 64, 64, 255);
	SDL_RenderFillRect(sdl->renderer, &r);
	color_text = create_sdl_color(255, 255, 255, 255);
	draw_text(sdl, name, r, *color_text);
	free(color_text);
}

static void		draw_mesh(t_sdl *sdl)
{
	int i;

	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
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
	SDL_Rect	*r;
	int			i;
	int			j;

	i = 0;
	while (i != sdl->mesh->size_y)
	{
		j = 0;
		while (j != sdl->mesh->size_x)
		{
			r = create_sdl_rect(sdl->mesh->x + j * sdl->mesh->zoom,
								sdl->mesh->y + i * sdl->mesh->zoom,
								sdl->mesh->zoom, sdl->mesh->zoom);
			if (sdl->mesh->map[i][j] == 0)
				SDL_RenderCopy(sdl->renderer, sdl->floor, NULL, r);
			else if (sdl->mesh->map[i][j] == 1)
				SDL_RenderCopy(sdl->renderer, sdl->wall, NULL, r);
			else if (sdl->mesh->map[i][j] == 2)
				SDL_RenderCopy(sdl->renderer, sdl->player_texture, NULL, r);
			free(r);
			j++;
		}
		i++;
	}
}

void			draw_full(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->backgroud, NULL, NULL);
	draw_texture(sdl);
	draw_mesh(sdl);
	draw_right_panel(sdl);
	if (sdl->status_save == ERROR_NO_PLAYER)
		draw_result_text(sdl, "No player on map!", COLOR_RESULT_ERROR);
	else if (sdl->status_save == ERROR_NO_FILENAME)
		draw_result_text(sdl, "No filename!", COLOR_RESULT_ERROR);
	else if (sdl->status_save == ERROR_NO_FILE)
		draw_result_text(sdl, "No such file!", COLOR_RESULT_ERROR);
	else if (sdl->status_save == ERROR_NON_VALID_FILE)
		draw_result_text(sdl, "Non valid file!", COLOR_RESULT_ERROR);
	else if (sdl->status_save == ERROR_OK)
		draw_result_text(sdl, "Action complete!", COLOR_RESULT_OK);
	SDL_RenderPresent(sdl->renderer);
}
