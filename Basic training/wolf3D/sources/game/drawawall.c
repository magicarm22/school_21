/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawawall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:00:06 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/24 14:24:09 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_walls(t_player *point, int slice, SDL_Rect *rect, SDL_Rect *wall)
{
	double		wall_height;
	double		top_of_the_wall;

	wall_height = 64 / point->distance * ((RESOL_X / 4) /
					(tan(FIELD_OF_VIEW / 2 * RADIAN)));
	top_of_the_wall = RESOL_Y / 2 - wall_height / 2;
	rect->x = (RESOL_X - slice) * (SIZE_WIN_X / RESOL_X);
	rect->y = top_of_the_wall * RESOL_RATIO_Y;
	rect->w = (SIZE_WIN_X / RESOL_X);
	rect->h = wall_height * RESOL_RATIO_Y;
	wall->x = point->strip % 64;
	wall->y = 0;
	wall->w = 1;
	wall->h = 64 * RESOL_RATIO_Y;
}

void	draw_a_wall(t_sdl *sdl, t_player *point, int slice, double distance)
{
	SDL_Rect	rect;
	SDL_Rect	wall;

	point->distance = distance;
	init_walls(point, slice, &rect, &wall);
	if (point->hor_or_vert == 1)
	{
		if (point->check_hor_y > point->y)
			SDL_RenderCopy(sdl->renderer, sdl->texture_north, &wall, &rect);
		else
			SDL_RenderCopy(sdl->renderer, sdl->texture_south, &wall, &rect);
	}
	else
	{
		if (point->check_ver_x > point->x)
			SDL_RenderCopy(sdl->renderer, sdl->texture_east, &wall, &rect);
		else
			SDL_RenderCopy(sdl->renderer, sdl->texture_west, &wall, &rect);
	}
}
