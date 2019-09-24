/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:14:23 by djast             #+#    #+#             */
/*   Updated: 2019/09/24 15:01:19 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int		select_texture(t_sdl *sdl)
{
	if (sdl->window_event.button.x > BUTTON_WALL_X &&
		sdl->window_event.button.x < BUTTON_WALL_X + BUTTON_SIZE_X &&
		sdl->window_event.button.y > BUTTON_WALL_Y &&
		sdl->window_event.button.y < BUTTON_WALL_Y + BUTTON_SIZE_Y)
		sdl->button_pushed = WALL_PUSH;
	else if (sdl->window_event.button.x > BUTTON_FLOOR_X &&
		sdl->window_event.button.x < BUTTON_FLOOR_X + BUTTON_SIZE_X &&
		sdl->window_event.button.y > BUTTON_FLOOR_Y &&
		sdl->window_event.button.y < BUTTON_FLOOR_Y + BUTTON_SIZE_Y)
		sdl->button_pushed = FLOOR_PUSH;
	else if (sdl->window_event.button.x > BUTTON_PLAYER_X &&
		sdl->window_event.button.x < BUTTON_PLAYER_X + BUTTON_SIZE_X &&
		sdl->window_event.button.y > BUTTON_PLAYER_Y &&
		sdl->window_event.button.y < BUTTON_PLAYER_Y + BUTTON_SIZE_Y)
		sdl->button_pushed = PLAYER_PUSH;
	else
		return (0);
	return (1);
}

static int		lower_buttons(t_sdl *sdl)
{
	if (sdl->window_event.button.x > BUTTON_SAVE_X &&
		sdl->window_event.button.x < BUTTON_SAVE_X + BUTTON_SAVE_SIZE_X &&
		sdl->window_event.button.y > BUTTON_SAVE_Y &&
		sdl->window_event.button.y < BUTTON_SAVE_Y + BUTTON_SIZE_Y)
		save_map(sdl);
	else if (sdl->window_event.button.x > BUTTON_LOAD_X &&
		sdl->window_event.button.x < BUTTON_LOAD_X + BUTTON_LOAD_SIZE_X &&
		sdl->window_event.button.y > BUTTON_LOAD_Y &&
		sdl->window_event.button.y < BUTTON_LOAD_Y + BUTTON_SIZE_Y)
		load_map(sdl);
	else if (sdl->window_event.button.x > BUTTON_X &&
		sdl->window_event.button.x < BUTTON_X + INPUT_MAP_NAME_SIZE_X &&
		sdl->window_event.button.y > INPUT_MAP_NAME_Y &&
		sdl->window_event.button.y < INPUT_MAP_NAME_Y + BUTTON_SIZE_Y)
	{
		sdl->input_pushed = 1;
		SDL_StartTextInput();
	}
	else
	{
		sdl->input_pushed = 0;
		SDL_StopTextInput();
		return (0);
	}
	return (1);
}

static int		change_map_size(t_sdl *sdl)
{
	if (sdl->window_event.button.x > BUTTON_UP_X_X &&
		sdl->window_event.button.x < BUTTON_UP_X_X + BUTTON_UP_X_SIZE_X &&
		sdl->window_event.button.y > BUTTON_UP_X_Y &&
		sdl->window_event.button.y < BUTTON_UP_X_Y + BUTTON_UP_X_SIZE_Y)
	{
		if (sdl->mesh->size_x < INT_MAX - 2)
		{
			free_map(sdl->mesh);
			sdl->mesh->size_x += 1;
			init_map(&(sdl->mesh));
		}
		return (1);
	}
	else if (sdl->window_event.button.x > BUTTON_DOWN_X_X &&
		sdl->window_event.button.x < BUTTON_DOWN_X_X + BUTTON_DOWN_X_SIZE_X &&
		sdl->window_event.button.y > BUTTON_DOWN_X_Y &&
		sdl->window_event.button.y < BUTTON_DOWN_X_Y + BUTTON_DOWN_X_SIZE_Y)
	{
		if (sdl->mesh->size_x > 3)
		{
			free_map(sdl->mesh);
			sdl->mesh->size_x -= 1;
			init_map(&(sdl->mesh));
		}
		return (1);
	}
	else if (sdl->window_event.button.x > BUTTON_UP_Y_X &&
		sdl->window_event.button.x < BUTTON_UP_Y_X + BUTTON_UP_Y_SIZE_X &&
		sdl->window_event.button.y > BUTTON_UP_Y_Y &&
		sdl->window_event.button.y < BUTTON_UP_Y_Y + BUTTON_UP_Y_SIZE_Y)
	{
		if (sdl->mesh->size_y < INT_MAX - 2)
		{
			free_map(sdl->mesh);
			sdl->mesh->size_y += 1;
			init_map(&(sdl->mesh));
		}
		return (1);
	}
	else if (sdl->window_event.button.x > BUTTON_DOWN_Y_X &&
		sdl->window_event.button.x < BUTTON_DOWN_Y_X + BUTTON_DOWN_Y_SIZE_X &&
		sdl->window_event.button.y > BUTTON_DOWN_Y_Y &&
		sdl->window_event.button.y < BUTTON_DOWN_Y_Y + BUTTON_DOWN_Y_SIZE_Y)
	{
		if (sdl->mesh->size_y > 3)
		{
			free_map(sdl->mesh);
			sdl->mesh->size_y -= 1;
			init_map(&(sdl->mesh));
		}
		return (1);
	}
	return (0);
}

static void		put_texture(t_sdl *sdl, int *click)
{
	int x;
	int y;

	x = (sdl->window_event.button.x - sdl->mesh->x) / sdl->mesh->zoom;
	y = (sdl->window_event.button.y - sdl->mesh->y) / sdl->mesh->zoom;
	if (sdl->window_event.button.button == SDL_BUTTON_LEFT && *click == 1 &&
		y < sdl->mesh->size_y - 1 && x < sdl->mesh->size_x - 1 &&
		y >= 1 && x >= 1)
	{
		if (sdl->button_pushed == PLAYER_PUSH)
			change_player_position(sdl, x, y);
		if (sdl->mesh->map[y][x] == 2 && sdl->button_pushed != PLAYER_PUSH)
		{
			sdl->player->x = -1;
			sdl->player->y = -1;
		}
		sdl->mesh->map[y][x] = sdl->button_pushed;
	}
}

void			action_mouse(t_sdl *sdl, int *click)
{
	if (sdl->window_event.type == SDL_MOUSEWHEEL)
	{
		if (sdl->window_event.wheel.y > 0)
		{
			if (sdl->mesh->zoom < INT_MAX - 2)
				sdl->mesh->zoom += 2;
		}
		else if (sdl->window_event.wheel.y < 0)
		{
			if (sdl->mesh->zoom > 2)
				sdl->mesh->zoom -= 2;
		}
	}
	else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
	{
		*click = 1;
		if (select_texture(sdl) == 1)
			return ;
		else if (lower_buttons(sdl) == 1)
			return ;
		else if (change_map_size(sdl) == 1)
			return ;
	}
	else if (sdl->window_event.type == SDL_MOUSEMOTION)
		put_texture(sdl, click);
	else if (sdl->window_event.type == SDL_MOUSEBUTTONUP &&
			sdl->window_event.button.button == SDL_BUTTON_LEFT)
		*click = 0;
}
