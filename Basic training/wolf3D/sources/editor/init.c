/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:21:29 by djast             #+#    #+#             */
/*   Updated: 2019/09/16 13:06:23 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_input_field	*init_input_field(int x, int y, int size_x, int size_y)
{
	t_input_field *field;

	field = (t_input_field *)malloc(sizeof(t_input_field));

	field->x = x;
	field->y = y;
	field->size_x = size_x;
	field->size_y = size_y;
	field->max_text_size = 10;
	field->text = ft_strnew(field->max_text_size);
	field->text_size = 0;
	return (field);
}

void		init_mesh(t_sdl **sdl)
{
	t_mesh *mesh;

	mesh = (t_mesh *)malloc(sizeof(t_mesh));
	mesh->x = MESH_START_X;
	mesh->y = MESH_START_Y;
	mesh->size_x = BASIC_MAP_SIZE_X;
	mesh->size_y = BASIC_MAP_SIZE_Y;
	mesh->zoom = 45;
	mesh->map = NULL;
	(*sdl)->mesh = mesh;
}

void		init_map(t_mesh **mesh)
{
	int i;
	int j;

	i = 0;
	(*mesh)->map = (int **)malloc(sizeof(int *) * (*mesh)->size_y);
	while (i < (*mesh)->size_y)
	{
		(*mesh)->map[i] = (int *)malloc(sizeof(int) * (*mesh)->size_x);
		j = 0;
		while (j < (*mesh)->size_x)
			(*mesh)->map[i][j++] = 0;
		i++;
	}
	i = 0;
	(*mesh)->swaped = (int **)malloc(sizeof(int *) * (*mesh)->size_y);
	while (i < (*mesh)->size_y)
	{
		(*mesh)->swaped[i] = (int *)malloc(sizeof(int) * (*mesh)->size_x);
		j = 0;
		while (j < (*mesh)->size_x)
			(*mesh)->swaped[i][j++] = 0;
		i++;
	}
}

t_sdl 		*init_sdl(void)
{
	t_sdl *sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_VIDEO);
   	sdl->window = SDL_CreateWindow("Editor", SDL_WINDOWPOS_UNDEFINED,
                   SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
                   SDL_WINDOW_OPENGL);
    sdl->renderer =  SDL_CreateRenderer( sdl->window, -1, SDL_RENDERER_ACCELERATED);
    sdl->surface = SDL_LoadBMP("resources/editor/floor.bmp");
	sdl->floor = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
	sdl->surface = SDL_LoadBMP("resources/editor/wall.bmp");
	sdl->wall = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_FreeSurface(sdl->surface);
	return (sdl);
}
