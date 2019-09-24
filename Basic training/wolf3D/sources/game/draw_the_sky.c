/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_sky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:40:01 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/24 14:24:28 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	coef(double left_width, double right_width)
{
	double		coef;

	coef = left_width / (left_width + right_width);
	return (coef);
}

void	draw_the_sky_parts(t_sdl *sdl, int point_of_view)
{
	SDL_Rect	sky_background_l;
	SDL_Rect	sky_l;
	SDL_Rect	sky_background_r;
	SDL_Rect	sky_r;

	if (point_of_view >= 330)
		point_of_view = point_of_view - 360;
	sky_l.x = SKY_IMAGE_X - (point_of_view + 30) * (SKY_IMAGE_X / 360);
	sky_l.y = 0;
	sky_l.w = (point_of_view + 30) * (SKY_IMAGE_X / 360);
	sky_l.h = SKY_IMAGE_Y;
	sky_r.x = 0;
	sky_r.y = 0;
	sky_r.w = (60 - (point_of_view + 30)) * (SKY_IMAGE_X / 360);
	sky_r.h = SKY_IMAGE_Y;
	sky_background_l.x = 0;
	sky_background_l.y = 0;
	sky_background_l.w = SIZE_WIN_X * coef(sky_l.w, sky_r.w);
	sky_background_l.h = SIZE_WIN_Y / 2;
	sky_background_r.x = SIZE_WIN_X * coef(sky_l.w, sky_r.w);
	sky_background_r.y = 0;
	sky_background_r.w = SIZE_WIN_X * (1 - coef(sky_l.w, sky_r.w));
	sky_background_r.h = SIZE_WIN_Y / 2;
	SDL_RenderCopy(sdl->renderer, sdl->texture_sky, &sky_l, &sky_background_l);
	SDL_RenderCopy(sdl->renderer, sdl->texture_sky, &sky_r, &sky_background_r);
}

void	draw_the_sky_full(t_sdl *sdl, int point_of_view)
{
	SDL_Rect	sky_background_l;
	SDL_Rect	sky_l;

	sky_background_l.x = 0;
	sky_background_l.y = 0;
	sky_background_l.w = SIZE_WIN_X;
	sky_background_l.h = SIZE_WIN_Y / 2;
	sky_l.x = SKY_IMAGE_X - (point_of_view - 30) * (SKY_IMAGE_X / 360);
	sky_l.y = 0;
	sky_l.w = (SKY_IMAGE_X / 360) * 60;
	sky_l.h = SKY_IMAGE_Y;
	SDL_RenderCopy(sdl->renderer, sdl->texture_sky, &sky_l, &sky_background_l);
}

void	draw_the_sky(t_sdl *sdl, int point_of_view)
{
	if (point_of_view > 30 && point_of_view <= 330)
		draw_the_sky_full(sdl, point_of_view);
	else
		draw_the_sky_parts(sdl, point_of_view);
}
