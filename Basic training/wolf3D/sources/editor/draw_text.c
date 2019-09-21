/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:39:37 by djast             #+#    #+#             */
/*   Updated: 2019/09/19 17:05:45 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			draw_text(t_sdl *sdl, char *text, SDL_Rect r, SDL_Color color)
{
	sdl->surface = TTF_RenderText_Solid(sdl->font, text, color);
	SDL_DestroyTexture(sdl->text);
	sdl->text = SDL_CreateTextureFromSurface(sdl->renderer,
													sdl->surface);
	SDL_FreeSurface(sdl->surface);
	SDL_RenderCopy(sdl->renderer, sdl->text, NULL, &r);
}

void			draw_result_text(t_sdl *sdl, char *text, int color_result)
{
	SDL_Color *color;
	SDL_Rect *rect;

	if (color_result == COLOR_RESULT_OK)
		color = create_sdl_color(0, 255, 0, 255);
	else if (color_result == COLOR_RESULT_ERROR)
		color = create_sdl_color(255, 0, 0, 255);
	else
		color = create_sdl_color(0, 0, 0, 255);
	rect = create_sdl_rect(BUTTON_X, TEXT_RESULT_Y, INPUT_MAP_NAME_SIZE_X, BUTTON_SIZE_Y);
	draw_text(sdl, text, *rect, *color);
	free(rect);
	free(color);
}