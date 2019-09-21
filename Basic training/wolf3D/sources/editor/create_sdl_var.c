/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sdl_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:45:06 by djast             #+#    #+#             */
/*   Updated: 2019/09/17 10:58:18 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

SDL_Color		*create_sdl_color(int r, int g, int b, int a)
{
	SDL_Color *color;

	color = (SDL_Color *)malloc(sizeof(SDL_Color));
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
	return (color);
}

SDL_Rect		*create_sdl_rect(int x, int y, int w, int h)
{
	SDL_Rect *r;

	r = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;
	return (r);
}
