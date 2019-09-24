/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_sky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:40:01 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/24 11:43:38 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf3d.h"

void	draw_the_sky(t_SDL *sdl, int point_of_view)
{
	SDL_Rect	sky_background_l;
	SDL_Rect	sky_l;
	SDL_Rect	sky_background_r;
	SDL_Rect	sky_r;
	double		coef;

	if (point_of_view >= 30 && point_of_view <= 330)
	{
		sky_background_l.x = 0;
		sky_background_l.y = 0;
		sky_background_l.w = SIZE_WIN_X;
		sky_background_l.h = SIZE_WIN_Y / 2;

		// sky_l.x = (point_of_view - 30) * (8192 / 360);
		// sky_l.y = 0;
		// sky_l.w = (8192 / 360) * 60;// * RESOL_RATIO_X;
		// sky_l.h = 4096 / 2;

		sky_l.x = 8192 - (point_of_view - 30) * (8192 / 360);
		sky_l.y = 0;
		sky_l.w = (8192 / 360) * 60;// * RESOL_RATIO_X;
		sky_l.h = 4096;// / 2;
		SDL_RenderCopy(sdl->renderer, sdl->texture_sky, &sky_l, &sky_background_l);
	}
	else
	{
		if (point_of_view >= 330)
			point_of_view = point_of_view - 360;
		// if (point_of_view <= 30)
		// 	point_of_view = point_of_view + 360;
		// sky_l.x = 8192 + (point_of_view - 30) * (8192 / 360);
		// sky_l.y = 0;
		// sky_l.w = (-(point_of_view - 30) * (8192 / 360));// * RESOL_RATIO_X;
		// sky_l.h = 4096 / 2;
		// sky_r.x = 0;
		// sky_r.y = 0;
		// sky_r.w = ((8192 / 360) * 60 + (point_of_view - 30) * (8192 / 360));// * RESOL_RATIO_X;
		// sky_r.h = 4096 / 2;
		sky_l.x = 8192 - (point_of_view + 30) * (8192 / 360);
		sky_l.y = 0;
		sky_l.w = (point_of_view + 30) * (8192 / 360);// * RESOL_RATIO_X;
		sky_l.h = 4096;// / 2;
		sky_r.x = 0;
		sky_r.y = 0;
		sky_r.w = (60 - (point_of_view + 30)) * (8192 / 360);// * RESOL_RATIO_X;
		sky_r.h = 4096;// / 2;
		coef = (double)sky_l.w / ((double)sky_l.w + (double)sky_r.w);
		printf("coef = %f\n", coef);
		printf("point = %d\n", point_of_view);

		// sky_l.w и sky_r.w - коэф 50 и 150 = 1 и 3 итого 4 части
		// sky_background_l.w / sky_background_r.w - должна = коэф

		// SIZE_WIN_X - единица
		// SIZE_WIN_X * коэф (1/4) - наша левая часть

		sky_background_l.x = 0;
		sky_background_l.y = 0;
		sky_background_l.w = SIZE_WIN_X * coef;
		sky_background_l.h = SIZE_WIN_Y / 2;
		sky_background_r.x = SIZE_WIN_X * coef;
		sky_background_r.y = 0;
		sky_background_r.w = SIZE_WIN_X * (1 - coef);
		sky_background_r.h = SIZE_WIN_Y / 2;

		SDL_RenderCopy(sdl->renderer, sdl->texture_sky, &sky_l, &sky_background_l);
		SDL_RenderCopy(sdl->renderer, sdl->texture_sky, &sky_r, &sky_background_r);
	}
}
