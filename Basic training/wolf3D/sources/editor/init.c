/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:21:29 by djast             #+#    #+#             */
/*   Updated: 2019/09/22 14:33:16 by djast            ###   ########.fr       */
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
	field->max_text_size = 20;
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
		(*mesh)->map[i][j++] = 1;
		while (j < (*mesh)->size_x - 1)
			(*mesh)->map[i][j++] = 0;
		(*mesh)->map[i][j++] = 1;
		i++;
	}
	j = 1;
	while (j < (*mesh)->size_x - 1)
		(*mesh)->map[0][j++] = 1;
	j = 1;
	while (j < (*mesh)->size_x - 1)
		(*mesh)->map[i - 1][j++] = 1;
}
