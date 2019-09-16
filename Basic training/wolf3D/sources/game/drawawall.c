/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawawall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:00:06 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/10 13:20:29 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_a_wall(t_SDL *sdl, int slice, double distance_to_the_wall)
{
	int			wall_height;
	int			top_of_the_wall;
	SDL_Rect	newrect;

	wall_height = 64 / distance_to_the_wall * ((RESOL_X / 2) / (tan(FIELD_OF_VIEW / 2 * 0.0175)));
	top_of_the_wall = RESOL_Y / 2 - wall_height / 2; // 100 - горизонтальный центр проекции
    newrect.x = (RESOL_X - slice) * (SIZE_WIN_X / RESOL_X);// ширина сегмента в пикселях;
    newrect.y = top_of_the_wall * RESOL_RATIO_Y;// в отношении к пикселям;
    newrect.w = (SIZE_WIN_X / RESOL_X);
	newrect.h = wall_height * RESOL_RATIO_X;

	// Set render color (rect will be rendered in this color)
	SDL_SetRenderDrawColor(sdl->renderer, 54, 213, 125, 0);

	// Render rect
	SDL_RenderFillRect(sdl->renderer, &newrect);

	// SDL_RenderDrawRect(renderer, &newrect); // просто рамочка

	// Render the rect to the screen

}
