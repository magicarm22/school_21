/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawawall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:00:06 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/23 14:18:58 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_a_wall(t_SDL *sdl, t_player *point, int slice, double distance_to_the_wall)
{
	double		wall_height;
	double		top_of_the_wall;
	SDL_Rect	newrect;
	SDL_Rect	rectwall;

	// int a = point->x;
	// a++;

	wall_height = 64 / distance_to_the_wall * ((RESOL_X / 4) / (tan(FIELD_OF_VIEW / 2 * RADIAN)));
	top_of_the_wall = RESOL_Y / 2 - wall_height / 2; // 100 - горизонтальный центр проекции
	newrect.x = (RESOL_X - slice) * (SIZE_WIN_X / RESOL_X); // ширина сегмента в пикселях;
	newrect.y = top_of_the_wall * RESOL_RATIO_Y; // в отношении к пикселям;
	newrect.w = (SIZE_WIN_X / RESOL_X);
	newrect.h = wall_height * RESOL_RATIO_Y;

	//	rectwall.x = newrect.x % 64;// - RESOL_RATIO_X; // прямоугольник для текстуры
	rectwall.x = point->strip % 64; //strip (крайняя правая точка) =
									//check_x или check_y в зависимости от направления стены
	//	rectwall.x = ((int)point->check_x - RESOL_RATIO_X) % 64;
	rectwall.y = 0;
	rectwall.w = 1;
	rectwall.h = 64;// * RESOL_RATIO_Y;

	// Set render color (rect will be rendered in this color)
	//	SDL_SetRenderDrawColor(sdl->renderer, 102, 051, 051, 0);

	// Render rect
	//	SDL_RenderFillRect(sdl->renderer, &newrect);

	if (point->hor_or_vert == 1)
	{
		if (point->check_hor_y > point->y)
			SDL_RenderCopy(sdl->renderer, sdl->texture_north, &rectwall, &newrect);
		else
			SDL_RenderCopy(sdl->renderer, sdl->texture_south, &rectwall, &newrect);
	}
	else
	{
		if (point->check_ver_x > point->x)
			SDL_RenderCopy(sdl->renderer, sdl->texture_east, &rectwall, &newrect);
		else
			SDL_RenderCopy(sdl->renderer, sdl->texture_west, &rectwall, &newrect);
	}

	// SDL_RenderDrawRect(renderer, &newrect); // просто рамочка

	// Render the rect to the screen

}
