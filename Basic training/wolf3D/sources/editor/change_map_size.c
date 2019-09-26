/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 10:12:18 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/26 11:09:13 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int		check_size_y(t_sdl *sdl)
{
	if (sdl->window_event.button.x > BUTTON_DOWN_Y_X &&
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
	}
	return (0);
}

static int		check_size_y_int_max(t_sdl *sdl)
{
	if (sdl->window_event.button.x > BUTTON_UP_Y_X &&
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
	}
	return (0);
}

static int		check_size_x(t_sdl *sdl)
{
	if (sdl->window_event.button.x > BUTTON_DOWN_X_X &&
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
	}
	return (0);
}

static int		check_size_x_int_max(t_sdl *sdl)
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
	}
	return (0);
}

int				change_map_size(t_sdl *sdl)
{
	if (check_size_x_int_max(sdl) == 0)
		return (1);
	else if (check_size_x(sdl) == 0)
		return (1);
	if (check_size_y_int_max(sdl) == 0)
		return (1);
	else if (check_size_y(sdl) == 0)
		return (1);
	return (0);
}
