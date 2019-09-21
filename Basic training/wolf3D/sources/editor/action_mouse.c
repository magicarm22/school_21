/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:14:23 by djast             #+#    #+#             */
/*   Updated: 2019/09/21 13:40:28 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"


static int		select_texture(t_sdl *sdl)
{
	if (sdl->windowEvent.button.x > BUTTON_WALL_X &&
		sdl->windowEvent.button.x < BUTTON_WALL_X + BUTTON_SIZE_X &&
		sdl->windowEvent.button.y > BUTTON_WALL_Y &&
		sdl->windowEvent.button.y < BUTTON_WALL_Y + BUTTON_SIZE_Y)
		sdl->button_pushed = WALL_PUSH;
	else if (sdl->windowEvent.button.x > BUTTON_FLOOR_X &&
		sdl->windowEvent.button.x < BUTTON_FLOOR_X + BUTTON_SIZE_X &&
		sdl->windowEvent.button.y > BUTTON_FLOOR_Y &&
		sdl->windowEvent.button.y < BUTTON_FLOOR_Y + BUTTON_SIZE_Y)
		sdl->button_pushed = FLOOR_PUSH;
	else if (sdl->windowEvent.button.x > BUTTON_PLAYER_X &&
		sdl->windowEvent.button.x < BUTTON_PLAYER_X + BUTTON_SIZE_X &&
		sdl->windowEvent.button.y > BUTTON_PLAYER_Y &&
		sdl->windowEvent.button.y < BUTTON_PLAYER_Y + BUTTON_SIZE_Y)
		sdl->button_pushed = PLAYER_PUSH;
	else
		return (0);
	return (1);
}

static int		lower_buttons(t_sdl *sdl)
{
	if (sdl->windowEvent.button.x > BUTTON_SAVE_X &&
		sdl->windowEvent.button.x < BUTTON_SAVE_X + BUTTON_SAVE_SIZE_X &&
		sdl->windowEvent.button.y > BUTTON_SAVE_Y &&
		sdl->windowEvent.button.y < BUTTON_SAVE_Y + BUTTON_SIZE_Y)
		save_map(sdl);
	else if (sdl->windowEvent.button.x > BUTTON_LOAD_X &&
		sdl->windowEvent.button.x < BUTTON_LOAD_X + BUTTON_LOAD_SIZE_X &&
		sdl->windowEvent.button.y > BUTTON_LOAD_Y &&
		sdl->windowEvent.button.y < BUTTON_LOAD_Y + BUTTON_SIZE_Y)
		load_map(sdl);
	else if (sdl->windowEvent.button.x > BUTTON_X &&
		sdl->windowEvent.button.x < BUTTON_X + INPUT_MAP_NAME_SIZE_X &&
		sdl->windowEvent.button.y > INPUT_MAP_NAME_Y &&
		sdl->windowEvent.button.y < INPUT_MAP_NAME_Y + BUTTON_SIZE_Y)
	{
		sdl->input_pushed = 1;
		printf("AAAAA\n");
		SDL_StartTextInput();
	}
	else
	{
		printf("BBB\n");
		sdl->input_pushed = 0;
		SDL_StopTextInput();
		return (0);
	}
	return (1);

}

static void		put_texture(t_sdl *sdl, int *click)
{
	int x;
	int y;

	x = (sdl->windowEvent.button.x - sdl->mesh->x) / sdl->mesh->zoom;
	y = (sdl->windowEvent.button.y - sdl->mesh->y) / sdl->mesh->zoom;
	if (sdl->windowEvent.button.button == SDL_BUTTON_LEFT && *click == 1 && 
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
	if (sdl->windowEvent.type == SDL_MOUSEWHEEL)
	{
		if (sdl->windowEvent.wheel.y > 0)
		{
			if (sdl->mesh->zoom < INT_MAX - 2)
				sdl->mesh->zoom += 2;
		}
		else if (sdl->windowEvent.wheel.y < 0)
		{
			if (sdl->mesh->zoom > 2)
				sdl->mesh->zoom -= 2;
		}
	}
	else if (sdl->windowEvent.type == SDL_MOUSEBUTTONDOWN &&
					sdl->windowEvent.button.button == SDL_BUTTON_LEFT)
	{
		*click = 1;
		if (select_texture(sdl) == 1)
			return ;
		else if (lower_buttons(sdl) == 1)
			return ;
		
	}
	else if (sdl->windowEvent.type == SDL_MOUSEMOTION)
		put_texture(sdl, click);
	else if (sdl->windowEvent.type == SDL_MOUSEBUTTONUP &&
			sdl->windowEvent.button.button == SDL_BUTTON_LEFT)
		*click = 0;
}