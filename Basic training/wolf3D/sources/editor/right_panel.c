/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:10:26 by djast             #+#    #+#             */
/*   Updated: 2019/09/24 14:53:15 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		draw_buttons_on_right_panel(t_sdl *sdl)
{
	SDL_Rect	*r;

	r = create_sdl_rect(BUTTON_WALL_X, BUTTON_WALL_Y,
			BUTTON_SIZE_X, BUTTON_SIZE_Y);
	if (sdl->button_pushed == WALL_PUSH)
		draw_button(sdl, *r, "WALL", COLOR_PUSHED);
	else
		draw_button(sdl, *r, "WALL", COLOR_UNPUSHED);
	r->x = BUTTON_FLOOR_X;
	if (sdl->button_pushed == FLOOR_PUSH)
		draw_button(sdl, *r, "FLOOR", COLOR_PUSHED);
	else
		draw_button(sdl, *r, "FLOOR", COLOR_UNPUSHED);
	r->x = BUTTON_PLAYER_X;
	if (sdl->button_pushed == PLAYER_PUSH)
		draw_button(sdl, *r, "PLAYER", COLOR_PUSHED);
	else
		draw_button(sdl, *r, "PLAYER", COLOR_UNPUSHED);
	r->x = BUTTON_X;
	r->w = BUTTON_SAVE_SIZE_X;
	r->y = BUTTON_SAVE_Y;
	draw_button(sdl, *r, "SAVE", COLOR_NEUTRAL);
	r->x = BUTTON_LOAD_X;
	draw_button(sdl, *r, "LOAD", COLOR_NEUTRAL);
	free(r);
}

static void		draw_input_fields_on_right_panel(t_sdl *sdl)
{
	SDL_Rect	*r;
	SDL_Color	*color_text;

	r = create_sdl_rect(BUTTON_X, INPUT_MAP_NAME_Y,
			INPUT_MAP_NAME_SIZE_X, BUTTON_SIZE_Y);
	SDL_RenderFillRect(sdl->renderer, r);
	free(r);
	color_text = create_sdl_color(0, 0, 0, 255);
	r = create_sdl_rect(sdl->map_name->x, sdl->map_name->y,
		INPUT_LETTER_SIZE * sdl->map_name->text_size, sdl->map_name->size_y);
	draw_text(sdl, sdl->map_name->text, *r, *color_text);
	free(r);
}

static void		draw_map_size_buttons(t_sdl *sdl)
{
	SDL_Rect	*r;

	r = create_sdl_rect(BUTTON_UP_X_X, BUTTON_UP_X_Y,
						BUTTON_UP_X_SIZE_X, BUTTON_UP_X_SIZE_Y);
	SDL_RenderCopy(sdl->renderer, sdl->arrow_up, NULL, r);
	free(r);
	r = create_sdl_rect(BUTTON_DOWN_X_X, BUTTON_DOWN_X_Y,
						BUTTON_DOWN_X_SIZE_X, BUTTON_DOWN_X_SIZE_Y);
	SDL_RenderCopy(sdl->renderer, sdl->arrow_down, NULL, r);
	free(r);
	r = create_sdl_rect(BUTTON_UP_Y_X, BUTTON_UP_Y_Y,
						BUTTON_UP_Y_SIZE_X, BUTTON_UP_Y_SIZE_Y);
	SDL_RenderCopy(sdl->renderer, sdl->arrow_up, NULL, r);
	free(r);
	r = create_sdl_rect(BUTTON_DOWN_Y_X, BUTTON_DOWN_Y_Y,
						BUTTON_DOWN_Y_SIZE_X, BUTTON_DOWN_Y_SIZE_Y);
	SDL_RenderCopy(sdl->renderer, sdl->arrow_down, NULL, r);
	free(r);
}

static void		draw_map_size_info(t_sdl *sdl)
{
	SDL_Rect	*r;
	SDL_Color	*c;
	char		coords[10];
	char		*coord;

	r = create_sdl_rect(TEXT_MAP_X, TEXT_MAP_Y,
			TEXT_MAP_SIZE_X, TEXT_MAP_SIZE_Y);
	c = create_sdl_color(0, 0, 0, 255);
	draw_text(sdl, "Map size:", *r, *c);
	free(r);
	r = create_sdl_rect(TEXT_X_X, TEXT_X_Y, TEXT_X_SIZE_X, TEXT_X_SIZE_Y);
	ft_strcpy(coords, "X: ");
	coord = ft_itoa(sdl->mesh->size_x);
	ft_strcat(coords, coord);
	free(coord);
	draw_text(sdl, coords, *r, *c);
	free(r);
	r = create_sdl_rect(TEXT_Y_X, TEXT_Y_Y, TEXT_Y_SIZE_X, TEXT_Y_SIZE_Y);
	ft_strcpy(coords, "Y: ");
	coord = ft_itoa(sdl->mesh->size_y);
	ft_strcat(coords, coord);
	free(coord);
	draw_text(sdl, coords, *r, *c);
	free(r);
	free(c);
}

void			draw_right_panel(t_sdl *sdl)
{
	SDL_Rect	r;

	r.x = SIZE_WIN_X * 0.8;
	r.y = 0;
	r.w = SIZE_WIN_X * 0.2;
	r.h = SIZE_WIN_Y;
	SDL_SetRenderDrawColor(sdl->renderer, 128, 128, 128, 255);
	SDL_RenderFillRect(sdl->renderer, &r);
	draw_buttons_on_right_panel(sdl);
	draw_map_size_info(sdl);
	draw_map_size_buttons(sdl);
	draw_input_fields_on_right_panel(sdl);
}
